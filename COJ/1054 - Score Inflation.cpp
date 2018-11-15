#include <iostream>
#include <cstdlib>

/*
Essentially Knapack Problem

Read in the maxWeight and numItems
Read in item data:
	Each line is the value and the weight
	Enter into a list sorted by weights

Constructing knapsack[2, maxWeight]:
	Get the gcd of the items weights, d
	Each index, j, of a row would be a remaining weight of j * d; so if d = 5, then j = 1 means remaining weight is 5, 2 means remaining weight is 10, etc
	Use only 2 rows since the values for the knapsack[currentIndex] is only based on the  knapsack[previousIndex]

	Determining the value of knapsack[currentIndex, j] where currentIndex is values for the current item, j is the weights
		If the weight is bigger than the knapsack then return knapsack[previousIndex, j]
		Else
			get the value with this item by using the value of the current item plus the value of the knapsack with the remaining weight
			check if the remaining weight can have another of this item; if so then add that value at the remaining weight; if not then add the value of the previous item at the remaining weight
			return the max of this value or the value of the previous knapsack at this weight

	Swap the previousIndex and currentIndex at the end of each loop

	Return the value of knapsack[previousIndex, maxWeight]
*/

struct Item{
	int value, weight;
};

int knapsack(int max, Item* items, int numRows);
int gcd(int a, int b);

int main(int argc, char** argv) {

	int k;//number of test cases
	std::cin >> k;

	for(; k > 0; k--){
		int m, n, d = 0; //total available time, number of probems, gcd
		std::cin >> m >> n;
		Item* items = (Item*) calloc(n, sizeof(Item));
		for(int i = 0; i < n; i++){
			std::cin >> items[i].value >> items[i].weight;
			d = gcd(d, items[i].weight);
		}
		for(int i = 0; i < n; i++) items[i].weight /= d;
		std::cout << knapsack(m / d, items, n) << std::endl;
		free(items);
	}

	return EXIT_SUCCESS;
}


int knapsack(int maxWeight, Item* items, int numRows){
	if(maxWeight == 0) return 0;

	//Allocate knapsack
	//Use calloc instead  of regular array declaration to get zeros in all initially
	int** knapsack = (int**) calloc(2, sizeof(int*));
	knapsack[0] = (int*) calloc(maxWeight + 1, sizeof(int));
	knapsack[1] = (int*) calloc(maxWeight + 1, sizeof(int));

	/*for(int b = 0; b <= maxWeight; b++){
		printf("%d,", b);
	}
	printf("\n");*/

	int previousIndex = 0, currentIndex = 1;
	for(int item = 0; item < numRows; item++){
		for(int weight = 1; weight <= maxWeight; weight++){
			if(items[item].weight > weight)
				knapsack[currentIndex][weight] = knapsack[previousIndex][weight];
			else{
				int remainingWeight = weight - items[item].weight;
				int value = items[item].value + knapsack[currentIndex][remainingWeight];
				knapsack[currentIndex][weight] = std::max(value, knapsack[previousIndex][weight]);
			}
			//printf("%d,", knapsack[currentIndex][weight]);
		}
		std::swap(previousIndex, currentIndex);
		//printf("\n");
	}
	int optimalValue = knapsack[previousIndex][maxWeight];

	//Unallocate knapsack
	free(knapsack[0]);
	free(knapsack[1]);
	free(knapsack);

	return optimalValue;
}

int gcd(int a, int b){
	int temp;
	while(a != 0){
		temp = a;
		a = b % a;
		b = temp;
	}
	return b;
}
