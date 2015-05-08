class Solution {
public:
    //羅馬數字共有7個，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
    int romanToInt(string s) {
        int result = 0;
        
        int pre = getInt(s[0]);
        int curr;
        
        result += pre;
        
        //There could only be 1 smaller digit at the left of the larger digit
        //So just compare current and previous digit
        for (int i = 1; i < s.size(); i++) {
            curr = getInt(s[i]);
            if (pre >= curr)
                result += curr;
            else
                result = result - 2 * pre + curr;
            
            pre = curr;
        }
        
        return result;
    }

private:
    int getInt(char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
    }
};
