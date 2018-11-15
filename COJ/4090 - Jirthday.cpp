/*
Read birth year
Print age in 3000
*/
#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int year;
	cin >> year;
	int age = 3000 - year;
	cout << age;

	return EXIT_SUCCESS;
}

