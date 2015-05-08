class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> results;
        if (n <= 0)
            return results;
        
        generateParenthesisCore(results, "", n, n);
    
        return results;
    }

private:
    void generateParenthesisCore(vector<string> &results, string result, int leftCount, int rightCount) {
        if (leftCount == 0 && rightCount == 0) {
            results.push_back(result);
        } else {
            if (leftCount > 0) {
                generateParenthesisCore(results, result + '(', leftCount - 1, rightCount);
            }
            
            if (rightCount > leftCount) {
                generateParenthesisCore(results, result + ')', leftCount, rightCount - 1);
            }
        }
    }
};
