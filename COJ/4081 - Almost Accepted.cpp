/*
Read in the correct answer and the user answer
If they match then print Accepted
If they match when whitespace is removed the print Presentation Error
Else print Wrong Answer
*/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>
using namespace std;

string removeWhitespace(string s){
	string copy = "";
	for(int i = 0; i < s.length(); i++){
		if(!isspace(s[i])) copy += s[i];
 	}
	return copy;
}

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string correctAnswer, userAnswer;

	getline(cin, correctAnswer);
	getline(cin, userAnswer);

	if(correctAnswer == userAnswer)
		cout << "Accepted";
	else if(removeWhitespace(correctAnswer) == removeWhitespace(userAnswer))
		cout << "Presentation Error";
	else
		cout << "Wrong Answer";

	return EXIT_SUCCESS;
}

