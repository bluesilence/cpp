class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int totalBits = sizeof(int) / sizeof(char) * 8;
        
        for (int i = 0; i < totalBits; i++) {
            result <<= 1;
            result |= n & 0x01;
            n >>= 1;
        }
        
        return result;
    }
};
