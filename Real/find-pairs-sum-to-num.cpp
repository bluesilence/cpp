#include <vector>;
#include <algorithm>;
#include <iostream>;
using namespace std;

struct Pair {
	int a;
	int b;

	Pair(int x, int y) {
		a = x;
		b = y;
	}
};

class Solution {
public:
	vector<Pair> findPairs(vector<int> inputs, long long num) {
		sort(inputs.begin(), inputs.end());
		vector<Pair> results;

		if(inputs.front() * 2 > num || inputs.back() * 2 < num) { //Impossible to find the pair
			return results;
		} else {
			int i = 0, j = inputs.size() - 1;
			while (i < j) {
				long long tmp = inputs[i] + inputs[j];
				if (num == tmp) {
					Pair p(inputs[i], inputs[j]);
					results.push_back(p);
					i++;
					j--;
				} else if (tmp < num) {
					i++;
				} else {
					j--;
				}
			}

			return results;
		}
	}
};

void main() {
	Solution test;
	int iarray[] = {3, 1, 4, 7, 2, 5, 9, 8, 0};
	size_t count = sizeof(iarray) / sizeof(int);
	vector<int> ivec(iarray, iarray + count);
	vector<Pair> results = test.findPairs(ivec, 9);

	for(vector<Pair>::iterator it  = results.begin(); it != results.end(); )  
	{  
		Pair p = *it++;
		cout<<p.a<<','<<p.b<<endl;  
	}  
}