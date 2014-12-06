class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        if (digits.size() < 1)
            return digits;
            
        //1 extra digit for carry from the most significant digit
        vector<int> result(digits.size() + 1, 0);
        
        for (int i = 1; i < result.size(); i++)
            result[i] = digits[i-1];
        
        int carry = 1;
        for (int i = result.size() - 1; i >= 0; i--) {
            result[i] += carry;
            if (result[i] > 9) {
                carry = result[i] - 9;
                result[i] = result[i] % 10;
            } else {
                carry = 0;
            }
        }
        
        if (result[0] > 0) {
            return result;
        } else {
            //Remove the 0 at the most significant digit
            for (int i = 1; i < result.size(); i++)
                digits[i-1] = result[i];
                
            return digits;
        }
    }
};
