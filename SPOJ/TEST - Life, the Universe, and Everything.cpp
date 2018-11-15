/*
Read in numbers and output it.
Stop when 42 is read
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
	int num;
	for(scanf("%d", &num); num != 42; scanf("%d", &num))
		printf("%d\n", num);
	return EXIT_SUCCESS;
}
