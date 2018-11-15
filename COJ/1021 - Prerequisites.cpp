#include <iostream>
#include <cstdlib>
#include <string>
#include <map>

using std::string;
using std::map;

int main(int argc, char** argv) {

	int k, m;//Number of courses, Number of categories
	std::cin >> k;

	while(k != 0){
		std::cin >> m;

		string temp;
		map<string, bool> courses;
		while(k > 0){
			std::cin >> temp;
			courses[temp] = true;
			k--;
		}

		bool requirementsMet = true;
		while(m > 0){
			int c, r;//Number of courses, Number of required courses
			std::cin >> c >> r;
			while(c > 0){
				std::cin >> temp;
				if(courses[temp]) r--;
				c--;
			}
			if(r > 0){//Number of required courses not met
				requirementsMet = false;
			}
			m--;
		}

		std::cout << (requirementsMet ? "yes\n" : "no\n");
		std::cin >> k;
	}

	return EXIT_SUCCESS;
}

