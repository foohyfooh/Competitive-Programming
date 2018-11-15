/*
Read N and the fighters
sort the fighters
Print the last then print from the first onwards
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAX_FIGHTERS = 10000;
int fighters[MAX_FIGHTERS];

int main(int argc, char** argv){
	int numFighters;
	scanf("%d", &numFighters);

	for(int i = 0; i < numFighters; i++)
		scanf("%d", &fighters[i]);
	sort(fighters, fighters + numFighters);

	printf("%d ", fighters[numFighters - 1]);
	for(int i = 0; i < numFighters - 1; i++)
		printf("%d ", fighters[i]);

	return EXIT_SUCCESS;
}
