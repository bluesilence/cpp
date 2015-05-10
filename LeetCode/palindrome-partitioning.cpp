class Solution {
public:
    vector<vector<string>> partition(string s) {
        //DFS. Check if s[i...j] is palindrome. If so, collect substring s(i, j) and recursively check from s[j+1]
        //When reaching the end of s, collect this set of substrings
        vector<vector<string>> results;
        if (s.empty())
            return results;
        
        vector<string> result;
        partitionCore(results, result, s, 0);
        
        return results;
    }

private:
    void partitionCore(vector<vector<string>> &results, vector<string> &result, string &s, int begin) {
        for (int end = begin; end < s.size(); end++) {
            if (isPalindrome(s, begin, end)) {
                result.push_back(s.substr(begin, end - begin + 1));
                if (end + 1 < s.size()) {
                    partitionCore(results, result, s, end + 1);
                } else {
                    results.push_back(result);
                }
                    
                result.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int begin, int end) {
        if (begin < 0 || end >= s.size())
            throw "Invalid index of s";
            
        while (begin < end) {
            if (s[begin++] != s[end--])
                return false;
        }
        
        return true;
    }
};
