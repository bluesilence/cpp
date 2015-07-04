class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorNum = nums[0];
        
        const int N = nums.size();
        for (int i = 1; i < N; i++) {
            xorNum ^= nums[i];
        }
        
        return xorNum;
    }
};
