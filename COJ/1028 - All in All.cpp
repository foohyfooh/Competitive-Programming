#include <iostream>
#include <cstdlib>

/*
get first char of s1
while not at the end of s1
	search for current char is s2
	loop through s2 looking for s1
		if found then exit this loop
		else not found then s2 is not an encrypted version of s1
	move to next char in s1
endwhile
if didn't exit loop then is the encrypted version of the string
*/

int main(int argc, char** argv) {

	char s1[31], s2[31];
	while(std::cin >> s1 >> s2){
		int i = 0, j = 0;
		while(s1[i] != '\0'){
			bool found = false;
			while(s2[j] != '\0' && !found){
				if(s1[i] == s2[j]){
					found = true;
				}
				j++;
			}
			if(!found) goto failure;
			i++;
		}

		if(true){
			std::cout << "Yes\n";
		}else{
			failure: std::cout << "No\n";
		}
	}

	return EXIT_SUCCESS;
}
