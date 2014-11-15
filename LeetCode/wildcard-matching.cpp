// LeetCode.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h";
#include <iostream>;
#include <vector>;
using namespace std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        //? match one
        //* match 0,1,2,3..
        // aaaabc *c true
        const char* star = nullptr;
        const char* rs = nullptr;
        
        while(*s) {
            if(*s == *p || *p == '?') { //match
                s++;
                p++;
                
                continue;
            }
            
            if(*p == '*') { 
                star = p; // record star
                p++; //match from next p
                rs = s; // record the position of s , star match null
                
                continue;
            }
            
            if(star != nullptr) { //if have star in front then backtrace
                p = star + 1; //reset the position of p 
                s = rs + 1; //star match 1,2,3,4,5.... 
                rs ++; //record next position for backtrace
                
                continue;
            }
            
            return false; //if not match return false
        }
        
        while(*p == '*') p++; //skip continuing star
        
        return *p == '\0'; // successful match
    }
};

int main()
{
	Solution s;
	
	cout<<"Result: "<<s.isMatch("hi", "*?")<<endl;
}