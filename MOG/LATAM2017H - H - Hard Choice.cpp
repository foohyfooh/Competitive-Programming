#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char** argv){
	int Ca, Ba, Pa, Cr, Br, Pr, result = 0;
	scanf("%d%d%d", &Ca, &Ba, &Pa);
	scanf("%d%d%d", &Cr, &Br, &Pr);
	if(Ca < Cr) result += Cr - Ca;
	if(Ba < Br) result += Br - Ba;
	if(Pa < Pr) result += Pr - Pa;
	printf("%d\n", result);
	return EXIT_SUCCESS;
}