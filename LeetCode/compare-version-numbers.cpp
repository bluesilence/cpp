class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1, v2;
        int index1 = 0, index2 = 0;
        v1 = getNextLevel(version1, index1);
        v2 = getNextLevel(version2, index2);
        while (index1 < version1.size() || index2 < version2.size()) {
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
            else {
                v1 = getNextLevel(version1, index1);
                v2 = getNextLevel(version2, index2);
            }
        }
        
        //Last digit of the longer one of version 1 and 2
        if (v1 == v2)
            return 0;
        else if (v1 > v2)
            return 1;
        else
            return -1;
    }

private:
    int getNextLevel(string version, int &index) {
        if (index >= version.size() || version[index] == '.')
            return 0;
        
        int result = 0;
        while (index < version.size() && version[index] != '.') {
            result = result * 10 + version[index] - '0';
            index++;
        }
        
        if (index < version.size())
            //skip '.' and point to next level's version
            index++;
        
        return result;
    }
};
