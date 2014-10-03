#include "TrieTree.h"
using namespace std;

int main() {
    TrieTree tree;
    tree.print();
    char* str1 = "sunny";
    char* str2 = "spring";
    char* str3 = "speed";
    char* str4 = "crazy";
    char* str5 = "cat";
    char* str6 = "hat";
    char* str7 = "";
    tree.insert(str1);
    tree.insert(str2);
    tree.insert(str3);
    tree.insert(str4);
    tree.insert(str5);
    tree.insert(str6);
    tree.insert(str7);

    tree.print();
    cout<<"Finding "<<str1<<"..."<<tree.find(str1)<<endl;
    cout<<"Finding "<<str2<<"..."<<tree.find(str2)<<endl;
    cout<<"Finding "<<str3<<"..."<<tree.find(str3)<<endl;
    cout<<"Finding "<<str4<<"..."<<tree.find(str4)<<endl;
    cout<<"Finding "<<str5<<"..."<<tree.find(str5)<<endl;
    cout<<"Finding "<<str6<<"..."<<tree.find(str6)<<endl;
    cout<<"Finding "<<str7<<"..."<<tree.find(str7)<<endl;
    cout<<"Finding sp..."<<tree.find("sp")<<endl;
    cout<<"Finding ee..."<<tree.find("ee")<<endl;
    cout<<"Finding ing..."<<tree.find("ing")<<endl;
}
