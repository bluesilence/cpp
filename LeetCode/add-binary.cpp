class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
            return b;
        
        if (b.empty())
            return a;
        
        reverse(a);
        reverse(b);
        
        const int aLen = a.size();
        const int bLen = b.size();
        bool carry = false;
        
        const int LEN = max(aLen, bLen);
        
        string result(LEN, '0');
        
        for (int i = 0; i < aLen; i++) {
            result[i] = a[i];
        }
        
        for (int i = 0; i < LEN; i++) {
            if (i < bLen)
                result[i] = addDigit(result[i], b[i], carry);
            else
                result[i] = addDigit(result[i], '0', carry);
        }
        
        //Add 1 highest digit
        if (carry)
            result.push_back('1');
            
        reverse(result);
        
        return result;
    }

private:
    char addDigit(char c1, char c2, bool &carry) {
        char ch;
        
        if (c1 == '0' && c2 == '0') {
            ch = carry ? '1' : '0';
            carry = false;
        } else if (c1 == '0' && c2 == '1' || c1 == '1' && c2 == '0') {
            //carry won't change if current sum is 1
            ch = carry ? '0' : '1';
        } else {
            ch = carry ? '1' : '0';
            carry = true;
        }
        
        return ch;
    }
    
    void reverse(string &s) {
        int i = 0;
        int j = s.size() - 1;
        char tmp;
        while (i < j) {
            tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
};
