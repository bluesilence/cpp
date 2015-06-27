struct TrieNode {
    TrieNode *children[26];
    bool isKey;
    
    TrieNode() {
		for (int i = 0; i < 26; i++) {
			children[i] = NULL;
		}

        isKey = false;
    }
    
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    void addWord(string word) {
        int index;
        
        TrieNode *p = this;
        const int len = word.size();
        
        for (int i = 0; i < len; i++) {
            index = word[i] - 'a';
        
            if (!p->children[index]) {
                p->children[index] = new TrieNode();
            }
                
            if (i == word.size() - 1) {
                p->children[index]->isKey = true;
            } else {
                p = p->children[index];
            }
        }
    }
    
    bool search(string word, int start) {
        if (word.size() == start)
            return isKey;
        
        int index = 26;
        if (word[start] != '.') {
            index = word[start] - 'a';
            
            if (children[index] == NULL)
                return false;
            else
                return children[index]->search(word, start + 1);
        } else {    //'.' can match any of the 26 alphabets
            for (int i = 0; i < 26; i++) {
                if (children[i] == NULL)
                    continue;
                
                if (children[i]->search(word, start + 1))
                    return true;
            }
            
            return false;
        }
    }
};

class WordDictionary {
public:
	WordDictionary() {
		root = NULL;
	}

    // Adds a word into the data structure.
    void addWord(string word) {
        if (!root) {
            root = new TrieNode();
        }
        
        root->addWord(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (!root) {
            return false;
        }
        
        return root->search(word, 0);
    }

    ~WordDictionary() {
        if (root) {
            delete root;
        }
    }
    
private:
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
