#include "BiNode.h"

int main() {
    BiNode<char> charNode('a');
    charNode.print();

    BiNode<int> emptyNode;
    emptyNode.print();
}
