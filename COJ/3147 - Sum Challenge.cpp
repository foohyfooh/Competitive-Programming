/*
Read T
For T test cases
    Read N
    Read N numbers
    Check for consecutive numbers that add to zero
    Print YES if consective sum adds to zero else NO
*/
#include <bits/stdc++.h>
using namespace std;

const int NUM_TESTS = 100;
const int NUM_NUMS = 50;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numTestCases, size;
    int nums[NUM_NUMS];
    for(cin >> numTestCases; numTestCases > 0; numTestCases--){
        cin >> size;
        for(int i = 0; i < size; i++) cin >> nums[i];

        bool hasZeroSum = false;
        for(int i = 0; i < size; i++){
            int sum = 0;
            for(int j = i; j < size; j++){
                sum += nums[j];
                if(sum == 0){
                    hasZeroSum = true;
                    goto checks;
                }
            }
        }

        checks: cout << (hasZeroSum ? "YES" : "NO") << "\n";
    }

    return EXIT_SUCCESS;
}

