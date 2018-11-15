/*
For each test case
	Read D
	Read S or B
	If S
		Print the corresponding patterns

	If B
		Read the rows
		Print the corresponding number for each pattern
		Note that since all have the same last row they can be ignored
*/
#include <bits/stdc++.h>

using namespace std;

string buffer;
string rows[3];

int main(int argc, char** argv){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int numDominos;

	getline(cin, buffer);
	numDominos = stoi(buffer);

	while(numDominos != 0){
		getline(cin, buffer);
		char operation = buffer[0];

		if(operation == 'S'){
			getline(cin, buffer);

			rows[0].clear();
			rows[1].clear();
			rows[2].clear();

			for(int i = 0; i < buffer.size(); i++){
				      if(buffer[i] == '1'){
					rows[0] += '*';
					rows[0] += '.';
					rows[0] += ' ';

					rows[1] += '.';
					rows[1] += '.';
					rows[1] += ' ';
				}else if(buffer[i] == '2'){
					rows[0] += '*';
					rows[0] += '.';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '.';
					rows[1] += ' ';
				}else if(buffer[i] == '3'){
					rows[0] += '*';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '.';
					rows[1] += '.';
					rows[1] += ' ';
				}else if(buffer[i] == '4'){
					rows[0] += '*';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '.';
					rows[1] += '*';
					rows[1] += ' ';
				}else if(buffer[i] == '5'){
					rows[0] += '*';
					rows[0] += '.';
					rows[0] += ' ';

					rows[1] += '.';
					rows[1] += '*';
					rows[1] += ' ';
				}else if(buffer[i] == '6'){
					rows[0] += '*';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '.';
					rows[1] += ' ';
				}else if(buffer[i] == '7'){
					rows[0] += '*';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '*';
					rows[1] += ' ';
				}else if(buffer[i] == '8'){
					rows[0] += '*';
					rows[0] += '.';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '*';
					rows[1] += ' ';
				}else if(buffer[i] == '9'){
					rows[0] += '.';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '.';
					rows[1] += ' ';
				}else if(buffer[i] == '0'){
					rows[0] += '.';
					rows[0] += '*';
					rows[0] += ' ';

					rows[1] += '*';
					rows[1] += '*';
					rows[1] += ' ';
				}

				rows[2] += '.';
				rows[2] += '.';
				rows[2] += ' ';
			}

			cout << rows[0] << "\n";
			cout << rows[1] << "\n";
			cout << rows[2] << "\n";
		}else{ //operation == 'B'
			getline(cin, rows[0]);
			getline(cin, rows[1]);
			getline(cin, rows[2]);

			char a, b, c, d;
			for(int i = 0; i < numDominos; i++){
				a = rows[0][i * 3 + 0];
				b = rows[0][i * 3 + 1];

				c = rows[1][i * 3 + 0];
				d = rows[1][i * 3 + 1];

				     if(a == '*' && b == '.' && c == '.' && d == '.') cout << 1;
				else if(a == '*' && b == '.' && c == '*' && d == '.') cout << 2;
				else if(a == '*' && b == '*' && c == '.' && d == '.') cout << 3;
				else if(a == '*' && b == '*' && c == '.' && d == '*') cout << 4;
				else if(a == '*' && b == '.' && c == '.' && d == '*') cout << 5;
				else if(a == '*' && b == '*' && c == '*' && d == '.') cout << 6;
				else if(a == '*' && b == '*' && c == '*' && d == '*') cout << 7;
				else if(a == '*' && b == '.' && c == '*' && d == '*') cout << 8;
				else if(a == '.' && b == '*' && c == '*' && d == '.') cout << 9;
				else if(a == '.' && b == '*' && c == '*' && d == '*') cout << 0;
			}
			cout << "\n";
		}


		getline(cin, rows[0]);
		numDominos = stoi(rows[0]);
	}


	return EXIT_SUCCESS;
}
