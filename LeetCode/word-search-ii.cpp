struct Trie {
    Trie *children[26];
    bool isKey;
    
    Trie () {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        
        isKey = false;
    }
    
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i] != NULL) {
                delete children[i];
            }
        }
    }
    
    bool search(string s) {
        const int LEN = s.size();
        Trie *p = this;
        int i = 0;
        
        for (; i < LEN; i++) {
            int index = s[i] - 'a';
            if (p->children[index] != NULL) {
                p = children[index];
            } else {
                break;
            }
        }
        
        if (i == LEN && p->isKey == true) {
            return true;
        }
        
        return false;
    }
    
    void add(string s, int start = 0) {
        if (start >= s.size())
            return;
        
        int index = s[start] - 'a';
        if (children[index] == NULL) {
            children[index] = new Trie();
        }
        
        if (start == s.size() - 1) { //Reached the end of s
            children[index]->isKey = true;
        } else {
            children[index]->add(s, start + 1);
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //Build a trie from the dictionary
        Trie *root = new Trie();
        buildDict(root, words);
        
        const int M = board.size();
        const int N = board[0].size();
        
        vector<vector<bool>> visited(M, vector<bool>(N, false));
        vector<string> results;
        string result;
        
        //For every character in the board, use it as the starting point for BFS
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                result.clear();
                for (int k = 0; k < M; k++) {   //Reset visited matrix
                    fill(visited[k].begin(), visited[k].end(), false);
                }
                
                DFS(results, result, root, visited, board, i, j);
            }
        }
        
        return results;
    }

private:
    void DFS(vector<string> &results, string &result, Trie *root, vector<vector<bool>> &visited, vector<vector<char>> &board, int i, int j) {
        char ch = board[i][j];
        int index = ch - 'a';
        
        visited[i][j] = true;
        
        //If current character ch is found in root's children, set root = children[ch - 'a']
        if (root->children[index] != NULL) {
            result.push_back(ch);
            
            if (root->children[index]->isKey) {  //Found a word
                results.push_back(result);  //Collect word
                root->children[index]->isKey = false;    //Avoid duplicate words
            }
        
            //Update pointer to its child
            root = root->children[index];
            
            if ((i > 0) && !visited[i-1][j]) {    //Search UP
                DFS(results, result, root, visited, board, i - 1, j);
            }
            
            if ((i < board.size() - 1) && !visited[i+1][j]) {    //Search DOWN
                DFS(results, result, root, visited, board, i + 1, j);
            }
            
            if ((j > 0) && !visited[i][j-1]) {    //Search LEFT
                DFS(results, result, root, visited, board, i, j - 1);
            }
            
            if ((j < board[0].size() - 1) && !visited[i][j+1]) {    //Search RIGHT
                DFS(results, result, root, visited, board, i, j + 1);
            }
            
            result.pop_back();
        }

		    visited[i][j] = false;
    }
    
    void buildDict(Trie *root, vector<string> &words) {
        if (!root)
            return;
        
        const int LEN = words.size();
        for (int i = 0; i < LEN; i++) {
            root->add(words[i]);
        }
    }
};
