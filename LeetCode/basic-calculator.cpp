class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        
        s = trim(s);
        s = "+(" + s + ")";
        
        long long result = 0;
        long long additiveNum = 0;
        
        int currentSign = 1;    //Default sign
        //Store the absolute sign for each level of "()" block.
        stack<int> signs;
        signs.push(1);  //Default sign
        
        char op;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '+' || ch == '-') {
                if (i > 0 && s[i-1] >= '0' && s[i-1] <= '9') {
                    //sign of a number is determined by direct sign and the sign before its '('
                    additiveNum *= signs.top() * currentSign; //Caution: INT_MIN * (-1) will overflow. Use long long here.
                    result += additiveNum;
                    additiveNum = 0;
                }
                
                currentSign = ch == '-' ? -1 : 1;
            } else if (ch == '(' || ch == ')') {
                if (ch == '(') {
                    signs.push(signs.top() * currentSign);    //The sign for this "()" block is determined by the last sign at this level * the sign before '('
                    currentSign = 1;    //Initialize for the substring within ()
                } else {
                    additiveNum *= signs.top() * currentSign; //Caution: INT_MIN * (-1) will overflow. Use long long here.
                    result += additiveNum;
                    additiveNum = 0;
                    signs.pop();
                }
            } else {
                additiveNum *= 10;
                additiveNum += ch - '0';
            }
        }
        
        //Catch last number
        result += additiveNum;
        
        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        } else {
            return (int)result;
        }
    }

private:
    string trim(string &s) {
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                result.push_back(s[i]);
            }
        }
        
        return result;
    }
};
