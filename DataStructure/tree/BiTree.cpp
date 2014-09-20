#include <iostream>
#include <fstream>
#include <string>
#include "BiNode.h"
using namespace std;

template<class T>
class BiTree {
    public:
	//Construct from keyboard
	BiTree(unsigned int maxSize, T terminator) {
	    size = maxSize;
	    term = terminator;
	    Construct();
	}

	//Deserialize from file
	BiTree(unsigned int maxSize, T terminator, char* filename) {
	    size = maxSize;
	    term = terminator;

	    if(!filename || *filename == '\0')
	    {
		throw "Filename is NULL or empty!";
	    }
	    
	    ifstream in(filename);
	    if(!in.is_open())
	    {
		throw "Error opening file.";
	    }

	    char buffer[size];
	    in.getline(buffer, size);
	    cout<<"Read in buffer..."<<endl;
	    cout<<buffer<<endl;

	    Construct(buffer);
	}

	//pre-order traverse
	void PreOrder() {
	    cout<<"Pre-order traverse:"<<endl;
	    PreOrder(root);
	    cout<<endl;
	}

	~BiTree() {
	    Release(root);
	}


    private:
	BiNode<T>* root;
	T term;	//Stands for null node
	unsigned int size;

	void Construct() {
	    Construct(&root);
	}

	void Construct(BiNode<T>** root) {
	    T node;
	    cout<<"Please input node: ";
	    cin>>node;
	    if( node != term ) {
		*root = new BiNode<T>(node);
		cout<<"Construct lChild for node "<<node<<"..."<<endl;
		Construct(&(*root)->lChild);
		cout<<"Construct rChild for node "<<node<<"..."<<endl;
		Construct(&(*root)->rChild);
	    }
	}

	//str is the sequence of pre-order traverse
	void Construct(char* str) {
	    if(!str) {
		throw "NullPointerException";
	    }

	    Construct(&root, &str);
	}

	void PreOrder(BiNode<T>* root) {
	    if(!root) {
		cout<<term<<' ';
		return;
	    } else {
		root->print();
	    }

	    PreOrder(root->lChild);
	    PreOrder(root->rChild);
	}

	void Construct(BiNode<T>** root, char** str) {
	    T node = (T) **str;
	    *str += 1;
	    if( node != term) {
		*root = new BiNode<T>(node);
		cout<<"Construct lChild for node "<<node<<"..."<<endl;
		Construct(&(*root)->lChild, str);
		cout<<"Construct rChild for node "<<node<<"..."<<endl;
		Construct(&(*root)->rChild, str);
	    }
	}

	void Release(BiNode<T>* root) {
	    if(!root)
		return;

	    if(root->lChild)
		Release(root->lChild);
	    if(root->rChild)
		Release(root->rChild);
	    
	    delete root;
	}
};

int main() {
    BiTree<char> charTree(100, '#');
    charTree.PreOrder();

    BiTree<char> fileTree(100, '#', "tree.txt");
    fileTree.PreOrder();
}
