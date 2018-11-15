/*
Triangle Problem using Top-Down Approach
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

#define max(a, b) ((a) > (b)) ? (a) : (b)

const int MAX_TRIANGLE = 100;
int triangle[MAX_TRIANGLE][MAX_TRIANGLE];

int main(int argc, char** argv){

	int numTests, triangleSize, end, largest;
	for(scanf("%d", &numTests); numTests > 0; numTests--){
		scanf("%d", &triangleSize);
		largest = 0;
		for(int i = 0; i < triangleSize; i++){
			for(int j = 0; j <= i; j++){
				scanf("%d", &triangle[i][j]);
				if(i == 0 && j == 0);
				else if(j == 0) triangle[i][j] += triangle[i - 1][j];
				else if(j == i) triangle[i][j] += triangle[i - 1][j - 1];
				else triangle[i][j] += max(triangle[i - 1][j - 1], triangle[i - 1][j]);
				if(triangle[i][j] > largest) largest = triangle[i][j];
			}
		}

		printf("%d\n", largest);
	}

	return EXIT_SUCCESS;
}
