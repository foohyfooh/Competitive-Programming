/*
Read N
Read the N lines
If the line is P=NP then print skipped
Else print a+b
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string line;
	getline(cin, line);

	int numAdditions = stoi(line);


	for(int i = 0; i < numAdditions; i++){
		getline(cin, line);
		if(line.find("P=NP") != string::npos) cout << "skipped\n";
		else {
			auto pos = line.find("+");
			int a = stoi(line.substr(0, pos));
			int b = stoi(line.substr(pos + 1));
			cout << (a + b) << "\n";
		}
	}

	return EXIT_SUCCESS;
}
