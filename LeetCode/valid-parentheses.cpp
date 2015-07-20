class Solution {
public:
    bool isValid(string s) {
        //Use 1 stack to track latest parentheses
        if (s.empty())
            return true;
        
        stack<char> parenStack;
        
        const int N = s.size();
        
        for (int i = 0; i < N; i++) {
            switch (s[i]) {
                case '(': {
                    parenStack.push('(');
                    break;
                }
                
                case '{': {
                    parenStack.push('{');
                    break;
                }
                
                case '[': {
                    parenStack.push('[');
                    break;
                }
                
                case ')': {
                    if (!parenStack.empty() && parenStack.top() == '(') {
                        parenStack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
                
                case '}': {
                    if (!parenStack.empty() && parenStack.top() == '{') {
                        parenStack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
                
                case ']': {
                    if (!parenStack.empty() && parenStack.top() == '[') {
                        parenStack.pop();
                        break;
                    } else {
                        return false;
                    }
                }
            }
        }
        
        return parenStack.empty();
    }
};
