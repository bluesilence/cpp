#include <iostream>;
using namespace std;

class QuickUnionFind {
public:
	QuickUnionFind(int n) {
		N = n;
		parents = new int[n];
		for (int i = 0; i < n; i++) {
			parents[i] = i;
		}
	}

	bool connected(int p, int q) {
		return root(p) == root(q);
	}

	void union2(int p, int q) {
		int i = root(p);
		int j = root(q);
		parents[i] = j;
	}

	void print() {
		for (int i = 0; i < N; i++) {
			cout<<i<<": "<<parents[i]<<endl;
		}
	}

private:
	int root(int i) {
		while (parents[i] != i) {
			i = parents[i];
		}

		return i;
	}

	int* parents;
	int N;
};

int main() {
	QuickUnionFind quf(10);
	quf.union2(0, 8);
	quf.union2(1, 7);
	quf.union2(1, 9);
	quf.union2(5, 9);
	quf.union2(5, 3);
	quf.union2(2, 3);
	quf.union2(2, 6);

	quf.print();

	return 0;
}
