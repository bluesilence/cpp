class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end || dict.empty())
            return 0;
        
        unordered_set<string> currentLayer;
        unordered_set<string> nextLayer;
        unordered_set<string> unvisited = dict;
        
        currentLayer.insert(start);
        unvisited.insert(end);
        
        int length = 1;
        int minLength = INT_MAX;
        
        while (currentLayer.find(end) == currentLayer.end() && !unvisited.empty()) {
            minLength = min(minLength, length);
            
            for (auto iter = currentLayer.begin(); iter != currentLayer.end(); iter++) {
                string word = *iter;
                
                for (int j = 0; j < word.size(); j++) {
                    char originalChar = word[j];
                    for (int k = 0; k < 26; k++) {
                        char ch = 'a' + k;
                        if (ch == originalChar) {
                            continue;
                        }
                        
                        word[j] = ch;
                        
                        if (unvisited.find(word) != unvisited.end()) {
                            nextLayer.insert(word);
                            unvisited.erase(word);
                        }
                    }
                    
                    word[j] = originalChar;
                }
            }
            
            if (nextLayer.empty()) {
                break;
            }
            
            currentLayer = nextLayer;
            nextLayer.clear();
            
            length++;
        }
        
        if (currentLayer.find(end) != currentLayer.end())
            return length;
        else
            return 0;
    }
};
