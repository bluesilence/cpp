class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict[10] = { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        
        vector<string> results;
        if (!digits.empty()) {
            string result;
            combinationCore(results, result, dict, digits, 0);
        }
        
        return results;
    }

private:
    void combinationCore(vector<string> &results, string &result, string *dict, string digits, int index) {
        if (index == digits.size()) {
            results.push_back(result);
        } else {
            string letters = dict[digits[index] - '0'];
            for (int i = 0; i < letters.size(); i++) {
                result.push_back(letters[i]);
                combinationCore(results, result, dict, digits, index + 1);
                result.pop_back();
            }
        }
    }
};
