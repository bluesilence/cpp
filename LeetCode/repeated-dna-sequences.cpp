class Solution {
public:
    Solution () {
        memset(hashTable, false, sizeof(hashTable));
        
        convert[0] = 0; //'A' - 'A' => 00
        convert[2] = 1; //'C' - 'A' => 01
        convert[6] = 2; //'G' - 'A' => 10
        convert[19] = 3; //'T' - 'A' => 11
    }
    
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> results;
        if (s.size() < 10)
            return results;
            
        //Store the converted value of the first 10 chars of s
        int hashValue = 0;
        for (int i = 0; i < 10; i++) {
            hashValue <<= 2;
            hashValue |= convert[s[i] - 'A'];
        }
        
        hashTable[hashValue] = true;
        
        unordered_set<int> repeatedSequences;
        
        for (int i = 10; i < s.size(); i++) {
            hashValue <<= 2;
            hashValue |= convert[s[i] - 'A'];
            hashValue &= ~0x300000; //Preserve last 20 bits (2 bit per char)
            
            if (hashTable[hashValue]) {
                if (repeatedSequences.find(hashValue) == repeatedSequences.end()) {
                    results.push_back(s.substr(i - 9, 10));
                    repeatedSequences.insert(hashValue);
                }
            } else {
                hashTable[hashValue] = true;
            }
        }
        
        return results;
    }

private:
    //A/C/G/T is converted to 2 bits, so for 10-letter-long sequence, the total bits are 20, the total combination number is 2^20
    bool hashTable[1024 * 1024];
    
    unsigned char convert[26];
};
