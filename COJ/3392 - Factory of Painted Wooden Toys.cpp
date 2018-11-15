#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

	int N, res;
	for(scanf("%d", &N); N != 0; scanf("%d", &N)){
		if(N < 3) res = 0;
		else res = 12 * (N - 2);
		printf("%d\n", res);
	}

	return EXIT_SUCCESS;
}
