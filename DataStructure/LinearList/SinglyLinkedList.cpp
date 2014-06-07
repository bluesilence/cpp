#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node() {
	next = NULL;
    }

    Node(T element) {
	data = element;
	next = NULL;
    }
};

template <class T>
class SinglyLinkedList {
    public:
	SinglyLinkedList();
	SinglyLinkedList(T a[], int n);
	~SinglyLinkedList();
	void insert(T element, int pos);
	T remove(int pos);
	T get(int pos);
	int locate(T element);
	int getLength();
	void printList();

    private:
	Node<T>* nodeBefore(int pos) {
	    Node<T> *p = head;
	    for(int i = 0; i < pos; i++) {
		p = p->next;
	    }

	    return p;
	}

	Node<T>* head;
};

template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    head = new Node<T>;
    head->next = NULL;
}

template <class T>
SinglyLinkedList<T>::SinglyLinkedList(T a[], int n) {
    head = new Node<T>;
    head->next = NULL;

    //Insert from head
    for(int i = 0; i < n; i++) {
	Node<T>* tmp = new Node<T>(a[i]);
	tmp->next = head->next;
	head->next = tmp;
    }
}

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T> *p = head, *q = p;
    while(p) {
	q = p;
	p = p->next;
	delete q;
    }
}

template <class T>
void SinglyLinkedList<T>::insert(T element, int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength())
	throw "Invalid position: " + pos;
    Node<T> *p = nodeBefore(pos);
    Node<T> *tmp = new Node<T>(element);
    tmp->next = p->next;
    p->next = tmp;
}

template <class T>
T SinglyLinkedList<T>::remove(int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength() - 1)
	throw "Invalid position: " + pos;
    Node<T> *p = nodeBefore(pos);
    Node<T> *tmp = p->next;
    p->next = tmp->next;
    T element = tmp->data;
    delete tmp;
    return element;
}

template <class T>
T SinglyLinkedList<T>::get(int pos) {	//pos starts from 0
    if( pos < 0 || pos > getLength() - 1)
	throw "Invalid position: " + pos;
    Node<T> *p = head;
    for(int i = 0; i < pos; i++) {
	p = p->next;
    }

    return p->next->data;
}

template <class T>
int SinglyLinkedList<T>::locate(T element) {
    int len = getLength();
    Node<T> *p = head->next;
    for(int i = 0; i < len; i++) {
	if(element == p->data)
	    return i;
	p = p->next;
    }

    return -1;
}

template <class T>
int SinglyLinkedList<T>::getLength() {
    int len = 0;
    Node<T> *p = head->next;
    while(p) {
	len++;
	p = p->next;
    }

    return len;
}

template <class T>
void SinglyLinkedList<T>::printList() {
    int len = getLength();
    Node<T> *p = head->next;
    for(int i = 0; i < len; i++) {
	cout<<'['<<i<<"]: "<<p->data<<endl;
	p = p->next;
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};
    SinglyLinkedList<int> list(array, sizeof(array) / sizeof(array[0]));
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
}
