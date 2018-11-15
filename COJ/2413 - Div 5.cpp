/*
Read in the number
Check if the last digit is a 5 or 0 to determine if divisible by 5
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

	int numTests;
	string num;
	for(scanf("%d", &numTests); numTests > 0; numTests--){
		cin >> num;
		if(num[num.size() - 1] == '5' || num[num.size() - 1] == '0') printf("YES\n");
		else printf("NO\n");
	}

	return EXIT_SUCCESS;
}
