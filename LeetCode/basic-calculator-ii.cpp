class Solution {
public:
    Solution() {
        opDict['+'] = 0;
        opDict['-'] = 1;
        opDict['*'] = 2;
        opDict['/'] = 3;
    }
    
    int calculate(string s) {
        string trimmed = trim(s);
        
        if (trimmed.empty()) {
            return 0;
        }
        
        return calculateCore(trimmed, 0, trimmed.size() - 1);
    }
    
private:
    map<char, int> opDict;
    
    int calculateCore(string &s, int begin, int end) {
        if (end < begin) {
            return 0;
        }
        
        vector<int> firstOccurrence(4, -1);
        
        for (int i = begin; i <= end; i++) {
            char ch = s[i];
            if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                firstOccurrence[opDict[ch]] = i;
            }
        }
        
        for (int i = 0; i < 4; i++) {
            int firstPos = firstOccurrence[i];
            if (firstPos > -1) {
                int leftResult = calculateCore(s, begin, firstPos - 1);
                int rightResult = calculateCore(s, firstPos + 1, end);
                
                for (auto iter = opDict.begin(); iter != opDict.end(); iter++) {
                    if (iter->second == i) {
                        return directCalculate(iter->first, leftResult, rightResult);
                    }
                }
            }
        }
        
        //No operator found, just convert string to number
        return atoi(s, begin, end);
    }

private:
    string trim(string s) {
        string result = "";
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                result += s[i];
            }
        }
        
        return result;
    }
    
    int directCalculate(char op, int leftResult, int rightResult) {
        double left = leftResult;
        double right = rightResult;
        
        double result = 0;
        switch (op) {
            case '+': {
                result = left + right;
                break;
            }
            
            case '-': {
                result = left - right;
                break;
            }
            
            case '*': {
                result = left * right;
                break;
            }
            
            case '/': {
                if (right == 0) {
                    throw "DivideByZeroException";
                }
                
                result = left / right;
                break;
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
    
    int atoi(string s, int begin, int end) {
        if (begin < 0 || end >= s.size() || begin > end) {
            return 0;
        }
        
        long long result = 0;
        
        for (int i = begin; i <= end; i++) {
            result *= 10;
            result += s[i] - '0';
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
