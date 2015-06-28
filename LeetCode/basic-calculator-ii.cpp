class Solution {
public:
    int calculate(string s) {
        //Trick: integrating the first/last number into the while loop.
        s = '+' + s + '+';
        istringstream iss(s);
        
        long long result = 0;
        long long additiveNum = 0;
        int productNum = 0;
        
        char op;
        
        while (iss >> op) {
            if (op == '+' || op == '-') {
                result += additiveNum;
                iss>>additiveNum;
                
                //subtracting a number equals to adding the number's negative
                additiveNum *= op == '-' ? -1 : 1; //Caution: INT_MIN * (-1) will overflow. Use long long here.
            } else {    //Need to compute * and / before adding to the result
                iss>>productNum;
                
                if (op == '*') {
                    additiveNum *= productNum;
                } else {
                    additiveNum /= productNum;
                }
            }
        }
        
        if (result > INT_MAX) {
            return INT_MAX;
        } else if (result < INT_MIN) {
            return INT_MIN;
        } else {
            return (int)result;
        }
    }
};
