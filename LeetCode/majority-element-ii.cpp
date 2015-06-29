class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        return majorityKElement(nums, 3);
    }
    
    vector<int> majorityKElement(vector<int> &nums, const int K) {
        vector<int> results;
        
        const int N = nums.size();
        
        if (N == 0) {
            return results;
        }
        
        //For majorities that appear more than ⌊ N/K ⌋ times, there are at most (K - 1) majorities among N numbers
        vector<int> majorities(K - 1, 0);
        vector<int> majorityCounts(K - 1, 0);
        
        for (int i = 0; i < N; i++) {
            int j = 0;
            for (; j < K - 1; j++) {
                if (nums[i] == majorities[j]) {
                    majorityCounts[j]++;
                    break;
                } else if (majorityCounts[j] == 0) {
                    majorities[j] = nums[i];
                    majorityCounts[j] = 1;
                    break;
                }
            }
            
            if (j == K - 1) { //No previous majority which equals to nums[i] && no vacancy in the majority seats
                for (j = 0; j < K - 1; j++) {
                    majorityCounts[j]--;
                }
            }
        }
        
        const int threshold = N / K;
        fill(majorityCounts.begin(), majorityCounts.end(), 0);
        
        //Scan numbers again to make sure the top (K-1) frequent numbers actually appeared more than ⌊ N/K ⌋ times
        for (int i = 0; i < K - 1; i++) {
            bool hasDup = false;
            int major = majorities[i];
            
            for (int j = 0; j < results.size(); j++) {
                if (results[j] == major) {
                    hasDup = true;
                }
            }
            
            if (!hasDup) {
                for (int j = 0; j < N; j++) {
                    if (nums[j] == major) {
                        majorityCounts[i]++;
                    
                        if (majorityCounts[i] > threshold) {
                            results.push_back(major);
                            break;  //Make sure one majority is added only once
                        }
                    }
                }
            }
        }
        
        return results;
    }
};
