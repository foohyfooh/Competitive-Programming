/*
Read in the number of employees
For each employee
    Read the id and birth date
    Look for the first and last / in the date
    Extract the month and increment that month's count
Print the count for each month
*/
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int NUM_MONTHS = 12;
int counts[NUM_MONTHS + 1];

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numEmployees, empId, start, end, month;
    string date;
    for(cin >> numEmployees; numEmployees > 0; numEmployees--){
        cin >> empId >> date;
        start = date.find_first_of('/');
        end = date.find_last_of('/');
        month = stoi(date.substr(start + 1, end - start - 1));
        counts[month]++;
    }

    for(int i = 1; i <= NUM_MONTHS; i++){
        cout << i << " " << counts[i] << endl;
    }

    return EXIT_SUCCESS;
}
