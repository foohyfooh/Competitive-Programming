/*
Read T
For each test
	Read N
	Use a greedy solution to determine the amount of each coin type
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

const int COPPER = 1, TRIADS = 3, NONAS = 9, CUBICS = 27;

int main(int argc, char** argv){

	int numTests, coin, coppers, triads, nonas, cubics;
	scanf("%d", &numTests);
	for(int t = 1; t <= numTests; t++){
		scanf("%d", &coin);
		cubics = coin / CUBICS;
		coin %= CUBICS;
		nonas = coin / NONAS;
		coin %= NONAS;
		triads = coin / TRIADS;
		coin %= TRIADS;
		//coppers = coin / COPPER;
		//coin %= COPPER;
		//printf("Case #%d: %d Coppers %d Triads %d Nonas %d Cubics\n", t, coppers, triads, nonas, cubics);
		printf("Case #%d: %d Coppers %d Triads %d Nonas %d Cubics\n", t, coin, triads, nonas, cubics);
	}

	return EXIT_SUCCESS;
}
