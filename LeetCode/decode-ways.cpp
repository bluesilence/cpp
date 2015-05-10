class Solution {
public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        
        const int size = s.size();
        //DP. Use an array ways[s.size()+1], ways[i] indicate how many ways to decode at s[i-1]
        //This is to reduce duplicate code so that the loop can start from s[1] with ways[i-2]
        //Special case: '0' can only be decoded with the digit prior to it
        //ways[0] = 1
        //if s[0] != '0', ways[1] = 1, else return 0
        //if s[1] != '0', ways[2] = int(s[0...1]) <= 26 ? ways[0] + ways[1] : ways[1]
        //Else, ways[1] = int(s[0...1]) <= 26 ? ways[0] : return 0
        //So that ways[s.size()-1] is the total ways of decodings for s.
        vector<int> ways(size+1, 0);
        
        if (s[0] != '0') {
            ways[0] = 1;
            ways[1] = 1;
        } else {
            return 0;   //Invalid string at s[0]
        }
        
        for (int i = 1; i < size; i++) {
            if (s[i] != '0') {
                ways[i+1] = ways[i];   //Decode as single digit
                if (isValidTens(s[i-1], s[i])) {
                    ways[i+1] += ways[i-1]; //Decode as double digits
                }
            } else {
                if (isValidTens(s[i-1], s[i])) {
                    ways[i+1] = ways[i-1];  //Can only be decoded as double digits
                } else {
                    return 0;   //Invalid string at s[i]
                }
            }
        }
        
        return ways[size];
    }

private:
    bool isValidTens(char tenDigit, char oneDigit) {
        if (tenDigit > '2' || tenDigit == '0' || tenDigit == '2' && oneDigit > '6')
            return false;
        
        return true;
    }
};
