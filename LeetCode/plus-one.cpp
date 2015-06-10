class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.empty())
            return digits;
            
        reverse(digits.begin(), digits.end());
        const int n = digits.size();
        
        digits[0]++;
        
        int carry = 0;
        for (int i = 0; i < n; i++) {
            digits[i] += carry;
            carry = digits[i] / 10;
            digits[i] -= carry * 10;
        }
        
        if (carry > 0) {
            digits.push_back(carry);
        }
        
        reverse(digits.begin(), digits.end());
        
        return digits;
    }
};
