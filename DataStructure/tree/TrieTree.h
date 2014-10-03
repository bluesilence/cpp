#include <iostream>
#include <memory.h>
using namespace std;

// For lower-case only + '\0'
const unsigned int MAX_WIDTH = 26 + 1;
const unsigned int MAX_LENGTH = 100;

struct TrieNode {
    char data;
    TrieNode* next[MAX_WIDTH];

    TrieNode() {
	memset(next, 0x00, sizeof(TrieNode*) * MAX_WIDTH);
    }	

    TrieNode(char ch) {
	data = ch;
	TrieNode();
    }

    ~TrieNode() {
	for(int i = 0; i < MAX_WIDTH; i++) {
	    if(next[i] != NULL) {
		delete next[i];
	    }
	}
    }

    bool find(char* word) {
	if(!word) {
	    throw "NullPointerException: word";
	}

	char ch = *word;

	if('\0' == ch && next[MAX_LENGTH-1] != NULL) { //Match till leaf node
	    return true;
	}

	bool found = false;
	for(int i = 0; i < MAX_WIDTH; i++) {
	    //Already had the node, continue for the next char
	    if(next[i] != NULL && next[i]->data == ch) {
		found = next[i]->find(word + 1);

		if(found)
		    return true;
	    }
	}

	return false;
    }

    bool insert(char* word) {
	if(NULL == word) {
	    cout<<"Null pointer: word"<<endl;
	    return false;
	}

	if('\0' == *word) { //Insert terminal
	    next[MAX_LENGTH-1] = new TrieNode('\0');
	    return true;
	}

	char ch = *word;
	int index = ch == '\0' ? (MAX_WIDTH - 1) : (ch - 'a');
	if(!find(word)) { //The char doesn't exist in next[], create new node
	    if(index < 0 || index > 26) {
		cout<<"Invalid index"<<endl;
		return false;
	    }
	    
	    if(next[index] == NULL) {
		next[index] = new TrieNode(ch);
		if(ch == '\0') //Inserted till the end of string
		    return true;
	    }
	}

	//The new created node has empty next[], so no need to check existence
	return next[index]->insert(++word);
    }

    void print(char* printBuff, int pos) {
	if(pos < 0) {
	    throw "Invalid position: pos";
	}

	//Push current character
	printBuff[pos++] = data;

	bool isLeaf = true;
	for(int i = 0; i < MAX_WIDTH; i++) {
	    if(next[i] != NULL && next[i]->data != '\0') {
		isLeaf = false;
		next[i]->print(printBuff, pos);
	    }
	}
	
	if(isLeaf) {
	    //Print without next character
	    printBuff[pos] = '\0';
	    cout<<printBuff<<endl;
	}

	//Pop current character
	pos--;
    }
};

class TrieTree {
    public:
	TrieTree() {
	    root = new TrieNode();
	    memset(printBuff, '\0', sizeof(char) * MAX_LENGTH);
	}

	~TrieTree() {
	    cout<<"Deleting root..."<<endl;
	    delete root;
	}

	void print() {
	    cout<<"Print tree..."<<endl;
	    //root node doesn't have data. Start from first children nodes.
	    for(int i = 0; i < MAX_WIDTH; i++) {
		if(root->next[i] != NULL) {
		    root->next[i]->print(printBuff, 0);
		}
	    }

	    cout<<"Print tree ends."<<endl;
	}

	//root node doesn't contain real data, start finding from next nodes
	bool find(char* word) {
	    return root->find(word);
	}

	bool insert(char* word) {
	    return root->insert(word);
	}

    private:
	TrieNode* root;
	char printBuff[MAX_LENGTH];
};
