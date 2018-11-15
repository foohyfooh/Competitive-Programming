#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){

	int numTests;
	double a, b, c, tq;
	scanf("%d", &numTests);
	for(; numTests > 0; numTests--){
		scanf("%lf %lf %lf", &a, &b, &c);
		if(a == b && b == c) printf("equilateral\n");
		else {
			tq = ((b + c - a) * (a + b - c) * (c + a - b)) / (a * b * c);
			if(0.5 < tq) printf("good\n");
			else printf("bad\n");
		}
	}

	return EXIT_SUCCESS;
}
