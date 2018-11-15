#include <iostream>
#include <cstring>
using namespace std;

int x[10];

void reduceByOne(string& U, int pos){
	if(U[pos] > '0') {
		U[pos]--;
		for(int i = pos + 1; i < U.length(); i++){
			U[i] = '9';
		}
	}else if(U[pos] == '0'){
		reduceByOne(U, pos - 1);
	}
}

string determineL(string U){
	memset(x, 0, sizeof(int) * 10);

	int pos = -1;
	for(int i = 0; i < U.length() && pos == -1; i++){
		int num = U[i] - '0';
		x[num]++;
		if(x[num] > 2) pos = i;
	}

	if(pos == -1) {
		return U;
	}

	reduceByOne(U, pos);

	for(int i = 0; i < U.length(); i++){
		if(U[i] != '0') return determineL(U.substr(i));
	}
}

int main(int argc, char** argv){

	string U;
	cin >> U;
	cout << determineL(U) << endl;

	return EXIT_SUCCESS;
}