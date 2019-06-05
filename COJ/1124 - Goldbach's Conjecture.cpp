/*
Use the Sieve of Eranthoses to get prime numbers
For each number
    Go through the primes and see if the corresponding remainder is also prime
    Print the two prime numbers
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX_NUMS = 1e6;
vector<int> primes;
array<bool, MAX_NUMS> isPrime;

int main(int argc, char** argv){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    isPrime.fill(true);
    isPrime[0] = isPrime[1] = false;
    primes.push_back(2);
    for(int i = 4; i < MAX_NUMS; i += 2) isPrime[i] = false;
    for(int i = 3; i < MAX_NUMS; i += 2){
        if(isPrime[i]){
            primes.push_back(i);
            for(int j = i + i; j < MAX_NUMS; j += i) isPrime[j] = false;
        }
    }

    int num;
    for(cin >> num; num != 0; cin >> num){
        bool solved = false;
        for(auto prime: primes){
            int rem = num - prime;
            if(isPrime[rem]){
                solved = true;
                cout << num << " = " << prime << " + " << rem << "\n";
                break;
            }
        }
        if(!solved) cout << "Goldbach's conjecture is wrong.\n";
    }

    return EXIT_SUCCESS;
}
