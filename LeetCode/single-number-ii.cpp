class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Count how many 1s each bit has after summing up the whole array
        //count % 3 is the bit contributed by the exceptional number
        const int BITS_LEN = 8 * sizeof(int);
        vector<int> bitCounts(BITS_LEN, 0);
        const int N = nums.size();
        
        int result = 0;
        
        for (int i = 0; i < BITS_LEN; i++) {
            for (int j = 0; j < N; j++) {
                bitCounts[i] += (nums[j] >> i) & 1;
            }
            
            result |= (bitCounts[i] % 3) << i;
        }
        
        return result;
    }
};
