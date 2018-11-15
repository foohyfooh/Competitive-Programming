/*
Read in the time
Determine which time interval it is in
Determine how much mintues have passed
Check if it the time is within the 45 minutes class time or the 5 minutes break
*/
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string time;
	getline(cin, time);

	int hrs = stoi(time.substr(0, 2));
	int mins = stoi(time.substr(3, 2));


	if(7 <= hrs && hrs <= 11){
		hrs -= 7;
	}else{ // 1 <= hrs && hrs <= 5
		hrs -= 1;
	}

	mins += hrs * 60;
	mins %= 50;

	if(mins < 45)  cout << "Students, Surprise Quiz!";
	else cout << "Students, you may go out.";

	return EXIT_SUCCESS;
}
