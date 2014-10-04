#include <iostream>
#include <memory.h>
using namespace std;

// Switch of test mode
/*
#ifndef _DEBUG
#define _DEBUG
#endif
*/
// For all the chars
const unsigned int MAX_WIDTH = 256;
const unsigned int MAX_LENGTH = 100;

struct TrieNode {
    char data;
    TrieNode* next[MAX_WIDTH];

    TrieNode() {
	memset(next, 0x00, sizeof(TrieNode*) * MAX_WIDTH);
    }	

    TrieNode(char ch) {
	#ifdef _DEBUG
	cout<<"Construct TrieNode of max width: "<<MAX_WIDTH<<endl;
	#endif

	data = ch;
	TrieNode();
    }

    ~TrieNode() {
	for(int i = 0; i < MAX_WIDTH; i++) {
	    if(next[i] != NULL) {
		#ifdef _DEBUG
		cout<<"Destructing TrieNode: "<<next[i]->data<<endl;
		#endif

		delete next[i];
	    }
	}
    }

    bool find(char* word) {
	if(!word) {
	    throw "NullPointerException: word";
	}

	char ch = *word;

	#ifdef _DEBUG
	cout<<"ch: "<<ch<<", data: "<<data<<endl;
	#endif

	bool found = false;
	int index = ch;
	//Already had the node, continue for the next char
	if(next[index] != NULL) {
	    if(ch == '\0') //next character is terminal
		found = true;
	    else found = next[index]->find(word + 1);

	    if(found)
		return true;
	}

	return false;
    }

    bool insert(char* word) {
	if(NULL == word) {
	    cout<<"Null pointer: word"<<endl;
	    return false;
	}

	char ch = *word;
	int index = ch;
	if(next[index] == NULL) {
	    next[index] = new TrieNode(ch);
	    if(ch == '\0') { //Inserted till the end of string
		#ifdef _DEBUG
		cout<<"Inserted terminal."<<endl;
		#endif

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
	    #ifdef _DEBUG
	    cout<<"Construct TrieTree of max length: "<<MAX_LENGTH<<endl;
	    #endif

	    root = new TrieNode();
	    memset(printBuff, '\0', sizeof(char) * MAX_LENGTH);
	}

	~TrieTree() {
	    #ifdef _DEBUG
	    cout<<"Deleting root..."<<endl;
	    #endif

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
