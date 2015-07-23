class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        
        int count = 1;
        int major = nums[0];
        
        for (int i = 1; i < N; i++) {
            if (nums[i] == major) {
                count++;
            } else {
                if (count > 0) {
                    count--;
                } else {
                    major = nums[i];
                    count = 1;
                }
            }
        }
        
        return major;
    }
};
