class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        
        const int N = s.size();
        vector<bool> canFormPair(N - 1, false);
        stack<int> leftParenIndexStack;
        
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                leftParenIndexStack.push(i);
            } else {
                if (!leftParenIndexStack.empty()) {
                    canFormPair[i] = true;
                    canFormPair[leftParenIndexStack.top()] = true;
                    leftParenIndexStack.pop();
                }
            }
        }
        
        int localMax = 0;
        int globalMax = 0;
        
        for (int i = 0; i <= N; i++) {
            if (i < N && canFormPair[i]) {
                localMax++;
                continue;
            }
            
            globalMax = max(globalMax, localMax);
            
            localMax = 0;   //Start next continuous valid parentheses substring
        }
        
        return globalMax;
    }
};
