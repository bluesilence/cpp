class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;
        if (words.empty())
            return results;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() > maxWidth)    //No valid justification solution
                return results;
        }
        
        vector<vector<string>> wordsPerLine;
        vector<int> lengthPerLine;
        
        int lineCount = 1;
        //Collect words as many as possible in each line until the total length of (words + spaces) > L
        int i = 0;
		while (i < words.size()) {
            if (wordsPerLine.size() < lineCount) {
                vector<string> newLine;
                wordsPerLine.push_back(newLine);
                lengthPerLine.push_back(0);
            }
            
            if (lengthPerLine[lineCount-1] + words[i].size() <= maxWidth) {   //Collect word to existing line
                wordsPerLine[lineCount-1].push_back(words[i]);
                lengthPerLine[lineCount-1] += words[i].size() + 1; //1 for the space after the word
				i++;
            } else {    //Prepare a new line
                lineCount++;
            }
        }
        
        //Calculate extra spaces: E = L - (total length of words per line) - (necessary spaces between words per line)
        //Divide extra spaces: let each words pick one space at a time until all extra spaces runs out
        for (int i = 0; i < lineCount; i++) {
            string line = "";
            int extraSpaces = maxWidth - (lengthPerLine[i] - 1);
            //Allocate extra spaces
            allocateExtraSpaces(wordsPerLine[i], extraSpaces, i == (lineCount-1));
            
            //Allocate necessary spaces
            for (int j = 0; j < wordsPerLine[i].size(); j++) {
                line += wordsPerLine[i][j];
                if (j < wordsPerLine[i].size() - 1) //Not last word
                    line += " ";
            }
            
            results.push_back(line);
        }
        
        return results;
    }

private:
    void allocateExtraSpaces(vector<string> &words, int extraSpaces, bool isLastLine) {
        if (isLastLine || words.size() == 1) {   //In the last line, extra spaces must be put after the last word
            words[words.size()-1] += string(extraSpaces, ' ');
        } else {
            int extraSpacesPerWord = extraSpaces / (words.size() - 1);  //No extra space for the last word
            if (extraSpacesPerWord > 0) {
                for (int j = 0; j + 1 < words.size(); j++) {
                    words[j] += string(extraSpacesPerWord, ' ');
                }
            }
            
            extraSpaces -= extraSpacesPerWord * (words.size() - 1);
            
            //Allocate remaining spaces
            for (int j = 0; j + 1 < words.size(); j++) {
                if (extraSpaces == 0)
                    break;
                    
                words[j] += " ";
                extraSpaces--;
            }
        }
    }
};
