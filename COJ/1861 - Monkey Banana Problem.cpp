#include <iostream>
#include <cstdlib>

/*
Essentially Triangle Problem

Read the number of N
Number of rows = 2 * N - 1
Number of items = N*N
Store in a 2D array [1..N, 1..N] where
	if i <= N then in the top and thus numbers are in A[i, j]
	else i > N then in the bottom and thus numbers are in A[i - N, i - N + j]

Determining Max Sum
	Go through squares and add up the values
	If i < N From a point (i, j):
		left is (i + 1, j)
		right is (i + 1, j + 1)
	Else i >= N From a point (i, j):
		If == 1: right is (i + 1, j)
		Else If (2*N - i) == j: (i + 1, j - 1)
		Else
			left is (i + 1, j - 1)
			right is (i + 1, j
*/

int triangle[100][100], mem[100][100];
int T(int N, int i, int j){
	return i < N ? triangle[i][j] : triangle[i - N][i - N + j + 1];
}

int setT(int N, int i, int j, int value){
	return (i < N ? triangle[i][j] : triangle[i - N][i - N + j + 1]) = value;
}

int M(int N, int i, int j){
	return i < N ? mem[i][j] : mem[i - N][i - N + j + 1];
}

int setM(int N, int i, int j, int value){
	return (i < N ? mem[i][j] : mem[i - N][i - N + j + 1]) = value;
}

int bestSum(int N, int i, int j) {
	if(M(N, i, j) != -1) return M(N, i, j);
	int left, right;
	if(i < N){
		left = bestSum(N, i + 1, j);
		right = bestSum(N, i + 1, j + 1);
	}else if(j == 1){
		left = -1;
		right = bestSum(N, i + 1, j);
	}else if((2*N - i) == j){
		left = bestSum(N, i + 1, j - 1);
		right = -1;
	}else{
		left = bestSum(N, i + 1, j - 1);
		right = bestSum(N, i + 1, j);
	}
	return setM(N, i, j, (T(N, i, j) + std::max(left, right)));
}

int main(int argc, char** argv) {

	int t;//number of test cases
	std::cin >> t;

	for(int a = 1; a <= t; a++){
		int N, value;
		std::cin >> N;
		for(int row = 1, end = 2*N-1; row <= end; row++){
			for(int j = 1, limit = row <= N ? row : (2*N - row); j <= limit; j++){
				//std::cout << row << "," << j << std::endl;
				std::cin >> value;
				setT(N, row, j, value);
				setM(N, row, j, -1);
			}
		}
		setM(N, 2*N-1, 1, T(N, 2*N-1, 1));

		//for(int i = 1; i <= N; i++){
		//	for(int j = 1; j <= N; j++){
		//		std::cout << T(N, i, j) << " ";
		//		//std::cout << M(N, i, j) << " ";
		//	}
		//	std::cout << std::endl;
		//}
		//std::cout << "\n\n\n\n";

		std::cout << "Case " << a << ": " << bestSum(N, 1, 1) << std::endl;
	}

	return EXIT_SUCCESS;
}
