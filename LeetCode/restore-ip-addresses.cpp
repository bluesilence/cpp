class Solution {
//1. terminate case should satisfy all the conditions
//2. cut off should at least cover the out of range case
//3. move should satisfy all the necessary conditions
public:
    vector<string> restoreIpAddresses(string s) {
        vector<int> curPath;    //Store the start and end index of a number
        vector<string> allPath;
        restoreCore(s, 0, curPath, allPath);
        
        return allPath;
    }

private:
    void restoreCore(string& s, int curIdx, vector<int>& curPath, vector<string>& allPath) {
        if(curPath.size() == 4 && curIdx == s.size()) {
            string tmp = s;
            for(int i = curPath.size() - 2; i >= 0; i--)    //For all the numbers except the last one
                tmp.insert(curPath[i] + 1, 1, '.'); //insert '.' at index curPath[i] + 1
                
            allPath.push_back(tmp);
            return;
        }
        
        if(curPath.size() >= 4 || curIdx >= s.size())
            return;
        
        int curNum = s[curIdx] - '0';
        int end = curIdx;
        do {
            curPath.push_back(end);
            end++;
            restoreCore(s, end, curPath, allPath);
            curPath.pop_back();
            curNum = curNum * 10 + s[end] - '0';
        } while (end < s.size() && curNum <= 255 && s[curIdx] != '0');//The first digit can be 0, but there should be no number after 0
    }
};
