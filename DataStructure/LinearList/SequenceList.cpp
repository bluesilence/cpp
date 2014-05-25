#include <iostream>
using namespace std;

typedef unsigned int uint;

const uint MAX_SIZE = 100;

template <class T>
class SequenceList {
    private:
	T array[MAX_SIZE];
	uint length;

    public:
	SequenceList() {
	    length = 0;
	}

	SequenceList(T *a, uint size) {
	    if( !a || 0 == size || MAX_SIZE < size )
		throw "Invalid initial array parameters";
	    
	    for( uint i = 0; i < size; i++ ) {
		array[i] = a[i];
	    }

	    length = size;
	}

	T get(uint index) {
	    if( index >= length )
		throw "Invalid index";
	    return array[index];
	}

	int locate(const T element) {
	    for( uint i = 0; i < length; i++ ) {
		if( array[i] == element )
		    return i;
	    }

	    //Not found
	    return -1;
	}

	void insert(T element, uint index) {
	    if( MAX_SIZE == length )
		throw "Overflow";
	    if( length < index )
		throw "Invalid index";
	    for( int i = length-1; i >= index; i-- ) {
		array[i+1] = array[i];
	    }

	    array[index] = element;
	    length++;
	}

	T remove(uint index) {
	    if( 0 == length )
		throw "Underflow";
	    if( length <= index )
		throw "Invalid index";
	    
	    T removed = array[index];
	    for( uint i = index; i < length-1; i++ ) {
		array[i] = array[i+1];
	    }

	    length--;

	    return removed;
	}

	void print() {
	    if( 0 == length ) {
		cout<<"Empty list"<<endl;
	    } else {
		for( uint i = 0; i < length; i++ ) {
		    cout<<array[i]<<' ';
		}

		cout<<endl;
	    }
	}
};

int main() {
    int arr[] = { 0, 1, 2, 3, 4 };
    
    SequenceList<int> emptySeq;
    emptySeq.print();

    cout<<"Initialize seq with {0, 1, 2, 3, 4}"<<endl;
    SequenceList<int> seq(arr, 5);
    seq.print();
    cout<<"Insert 6 at index 3"<<endl;
    seq.insert(6, 3);
    seq.print();
    cout<<"Remove element at index 4"<<endl;
    seq.remove(4);
    seq.print();
    cout<<"Element at index 0: "<<seq.get(0)<<endl;
    cout<<"Location of Element 5: "<<seq.locate(5)<<endl;
    cout<<"Location of Element 6: "<<seq.locate(6)<<endl;
}
