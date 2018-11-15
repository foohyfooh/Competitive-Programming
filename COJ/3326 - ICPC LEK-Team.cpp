#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char words[1001][9];

int main(int argc, char** argv){

	int numTests, numWords;
	bool found, wrong;
	scanf("%d", &numTests);
	while(numTests--){
		scanf("%d", &numWords);
		for(int i = 1; i <= numWords; i++) scanf("%s", &words[i]);
		for(int i = 1; i < numWords; i++){
			wrong = found = false;
			for(int j = i + 1; j <= numWords && !wrong && !found; j++){
				int cmp = strcmp(words[j], words[i]);
				if(cmp <= 0) wrong = true;
				else if(cmp > 0){
					printf("%d ", j);
					found = true;
				}
			}
			if(wrong || !found) printf("-1 ");
		}
		printf("-1\n");
	}

	return EXIT_SUCCESS;
}
