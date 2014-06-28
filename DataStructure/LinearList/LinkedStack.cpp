#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node(T value) {
	data = value;
	next = NULL;
    }
};

template <class T>
class LinkedStack {
    public:
	LinkedStack<T>() {
	    cout<<"Constructing stack..."<<endl;
	    top = NULL;
	}

	~LinkedStack<T>() {
	    cout<<"Destructing stack..."<<endl;
	    Node<T>* tmp = NULL;
	    while( top ) {
		tmp = top->next;
		cout<<"Deleting "<<top->data<<endl;
		delete top;
		top = tmp;
	    }
	}

	void push(T data) {
	    Node<T>* tmp = new Node<T>(data);
	    tmp->next = top;
	    top = tmp;
	    cout<<"Push "<<data<<endl;
	}

	T pop() {
	    if( !top )
		throw "Underflow";
	    Node<T>* tmp = top->next;
	    T result = top->data;
	    delete top;
	    top = tmp;
	    cout<<"Pop "<<result<<endl;
	    return result;
	}

	T peek() {
	    if( !top )
		throw "Underflow";
	    return top->data;
	}

	bool isEmpty() {
	    return top == NULL;
	}

    private:
	Node<T>* top;
};

int main() {
    LinkedStack<int> stack;
    cout<<"Stack is empty? "<<stack.isEmpty()<<endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout<<"Top: "<<stack.peek()<<endl;
    stack.pop();
    stack.pop();
    stack.push(5);
    cout<<"Top: "<<stack.peek()<<endl;
    cout<<"Stack is empty? "<<stack.isEmpty()<<endl;
}

