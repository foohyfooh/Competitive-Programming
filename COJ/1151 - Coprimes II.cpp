/*
Read T
For T test cases
	Read N, A, B
	range = A - B + 1*
	Compute the factors of N
	Determine the count of the numbers which are not coprime with N using Inclusion - Exclusion Principle
	Print range - count
*/
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numTests, num, start, end, count;
	vector<int> primeFactors;
	cin >> numTests;
	while(numTests--){
		cin >> num >> start >> end;
		count = end - start + 1;
		if(num != 1){
			primeFactors.clear();
			if(num % 2 == 0) primeFactors.push_back(2);
			while(num % 2 == 0) num = num / 2;

			for(int i = 3; i * i <= num; i += 2){
				if(num % i == 0){
					primeFactors.push_back(i);
					while(num % i == 0) num = num / i;
				}
			}

			if(num > 2) primeFactors.push_back(num);

			for(int i = 1, numFactors = primeFactors.size(), factorMask = (1 << numFactors); i < factorMask; i++){
				int factor = 1, sign = -1;
				for(int j = 0; j < numFactors; j++){
					if(i & (1 << j)){
						factor *= primeFactors[j];
						sign *= -1;
					}
				}
				count -= sign * (end / factor - (start - 1) / factor );
			}
		}

		cout << count << "\n";
	}

	return EXIT_SUCCESS;
}

