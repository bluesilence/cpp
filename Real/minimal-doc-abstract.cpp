#include <vector>;
#include <string>;
#include <iostream>;
using namespace std;

/*
 *Given a large document and a short pattern consisting of a few words (eg. W1 W2 W3),
 *find the shortest string that has all the words in any order
 *(for eg. W2 foo bar dog W1 cat W3 -- is a valid pattern)
 */
class Solution {
public:
	vector<int> minimalAbstract(fstream doc, vector<string> words) {
		//if(targets.size() < 1)	return "";
		//vector<int> indices(targets.size(), -1);
		//int lineIndex = 0;
		//int min = -1, max = -1;
		//int minDistance = numeric_limits<int>::max();
		//While doc != end, read line by line from doc {
		//	line.toLowerCase()
		//	int index = -1;
		//	for(int i = 0, i < words.size(); i++) {
		//		if(-1 != (index = string.find(line, words[i])) {
		//			indices[i] = index + lineIndex;
		//			int newMin = findMin(indices);
		//			int newMax = findMax(indices);
		//			if( newMin > -1 && newMax > -1 && (newMax - newMin < minDistance) {
		//				minDistance = newMax - newMin;
		//				min = newMin;
		//				max = newMax;
		//			}
		//	}
		//	lineIndex += line.length();
		//}
		//vector results;
		//results.push_back(min);
		//results.push_back(max);
		//return results;
	}
};

void main() {
	Solution test;
	
}