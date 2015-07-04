class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int LEN1 = version1.size();
        const int LEN2 = version2.size();
        
        int index1 = 0;
        int index2 = 0;
        
        int num1 = 0;
        int num2 = 0;
        
        do {
            num1 = getNextLevel(version1, index1);
            num2 = getNextLevel(version2, index2);
            
            if (num1 != num2) {
                return num1 > num2 ? 1 : -1;
            }
        } while (index1 <= LEN1 || index2 <= LEN2);
        
        return 0;
    }

private:
    //If the substring is like "..", return 0 as the current level of version
    int getNextLevel(string s, int &begin) {
        if (begin >= s.size())
            return 0;
        
        int result = 0;
        
        while (begin < s.size() && s[begin] != '.') {
            result *= 10;
            result += s[begin++] - '0';
        }
        
        begin++;
        
        return result;
    }
};
