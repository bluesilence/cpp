#include "TrieTree.h"
using namespace std;

int main() {
    TrieTree tree;
    tree.print();
    char* str1 = "sunny";
    char* str2 = "spring";
    char* str3 = "speed";
    tree.insert(str1);
    tree.insert(str2);
    tree.insert(str3);

    tree.print();
    cout<<"Finding "<<str1<<"..."<<tree.find(str1)<<endl;
    cout<<"Finding "<<str2<<"..."<<tree.find(str2)<<endl;
    cout<<"Finding "<<str3<<"..."<<tree.find(str3)<<endl;
    cout<<"Finding sp..."<<tree.find("sp")<<endl;
    cout<<"Finding ee..."<<tree.find("ee")<<endl;
    cout<<"Finding ing..."<<tree.find("ing")<<endl;
}
