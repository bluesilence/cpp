class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> results;
        combine(digits, results, "", 0);
        
        return results;
    }
    
    Solution() {
        mappings['0'] = " ";
        mappings['1'] = "";
        mappings['2'] = "abc";
        mappings['3'] = "def";
        mappings['4'] = "ghi";
        mappings['5'] = "jkl";
        mappings['6'] = "mno";
        mappings['7'] = "pqrs";
        mappings['8'] = "tuv";
        mappings['9'] = "wxyz";
    }

private:
    map<char, string> mappings;
    
    void combine(const string &digits, vector<string> &results, string result, int i) {
        if (i >= digits.size()) {
            results.push_back(result);
            return;
        }
        
        string characters = mappings[digits[i]];
        for (int j = 0; j < characters.size(); j++) {
            combine(digits, results, result + characters[j], i + 1);
        }
    }
};
