class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2 || k < 1)
            return;
        
        const int N = nums.size();
        int cleanK = k % N;

        if (cleanK == 0)
            return;
        
        reverse(nums, 0, N - cleanK - 1);
        reverse(nums, N - cleanK, N - 1);
        reverse(nums, 0, N - 1);
    }

private:
    void reverse(vector<int>& nums, int begin, int end) {
        if (begin < 0 || end >= nums.size() || begin >= end)
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
