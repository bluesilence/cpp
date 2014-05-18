#include <iostream>
#include <map>
#include <vector>
using namespace std;

class SuffixTreeNode {
	public:
		vector<int> search(const char* str);
		void insertString(const char* str, int index);
		SuffixTreeNode() {}
		SuffixTreeNode(char ch) {
			value = ch;
		}

		~SuffixTreeNode() {
			map<char, SuffixTreeNode*>::iterator it = children.begin();
			while(it != children.end()) {
				delete it->second;
				it++;
			}

			children.clear();
			indexes.clear();
		}
			
	private:
		map<char, SuffixTreeNode*> children;
		vector<int> indexes;
		char value;
};

void SuffixTreeNode::insertString(const char* str, int index) {
	indexes.push_back(index);

	if( !str || '\n' == *str || '\000' == *str)
		return;
	else {
		char ch = *str;
		SuffixTreeNode* child = NULL;
		map <char, SuffixTreeNode*>::iterator iter = children.find(ch);
		if( iter != children.end() ) {
			child = iter->second;
		} else {
			child = new SuffixTreeNode(ch);
			children.insert(map<char, SuffixTreeNode*>::value_type(ch, child));
		}

		child->insertString(str + 1, index);
	}
}

vector<int> SuffixTreeNode::search(const char* str) {
	vector<int> nullResult;
	nullResult.push_back(-1);
	if( !str )
		return nullResult;
	else if( '\n' == *str || '\000' == *str)
		return indexes;
	else {
		char first = *str;
		map <char, SuffixTreeNode*>::iterator iter = children.find(first);
		if( iter != children.end() ) {
			return iter->second->search(str + 1);
		}
	}

	return nullResult;
}

class SuffixTree {
	public:
		SuffixTree(const char* str) {
			if( !str )
				throw "Null pointer exception: str";
			else {
				for(int i = 0; str[i] != '\n' && str[i] != '\000'; i++) {
					root.insertString(str + i, i);
				}
			}
		}

		vector<int> search(const char* str) {
			return root.search(str);
		}

	private:
		SuffixTreeNode root;
};

int main() {
	string origin;
	string target;
	cout<<"Please input original string:"<<endl;
	cin>>origin;

	cout<<"Please input target string:"<<endl;
	cin>>target;

	SuffixTree tree(origin.data());
	vector<int> indexes = tree.search(target.data());
	for(vector<int>::iterator it = indexes.begin(); it != indexes.end(); it++) {
		cout<<"Found in position: "<<*it<<endl;
	}
}
