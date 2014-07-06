#include <iostream>
#include <vector>
using namespace std;

typedef unsigned int uint;

//next array: index (1 ~ len+1)
//pattern: index (0 ~ len-1)
//So the index of pattern == ((the index of next) - 1)
void buildNext( char* pattern, uint len, uint *next ) {
    if( !pattern || !next )
	throw "NullPointerException";
    else if( len < 1 )
	throw "Length must be positive";
    else {
	next[1] = 0;
	uint i = 1, t = 0;
	while( i < len + 1 ) {
	    while( t > 0 && pattern[i-1] != pattern[t-1] ) {
		t = next[t];
	    }

	    t++;
	    i++;

	    if( pattern[i-1] == pattern[t-1] ) {
		next[i] = next[t];
	    } else {
		next[i] = t;
	    }
	}

	--t;

	//Scroll pattern to beginning for next match
	//t-1 is to map from next array(start from 1) to pattern string(start from 0)
	while( t > 0 && pattern[len-1] != pattern[t-1] ) {
	    t = next[t];
	}

	++t;
	
	//i == len + 1
	next[i] = t;
    }

    //debug
    for(int j = 1; j <= len+1; j++ ) {
	cout<<"Pattern["<<j-1<<"]="<<pattern[j-1]<<", Next["<<j<<"]="<<next[j]<<endl;
    }
}

//next array: index (1 ~ pattern_len+1)
//target and pattern: index (0 ~ len-1)
vector<int> kmp( char *target, uint target_len, char *pattern, uint pattern_len ) {
    if( !target || !pattern )
	throw "NullPointerException";
    uint *next = new uint[pattern_len + 2];
    uint i = 0, j = 1;
    buildNext( pattern, pattern_len, next );

    vector<int> matches;
    while( pattern_len - (j - 1) <= target_len - i ) {
	if( pattern[j-1] == target[i] ) {
	    i++;
	    j++;

	    if(j == pattern_len + 1) {
		matches.push_back(i - (j - 1));
		j = next[j];
	    }
	} else {
	    j = next[j];

	    if(0 == j) {
		i++;
		j++;
	    }
	}
    }

    delete next;
    return matches;
}

int strlen(char* str) {
    char* p = str;
    while(*p++ != '\0');
    return p - str - 1;
}

int main() {
    char* target = "adcabcabcabacd";
    char* pattern = "abcab";
    cout<<"Target string: "<<target<<endl;
    cout<<"Pattern string: "<<pattern<<endl;
    int target_len = strlen(target);
    int pattern_len = strlen(pattern);
    cout<<"Target length: "<<target_len<<endl;
    cout<<"Pattern length: "<<pattern_len<<endl;

    vector<int> matches = kmp( target, target_len, pattern, pattern_len );
    if( !matches.empty() ) {
	for(int i = 0; i < matches.size(); i++ )
	{
	    cout<<"Match["<<i<<"]: "<<matches[i]<<endl;
	}
    } else {
	cout<<"No matches found."<<endl;
    }
}
