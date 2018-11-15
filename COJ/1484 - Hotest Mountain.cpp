/*
Read N
Read in the N temps [T <= 1000]
Check which temp is the heighest
Print the position of the heighest
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_MOUNTAINS = 100;
const double MAX_TEMP = 1000;
int temps[MAX_MOUNTAINS + 1];

int main(int argc, char** argv){

	int numMountains;
	scanf("%d", &numMountains);
	for(int i = 1; i <= numMountains; i++) scanf("%f", &temps[i]);

	int max = 1;
	for(int i = 2; i <= numMountains; i++)
		if(temps[i] >= temps[max]) max = i;

	printf("%d", max);

	return EXIT_SUCCESS;
}
