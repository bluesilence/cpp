class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }

		isTerminalWord = false;
    }
    
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != NULL)
                delete children[i];
        }
    }
    
    void insert(string &s, int index) {
        if (index < 0 || index >= s.size())
            return;
            
        int cIndex = s[index] - 'a';
        if (!children[cIndex]) {
            children[cIndex] = new TrieNode();
		}

		  if (index + 1 < s.size()) {
			  children[cIndex]->insert(s, ++index);
		  } else { //The entire string has been inserted
			  children[cIndex]->isTerminalWord = true;
		  }
    }

    bool search(string &s, int index) {
        if (index < 0 || index >= s.size())
            return false;
            
        int cIndex = s[index] - 'a';
        if (!children[cIndex]) {
            return false;
        } else {
            if (index == s.size() - 1) {    //Last character in s
                return children[cIndex]->isLeaf();
            } else {
                return children[cIndex]->search(s, ++index);
            }
        }
    }
    
    bool startsWith(string &s, int index) {
        if (index < 0 || index > s.size())
            return false;
        
		    if (s.empty())
			    return true;

        int cIndex = s[index] - 'a';
        if (!children[cIndex]) {
            return false;
        } else {
            if (index == s.size() - 1) {
                return true;
            } else {
                return children[cIndex]->startsWith(s, ++index);
            }
        }
    }
    
    bool isLeaf() {
        return isTerminalWord;
    }
    
private:
    TrieNode *children[26];
	bool isTerminalWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        delete root;
    }
    
    // Inserts a word into the trie.
    void insert(string s) {
        if (search(s))  //s already exists in trie
            return;
        
        root->insert(s, 0);
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        if (!root)
            return false;
        
        if (key.empty())
            return true;
            
        return root->search(key, 0);
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if (!root)
            return false;
        
        if (prefix.empty())
            return true;
        
        return root->startsWith(prefix, 0);
    }

private:
    TrieNode* root;
};
