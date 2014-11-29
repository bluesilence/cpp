#include <vector>;
#include <algorithm>;
#include <string>;
#include <iostream>;
using namespace std;

/*
 */
class Solution {
public:
    string getPermutation(int n, int k) {
       //Form the sequence from 1 to n
       string origin;
       for (int i = 1; i <= n; i++) {
           origin += i + '0';
       }
       
       //Generate all possible permutations
       vector<string> permutations;
       genPermutations(origin, 0, permutations);
       
       //Return the kth sequence in the sorted array
       if (k > permutations.size() || k < 1) {  //k starts from 1?
           return "";
       } else {
           //Sort the permutations ascendantly
           sort(permutations.begin(), permutations.end());
           return permutations[k - 1];
       }
    }
    
    void genPermutations(string &str, int index, vector<string> &results) {
        if (str.size() <= index) { //Come to the end, collect the string
            results.push_back(str);
        } else {
            for (int i = index; i < str.size(); i++) {
                swap(str, index, i);
                genPermutations(str, index + 1, results);
                swap(str, index, i);
            }
        }
    }
    
    void swap(string &str, int indexA, int indexB) {
        if (indexA != indexB && indexA >= 0 && indexB >=0 && indexA < str.size() && indexB < str.size()) {
            char tmp = str[indexA];
            str[indexA] = str[indexB];
            str[indexB] = tmp;
        }
    }
};
