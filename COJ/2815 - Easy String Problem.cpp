/*
For each test case
	Read in T and P
	Repeatedly P from T until it cannot be removed anymore
	Print the number of times that P was removed
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTests, numReductions, pos;
    string text, pattern;
    for(cin >> numTests; numTests > 0; numTests--){
        cin >> text >> pattern;
        numReductions = 0;
        pos = text.find(pattern);
        while(pos != string::npos){
            numReductions++;
            text = text.substr(0, pos) + text.substr(pos + pattern.length());
            pos = text.find(pattern);
        }
        cout << numReductions << endl;
    }

    return EXIT_SUCCESS;
}
