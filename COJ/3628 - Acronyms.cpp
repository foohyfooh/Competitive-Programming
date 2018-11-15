/*
For each test
	Read the authors and the string to check
	Check each letter that begins a word
	If all match then print yes else print no
*/
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string authors, toCheck;
	bool matched;
	size_t nextI, nextJ;

	while(getline(cin, authors) && getline(cin, toCheck)){
		matched = true;
		for(int i = 0, j = 0; matched && i != string::npos && j != string::npos;){
			matched = authors[i] == toCheck[j];
			i = authors.find(" ", i);
			j = toCheck.find(" ", j);
			if(i != string::npos) i++;
			if(j != string::npos) j++;
		}
		if(matched) cout << "yes\n";
		else cout << "no\n";
	}


	return EXIT_SUCCESS;
}
