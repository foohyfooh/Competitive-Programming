/*
Read N
Read in each number as a string
Extract the last digit and determine if it is even or odd from that
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, last;
	string num;

	for(cin >> N; N > 0; N--){
		cin >> num;
		last = num[num.size() - 1] - '0';
		if(last % 2 == 0) printf("even\n");
		else printf("odd\n");
	}

	return EXIT_SUCCESS;
}
