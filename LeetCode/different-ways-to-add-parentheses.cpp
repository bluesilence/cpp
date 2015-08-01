class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        
        return computeDiffResults(input, dpMap);
    }

private:
    vector<int> computeDiffResults(string& input, unordered_map<string, vector<int>>& dpMap) {
        vector<int> results;
        
        const int LEN = input.size();
        
        vector<int> leftResults;
        vector<int> rightResults;
        
        for (int i = 0; i < LEN; i++) {
            char curr = input[i];
            
            if (curr == '+' || curr == '-' || curr == '*') {
                string leftOperand = input.substr(0, i);
                if (dpMap.find(leftOperand) != dpMap.end()) {
                    leftResults = dpMap[leftOperand];
                } else {
                    leftResults = computeDiffResults(leftOperand, dpMap);
                }
                
                string rightOperand = input.substr(i+1);
                if (dpMap.find(rightOperand) != dpMap.end()) {
                    rightResults = dpMap[rightOperand];
                } else {
                    rightResults = computeDiffResults(rightOperand, dpMap);
                }
                
                for (auto leftResult : leftResults) {
                    for (auto rightResult : rightResults) {
                        switch (curr) {
                            case '+':
                                results.push_back(leftResult + rightResult);
                                break;
                            case '-':
                                results.push_back(leftResult - rightResult);
                                break;
                            case '*':
                                results.push_back(leftResult * rightResult);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }   
        }
        
        //No operator, only 1 number
        if (results.empty()) {
            results.push_back(atoi(input.c_str()));
        }
                
        dpMap[input] = results;
        
        return results;
    }
};
