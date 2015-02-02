class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        //Use stack to store each token.
        //Whenever the top is an operand, calculate the expression with the top 3 tokens, then push result into the stack.
        stack<int> cache;

        for(int i = 0 ; i < tokens.size(); i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                int num2 = cache.top();
                cache.pop();
                int num1 = cache.top();
                cache.pop();
                cache.push(calculate(num1, num2, tokens[i]));
            } else {
                cache.push(strToInt(tokens[i]));
            }
        }

        return cache.top();
    }
    
private:
    int strToInt(string str) {
        bool positive = true;
        int start = 0;
        if(str[start] == '-') {
            positive = false;
            start++;
        } else if(str[start]=='+') {
            start++;
        } 
        
        int result = 0;
        while(start < str.size()) {
            result *= 10;
            result += (str[start] - '0');
            start++;
        };
        
        if(!positive)
            result *= -1;
        
        return result;
    }
    
    string intToStr(int v) {
        bool positive = true;
        if(v < 0) {
            positive = false;
            v *= -1;
        }
        
        string str;
        while(v > 0) {
            str.push_back(v % 10 + '0');
            v/=10;
        }
        
        if(str.size() == 0)
            str.push_back('0');
        if(!positive)
            str.push_back('-');
        
        for(int i = 0;i < str.size()/2; i++) {
            char c = str[i];
            str[i] = str[str.size() - 1 - i];
            str[str.size() - 1 - i] = c;
        }
        
        return str;
    }
    
    int calculate(int num1, int num2, string operation) {
        int result = 0;
        if(operation == "+")  {
             result = num1 + num2;
        } else if(operation == "-") {
            result = num1 - num2;
        } else if(operation == "*") {
            result = num1 * num2;
        } else {
            result = num1 / num2;
        }
        
        return result;
    }
    
    bool isInteger(string s) {
        if(s == "+" || s == "-" || s == "*" || s == "/")
            return false;
        else
    	    return true;
    }
};
