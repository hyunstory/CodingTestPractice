#include <iostream>
#include <stack>
#include <string>
using namespace std;



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	stack<char> s;
	int n;
	cin >> n;
	
	cin.ignore();

	
	
		while (n--) {
		
			string str;
			getline(cin, str);

			str += '\n';

			for (char ch : str) {
			
				if (ch == ' ' || ch == '\n') {
				
				
					while (!s.empty()) {
					
					
						cout << s.top();
						s.pop();
					}
					cout << ch;

				}
				else { 
					s.push(ch); 
				}

			}
		
		}
	
		
	




	return 0;
}