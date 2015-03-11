#include "stdafx.h";

#include <vector>;
#include <iostream>;
using namespace std;

class Solution {
public:
    int Package01(vector<int> &values, vector<int> &volumes, int maxVolume) {
		if (values.size() != volumes.size())
			throw "Values array and volumes array size mismatches.";

		vector<int> maxValues(maxVolume + 1, 0);
		vector<vector<int> > items(maxVolume + 1, vector<int>());

		// 0-1 package: maxValues[i][m] = max(maxValues[i][m-1], maxValues[i - volumes[j]][m-1] + values[j])
		for (int j = 0; j < volumes.size(); j++) {
			// 在每次主循环中我们以v=V..0的顺序推f[v]，这样才能保证推f[v]时f[v-c[i]]保存的是状态f[i -1][v-c[i]]的值
			for (int i = maxVolume; i >= volumes[j]; i--) {
				const int pickItemJValue = maxValues[i - volumes[j]] + values[j];
				maxValues[i] = max(maxValues[i], pickItemJValue);

				if (maxValues[i] == pickItemJValue) {
					items[i] = items[i - volumes[j]];
					items[i].push_back(j);
					
					cout<<"Items["<<i<<"]: ";
					vector<int> itemVec = items[i];
					for (int k = 0; k < itemVec.size(); k++)
						cout<<itemVec[k]<<',';

					cout<<endl;
				}
			}
		}

		vector<int> finalItems = items[maxVolume];
		for (int i = 0; i < finalItems.size(); i++) {
			cout<<finalItems[i]<<", ";
		}

		cout<<endl;

        return maxValues[maxVolume];
    }
};

void main() {
    Solution test;
    vector<int> values;
    values.push_back(1);
    values.push_back(4);
    values.push_back(1);
    values.push_back(3);

    vector<int> volumes;
    volumes.push_back(1);
    volumes.push_back(3);
    volumes.push_back(2);
    volumes.push_back(4);

	int maxVolume = 7;
	cout<<test.Package01(values, volumes, maxVolume)<<endl;
}
