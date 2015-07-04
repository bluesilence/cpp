class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Another solution from Discuss
        const int N = nums.size();
        
        int ones = 0, twos = 0;
        
        for(int i = 0; i < N; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
    
        return ones;
    }
};
