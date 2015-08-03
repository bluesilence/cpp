class MonoQueue {
    public:
        void push(int val) {
            int count = 0;
            
            while (!deq.empty() && deq.back().first < val) {
                count += deq.back().second + 1;
                deq.pop_back();
            }
            
            deq.emplace_back(val, count);
        }
        
        int max() {
            return deq.front().first;
        }
        
        void pop() {
            if (deq.front().second > 0) {
                deq.front().second--;
            } else {
                deq.pop_front();
            }
        }
        
    private:
        //pair.first: the actual value
        //pair.second: how many numbers have been deleted between current number and the number before it to keep monotony.
        deque<pair<int, int>> deq;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> results;
        if (nums.empty() || k < 1)
            return results;
            
        MonoQueue monoQueue;
        
        const int N = nums.size();
        k = min(k, N);
        
        for (int i = 0; i < k - 1; i++) {
            monoQueue.push(nums[i]);
        }
        
        for (int i = k; i <= N; i++) {
            monoQueue.push(nums[i-1]);
            results.push_back(monoQueue.max());
            monoQueue.pop();
        }
        
        return results;
    }
};
