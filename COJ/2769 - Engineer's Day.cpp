/*
Read N
Print N times "i: I am participating in the Engineer's day."
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
		printf("%d: I am participating in the Engineer's day.\n", i);

	return EXIT_SUCCESS;
}
