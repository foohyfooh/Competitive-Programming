#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){

    int i, j;
    while(std::cin >> i >> j){
        int originalI = i, originalJ = j;
        if(i > j) std::swap(i, j);
        int highestCount = 0;
        for(int a = i; a <= j; a++){
            int count = 1;
            int b = a;
            while(b != 1){
                if(b % 2 == 0){
                    b >>= 1;//right shift for faster division
                    count++;
                }else{
                    b = 3 * b + 1;
                    b >>= 1; //do the division now since it became even
                    count += 2;
                }
            }
            if(count > highestCount) highestCount = count;
        }
        std::cout << originalI << " " << originalJ << " " << highestCount << std::endl;
    }

    return EXIT_SUCCESS;
}
