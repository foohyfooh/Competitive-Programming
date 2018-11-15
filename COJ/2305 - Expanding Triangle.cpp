#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(int argc, char** argv){
	int numTestCases;
	double A, B, C;

	scanf("%d", &numTestCases);
	while (numTestCases--){
		scanf("%lf %lf %lf", &A, &B, &C);
		double s = (A + B + C)/2;
		printf("%.1lf\n", 7 * sqrt(s * (s - A) * (s - B) * (s - C)));
	}

	return EXIT_SUCCESS;
}
