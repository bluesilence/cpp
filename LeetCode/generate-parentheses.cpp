class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //Right parentheses must appear after left parentheses
        vector<string> results;
        string result = "";
        generate(n, n, result, results);
        
        return results;
    }

private:
    //leftNum: number of remaining left parenthesis
    //rightNum: number of remaining right parenthesis
    void generate(int leftNum, int rightNum, string result, vector<string> &results) {
        if (leftNum == 0 && rightNum == 0) {
            results.push_back(result);
        }
        
        if (leftNum > 0) {
            generate(leftNum - 1, rightNum, result + '(', results);
        }
        
        if (rightNum > 0 && leftNum < rightNum) {
            generate(leftNum, rightNum - 1, result + ')', results);
        }
    }
};
