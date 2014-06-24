#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prior;

    Node() {
	next = NULL;
	prior = NULL;
    }

    Node(T element) : Node() {
	data = element;
    }
};

template <class T>
class DoublyLinkedList {
    public:
	DoublyLinkedList();
	DoublyLinkedList(T a[], int n);
	~DoublyLinkedList();
	void insert(T element, int pos);
	void insert(T element, Node<T>* prior);
	T remove(int pos);
	T remove(Node<T>* p);
	T get(int pos);
	int locate(T target);
	int getLength();
	bool contains(Node<T>* p);
	bool hasNext(Node<T>* p);
	Node<T>* getHead();
	Node<T>* getRear();
	void printList();

    private:
	Node<T>* head;
	Node<T>* rear;

	Node<T>* nodeBefore(int pos) {
	    Node<T> *p = head;
	    for(int i = 0; i < pos; i++) {
		p = p->next;
	    }

	    return p;
	}
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = new Node<T>;
    rear = head;
    head->next = rear;
    head->prior = rear;
}

template <class T>
DoublyLinkedList<T>::DoublyLinkedList(T a[], int n) : DoublyLinkedList<T>() {
    if( !a || n < 0 )
	throw "Invalid array parameter";

    //Insert from head
    for(int i = 0; i < n; i++) {
	Node<T>* tmp = new Node<T>(a[i]);
	tmp->next = head->next;
	head->next->prior = tmp;
	tmp->prior = head;
	head->next = tmp;

	if( rear == head ) { //first node inserted
	    rear = tmp;
	}
    }

    head->prior = rear;
    rear->next = head;
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T> *p = head, *q;
    while(p != rear) {
	q = p->next;
	delete p;
	p = q;
    }

    delete rear;
    head = rear = 0;
}

template <class T>
void DoublyLinkedList<T>::insert(T data, int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength())
	throw "Invalid position: " + pos;
    Node<T> *p = nodeBefore(pos);
    Node<T> *tmp = new Node<T>(data);
    tmp->next = p->next;
    p->next->prior = tmp;
    tmp->prior = p;
    p->next = tmp;
}

template <class T>
void DoublyLinkedList<T>::insert(T data, Node<T>* prior) { //insert after node prior
    if( contains(prior) ) {
	Node<T> *tmp = new Node<T>(data);

	tmp->next = prior->next;
	prior->next->prior = tmp;
	tmp->prior = prior;
	prior->next = tmp;

	if( prior == rear ) { //rear needs to change
	    rear = tmp;
	}
    }
}

template <class T>
T DoublyLinkedList<T>::remove(int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength() - 1)
	throw "Invalid position: " + pos;
    Node<T> *p = nodeBefore(pos); //node before tmp
    Node<T> *tmp = p->next; //node to be deleted
    p->next = tmp->next; //node after tmp
    tmp->next->prior = p;
    T element = tmp->data;
    
    if( rear == tmp ) { //rear needs to be changed
	rear = p;
    }

    delete tmp;
    return element;
}

template <class T>
T DoublyLinkedList<T>::remove(Node<T>* p) { //remove node p. Header node cannot be removed.
    if( contains(p) ) {
	T elem = p->data;
	Node<T>* prior = p->prior;
	Node<T>* next = p->next;
	prior->next = next;
	next->prior = prior;
    
	if( rear == p ) { //rear needs to be changed
	    rear = prior;
	}

	delete p;
	return elem;
    } else {
	throw "node doesn't exist";
    }
}

template <class T>
T DoublyLinkedList<T>::get(int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength() - 1)
	throw "Invalid position: " + pos;
    Node<T> *p = head;
    for(int i = 0; i < pos; i++) {
	p = p->next;
    }

    return p->next->data;
}

template <class T>
int DoublyLinkedList<T>::locate(T target) {
    int len = getLength();
    Node<T> *p = head->next;
    for(int i = 0; i < len; i++) {
	if(target == p->data)
	    return i;
	p = p->next;
    }

    return -1;
}

template <class T>
int DoublyLinkedList<T>::getLength() {
    int len = 0;
    Node<T> *p = head->next;
    while( head != p ) {
	len++;
	p = p->next;
    }

    return len;
}

template <class T>
bool DoublyLinkedList<T>::contains(Node<T>* p) {
    Node<T>* cursor = head->next;
    while( cursor && head != cursor ) {
	if( cursor == p ) {
	    return true;
	}

	cursor = cursor->next;
    }

    return false;
}

template <class T>
bool DoublyLinkedList<T>::hasNext(Node<T>* p) {
    return contains(p) && !(rear == p);
}

template <class T>
Node<T>* DoublyLinkedList<T>::getHead() {
    return head;
}

template <class T>
Node<T>* DoublyLinkedList<T>::getRear() {
    return rear;
}

template <class T>
void DoublyLinkedList<T>::printList() {
    Node<T> *p = head->next;
    while( head != p ) {
	cout<<p->data<<" ";
	p = p->next;
    }

    cout<<endl;
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    DoublyLinkedList<int> list(array, sizeof(array) / sizeof(array[0]));
    cout<<"Initialize list with array {1,2,3,4,5}: "<<endl;
    list.printList();
    cout<<"Insert into list with 6 at position 1: "<<endl;
    list.insert(6, 1);
    list.printList();
    cout<<"Remove element at position 3 from list: "<<endl;
    list.remove(3);
    list.printList();
    cout<<"Get element at position 3 from list: "<<endl;
    cout<<list.get(3)<<endl;
    cout<<"Locate position of element 5: "<<endl;
    cout<<list.locate(5)<<endl;
    cout<<"Length of list: "<<endl;
    cout<<list.getLength()<<endl;
    cout<<"Insert into list with 7 after the second node: "<<endl;
    list.insert(7, list.getHead()->next->next);
    list.printList();
    cout<<"Remove the last node from list: "<<endl;
    list.remove(list.getRear());
    list.printList();
    cout<<"Length of list: "<<endl;
    cout<<list.getLength()<<endl;
}
