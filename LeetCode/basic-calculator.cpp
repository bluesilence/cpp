class Solution {
public:
    int calculate(string s) {
        if (s.empty())
            return 0;
        
        s = "+(" + s + ")";
        
        long long result = 0;
        long long additiveNum = 0;
        
        int currentSign = 1;    //Default sign
        stack<int> signs;
        signs.push(1);  //Default sign
        
        char op;
        
        //Skip ' ' during the loop
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '+' || ch == '-') {
                //sign of a number is determined by direct sign and the sign before its '('
                //If additiveNum is already added within ')' if-branch, it will be set to 0 and no affect to result here
                additiveNum *= signs.top() * currentSign; //Caution: INT_MIN * (-1) will overflow. Use long long here.
                result += additiveNum;
                additiveNum = 0;
                
                currentSign = ch == '-' ? -1 : 1;
            } else if (ch == '(' || ch == ')') {
                if (ch == '(') {
                    signs.push(signs.top() * currentSign);    //The sign before '('
                    currentSign = 1;    //Initialize for the substring within ()
                } else {
                    additiveNum *= signs.top() * currentSign; //Caution: INT_MIN * (-1) will overflow. Use long long here.
                    result += additiveNum;
                    additiveNum = 0;
                    signs.pop();
                }
            } else if (ch >= '0' && ch <= '9') {
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
};
