#include <iostream>
#include <cstdlib>

int main(int argc, char** argv) {

	int t;
	std::cin >> t;

	int n, m, value;
	for(; t > 0; t--){
		std::cin >> n >> m;
		//int votes[n]{}, highest;
		int *votes = (int*)calloc(n, sizeof(int)), highest;
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				std::cin >> value;
				votes[j] += value;
			}
		}

		highest = 0;
		for(int i = 1; i < n; i++){
			if(votes[i] > votes[highest])
				highest = i;
		}

		std::cout << (highest + 1) << std::endl;
	}

	return EXIT_SUCCESS;
}
