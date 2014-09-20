#include <iostream>
using namespace std;

template<class T>
struct BiNode {
    T data;
    BiNode* lChild;
    BiNode* rChild;

    BiNode() {
	lChild = rChild = NULL;
    }

    BiNode(T element) {
	cout<<"Construct new node: "<<element<<endl;
	data = element;
	lChild = rChild = NULL;
    }

    void print() {
	cout<<data<<' ';
    }
};
