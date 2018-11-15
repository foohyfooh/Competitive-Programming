/*
Read in the number K and the sequence length N

The sequence length needs to be a multiple of K to be correct where each number has (N / K) occurrences

If the sequence is a multiple of K then the max needs to be removed and the min added

If the sequence is not a multiple then it can be possible corrected if the sequence has 1 extra or 1 less than a multiple of K
	If 1 less then add the number with the lowest count
	If 1 more then remove the number with the highest count

With the resulting sequence from the above cases has matching occurances for all numbers then it is fine

If the sequence does not satisfy the above conditions then it is unsolvable
*/
#include <cstdio>
#include <cstdlib>
using namespace std;

const int MAX_NUM = 1000;
short int count[MAX_NUM + 1];

bool verifySequence(int max){
	for(int i = 2; i <= max; i++)
		if(count[i - 1] != count[i]) return false;
	return true;
}

int main(int argc, char** argv){

	int K, sequenceLength, num, min = 1, max = 1;
	scanf("%d%d", &K, &sequenceLength);
	for(int i = 0; i < sequenceLength; i++){
		scanf("%d", &num);
		count[num]++;
	}

	for(int i = 1; i <= K; i++){
		if(count[i] < count[min]) min = i;
		if(count[i] > count[max]) max = i;
	}

	int remainder = sequenceLength % K;
	if(remainder == (K - 1)){ //+ a num
		count[min]++;
		if(verifySequence(K)) printf("+%d\n", min);
		else printf("*\n");
	}else if(remainder == 1){ //- a num
		count[max]--;
		if(verifySequence(K)) printf("-%d\n", max);
		else printf("*\n");
	}else if(remainder == 0) {// - a num + a num
		count[min]++;
		count[max]--;
		if(verifySequence(K)) printf("-%d +%d\n", max, min);
		else printf("*\n");
	}else{ //unsolvable
		printf("*\n");
	}

	return EXIT_SUCCESS;
}