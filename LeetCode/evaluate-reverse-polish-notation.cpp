class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        long long result = 0;
        
        stack<long long> s;
        
        const int N = tokens.size();
        
        for (int i = 0; i < N; i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                if (s.size() < 2)
                    throw "Invalid expression";
                
                //The later num is on the top of stack due to FILO
                long long num2 = s.top();
                s.pop();
                long long num1 = s.top();
                s.pop();
                
                long long tmp = 0;
                if (tokens[i] == "+") {
                    tmp = num1 + num2;
                } else if (tokens[i] == "-") {
                    tmp = num1 - num2;
                } else if (tokens[i] == "*") {
                    tmp = num1 * num2;
                } else {
                    tmp = num1 / num2;
                }
                
                s.push(tmp);    //Push result back as the operand for next operator
            } else {
                s.push(atol(tokens[i]));
            }
        }
        
        if (!s.empty())
            result = s.top();
        
        if (result > INT_MAX)
            return INT_MAX;
        else if (result < INT_MIN)
            return INT_MIN;
        else
            return result;
    }

private:
    long long atol(string token) {
        long long num = 0;
        
        const int LEN = token.size();
        int sign = 1;
        
        if (token[0] == '-')
            sign = -1;
            
        for (int i = 0; i < LEN; i++) {
            if (token[i] <= '9' && token[i] >= '0') {   //Omitted verification of validity here
                num *= 10;
                num += token[i] - '0';
            }
        }
        
        return sign * num;
    }
};
