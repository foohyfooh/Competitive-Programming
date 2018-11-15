/*
Read in the dimensions
Read in the picture information
For each +
	If a - exist above, below, right or, or left of it then increase the count
Print the count
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_SIZE = 1000;
char picture[MAX_SIZE][MAX_SIZE];

int main(int argc, char** argv){

	int height, width;
	scanf("%d%d", &height, &width);
	for(int i = 0; i < height; i++)
		scanf("%s", picture[i]);

	int count = 0;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			if(picture[i][j] == '+'){
				if(i > 0 && picture[i - 1][j] == '-') count++;
				else if(i < height - 1 && picture[i + 1][j] == '-') count++;
				else if(j > 0 && picture[i][j - 1] == '-') count++;
				else if(j < width - 1 && picture[i][j + 1] == '-') count++;
			}
		}
	}
	printf("%d", count);

	return EXIT_SUCCESS;
}
