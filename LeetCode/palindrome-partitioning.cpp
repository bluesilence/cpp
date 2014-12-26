class Solution {
public:
    vector<vector<string>> partition(string s) {
        //Use recursion to generate all combinations of palindrome
        vector<vector<string>> results;
        if (s.empty())
            return results;
        
        vector<string> combination;
        partitionCore(s, results, combination, 0);
        
        return results;
    }

private:
    void partitionCore(string s, vector<vector<string>> &results, vector<string> &combination, int n) {
        if (n >= s.size()) {
            results.push_back(combination);
            return;
        }
        
		for (int j = n; j < s.size(); j++) {
			if (isPalindrome(s, n, j)) {
				string p = s.substr(n, j - n + 1);
				combination.push_back(p);
				partitionCore(s, results, combination, j + 1);
				combination.pop_back();
			}
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        if (s.empty() || start > end || start < 0)
            return false;
        
        while (start < end) {
            if (s[start++] != s[end--])
                return false;
        }
        
        return true;
    }
};
