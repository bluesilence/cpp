class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        
        if (N < 1)
            throw "Array size must be >= 1";
        
        int majority = nums[0];
        int count = 1;
        
        for (int i = 1; i < N; i++) {
            if (majority != nums[i]) {
                if (!count) {
                    majority = nums[i];
                    count = 1;
                } else {
                    count--;
                }
            } else {
                count++;
            }
        }
        
        return majority;
    }
};
