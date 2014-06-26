#include <iostream>
using namespace std;

template <class T>
class BothSeqStack {
    public:
	BothSeqStack() {
	    top1 = -1;
	    top2 = MAX_SIZE;
	    array = new T[MAX_SIZE];
	}

	~BothSeqStack() {
	    top1 = -1;
	    top2 = MAX_SIZE;
	    delete array;
	}

	void push(int stack, T data) {
	    verifyStack(stack);
	    cout<<"Push "<<data<<" into stack "<<stack<<endl;
	    if( top1 + 1 >= top2 )
		throw "Overflow";
	    else if(1 == stack) {
		array[++top1] = data;
	    } else {
		array[--top2] = data;
	    }
	}

	T pop(int stack) {
	    verifyStack(stack);
	    cout<<"Pop stack "<<stack<<endl;
	    if(1 == stack) {
		if(-1 == top1)
		    throw "Stack 1 underflow";
		else return array[top1--];
	    } else {
		if(MAX_SIZE == top2)
		    throw "Stack 2 underflow";
		else return array[top2++];
	    }
	}

	T top(int stack) {
	    verifyStack(stack);
	    if(1 == stack) {
		if(-1 == top1)
		    throw "Stack 1 underflow";
		else return array[top1];
	    } else {
		if(MAX_SIZE == top2)
		    throw "Stack 2 underflow";
		else return array[top2];
	    }
	}

	bool isEmpty(int stack) {
	    verifyStack(stack);
	    if(1 == stack)
		return -1 == top1;
	    else return MAX_SIZE == top2;
	}

	void printStack() {
	    cout<<"Stack 1:"<<endl;
	    for(int i = 0; i <= top1; i++) {
		cout<<array[i]<<' ';
	    }

	    cout<<endl;

	    cout<<"Stack 2:"<<endl;
	    for(int i = MAX_SIZE-1; i >= top2; i--) {
		cout<<array[i]<<' ';
	    }

	    cout<<endl;
	}

    private:
	const unsigned int MAX_SIZE = 100;
	int top1;
	int top2;
	T* array;

	void verifyStack(int stack) {
	    if( stack != 1 && stack != 2 )
		throw "Unsupported stack: " + stack;
	}
};

int main() {
    BothSeqStack<int> stack;
    cout<<"Stack 1 is empty? "<<stack.isEmpty(1)<<endl;
    cout<<"Stack 2 is empty? "<<stack.isEmpty(2)<<endl;
    stack.push(1, 1);
    stack.push(1, 2);
    stack.push(1, 3);
    stack.push(1, 4);
    stack.push(2, 9);
    stack.push(2, 8);
    stack.push(2, 7);
    stack.push(2, 6);
    cout<<"Stack 1 is empty? "<<stack.isEmpty(1)<<endl;
    cout<<"Stack 2 is empty? "<<stack.isEmpty(2)<<endl;
    stack.printStack();
    stack.pop(1);
    stack.pop(2);
    stack.pop(2);
    stack.printStack();
    stack.pop(1);
    cout<<"Top of stack 1: "<<stack.top(1)<<endl;
    stack.pop(2);
    cout<<"Top of stack 2: "<<stack.top(2)<<endl;
    stack.printStack();
}

