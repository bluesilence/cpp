class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        const int N = nums.size();
        if (N < 2)
            return;
        
        int moves = k % N;
        if (moves == 0)
            return;
        
        reverse(nums, N - 1 - moves + 1, N - 1);
        reverse(nums, 0, N - moves - 1);
        reverse(nums, 0, N - 1);
    }
    
private:
    void reverse(vector<int>& nums, int begin, int end) {
        if (begin < 0 || end >= nums.size())
            return;
        
        while (begin < end) {
            int tmp = nums[begin];
            nums[begin] = nums[end];
            nums[end] = tmp;
            begin++;
            end--;
        }
    }
};
