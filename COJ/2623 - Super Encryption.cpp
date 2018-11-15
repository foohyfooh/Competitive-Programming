/*
Read the string
Reverse the first half and the second half independant of each other
Print the reverse;
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string word;
    cin >> word;
    int split = word.length() / 2;
    reverse(word.begin(), word.begin() + split);
    if(word.length() % 2 != 0) split++;
    reverse(word.begin() + split, word.end());
    cout << word;

    return EXIT_SUCCESS;
}
