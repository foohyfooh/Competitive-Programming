#include <iostream>
#include <cstdlib>
/*
Summation Formula : n(n+1)/2
if n is 0   then 0 + 1;
if n is +ve then n(n+1)/2
if n is -v2 then 1 - n(n+1)/2
*/

int main(int argc, char** argv) {

	int n;
	std::cin >> n;
	int t = n < 0 ? -n : n;
	std::cout << (n == 0 ? 1 : n < 0 ? 1 - (t*(t+1)/2) : t*(t+1)/2) << std::endl;

	/*int ans;
	if (n == 0) ans = 1;
	else {
		int t = n < 0 ? -n : n;
		int sum = t * (t+1) / 2;
		if (n < 0) sum  = 1 - sum;
		std::cout << sum;
	}*/

	return EXIT_SUCCESS;
}
