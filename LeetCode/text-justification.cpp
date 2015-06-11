class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> results;
        
        if (words.empty())
            return results;
        
        for (int i = 0; i < words.size(); i++) {
            if (words[i].size() > maxWidth)  //No possible justification
                return results;
        }
        
        vector<vector<string> > lines;
        
        int wordCnt = 0;
        while (wordCnt < words.size()) {
            int lineWidth = 0;
            
            vector<string> line;
            while(wordCnt < words.size() && lineWidth + words[wordCnt].size() <= maxWidth) {   //the word to the maxWidth in a line doesn't require space
                line.push_back(words[wordCnt]);
                lineWidth += words[wordCnt].size();
                if (lineWidth < maxWidth)   //Add 1 space between words
                    lineWidth++;
                    
                wordCnt++;
            }
            
            lines.push_back(line);
        }
        
        for (int i = 0; i < lines.size(); i++) {
            int wordsPerLine = lines[i].size();
            
            int wordsLen = 0;
            for (int j = 0; j < wordsPerLine; j++) {
                wordsLen += lines[i][j].size();
            }
            
            int spaces = maxWidth - wordsLen;
            if (i < lines.size() - 1) {
                if (wordsPerLine == 1) {
                    lines[i][0] += string(spaces, ' ');
                } else {
                    int extraSpacesPerWord = spaces / (wordsPerLine - 1);
                    int remainingSpaces = spaces - extraSpacesPerWord * (wordsPerLine - 1);
            
                    for (int j = 0; j + 1 < wordsPerLine; j++) {    //No extra space after the last word in a line
                        lines[i][j] += string(extraSpacesPerWord, ' ');
                    }
            
                    //Assign remaining spaces to the left words in a line
                    for (int j = 0; j < remainingSpaces; j++) {
                        lines[i][j] += " ";
                    }
                }
            } else {    //Last line, all the extra spaces should be left after the last word
                for (int j = 0; j + 1 < wordsPerLine; j++) {    //No extra space after the last word in a line
                    lines[i][j] += " ";
                }
                
                lines[i][wordsPerLine-1] += string(spaces - (wordsPerLine - 1), ' ');
            }
            
            string justifiedLine = "";
            for (int j = 0; j < wordsPerLine; j++) {
                justifiedLine += lines[i][j];
            }
            
            results.push_back(justifiedLine);
        }
        
        return results;
    }
};
