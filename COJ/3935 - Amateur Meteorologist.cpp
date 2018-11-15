/*
For each day
	Forcast the the result based on the previous actual result
	If the day before was sunny, predict sunny
	If the day before was cloudy, predict cloudy
	If the 3 days before were cloudy, predict rainy
Check if the forcasts match and return the amount that match
*/
#include <iostream>
using namespace std;

string arr[100], forcast[100];

int main(int argc, char** argv){

	int D;
	cin >> D;
	int total, cloudCount = 0;
	for(int i = 0; i < D; i++){
		cin >> arr[i];
	}

	forcast[0] = "sunny";
	total = arr[0] == forcast[0] ? 1 : 0;
	for(int i = 1; i < D; i++){
		if(arr[i - 1] == "sunny") {
			forcast[i] = "sunny";
			cloudCount = 0;
		}
		else if(arr[i - 1] == "rainy") {
			forcast[i] = "rainy";
			cloudCount = 0;
		}
		else if(arr[i - 1] == "cloudy" && cloudCount >= 2) {
			forcast[i] = "rainy";
			cloudCount++;
		}else {
			forcast[i] = "cloudy";
			cloudCount++;
		}
		if(arr[i] == forcast[i]) total++;
	}

	cout << total;


	return EXIT_SUCCESS;
}
