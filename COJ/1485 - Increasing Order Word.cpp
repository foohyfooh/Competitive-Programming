/*
Read C
Sort C
Print sorted C
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string C;
	cin >> C;
	sort(C.begin(), C.end());
	cout << C;

	return EXIT_SUCCESS;
}