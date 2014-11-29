class Solution {
public:
    //羅馬數字共有7個，即I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
    int romanToInt(string s) {
        map<char, int> dict;
        dict['I'] = 1;
        dict['V'] = 5;
        dict['X'] = 10;
        dict['L'] = 50;
        dict['C'] = 100;
        dict['D'] = 500;
        dict['M'] = 1000;
        
        int result = 0;
        for (int i = 0; i + 1 < s.size(); i++) {
            if (dict[s[i]] >= dict[s[i+1]])
                result += dict[s[i]];
            else
                result -= dict[s[i]];
        }
        
        //The last digit must be added, not subtracted
        result += dict[s[s.size()-1]];
        
        return result;
    }
};
