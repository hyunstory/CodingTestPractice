#include <iostream>
#include <deque>
#include <string>

using namespace std;


deque<int> d;

int main() {
	

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin.tie(0);


	int repeat;
	int value;

	cin >> repeat;

	while (repeat--) {
		
		string cmd;
		cin >> cmd;


		if (cmd == "push_back") {
		
			cin >> value;
			d.push_back(value);

		}
		else if (cmd == "push_front") {
		
			cin >> value;
			d.push_front(value);

		}
		else if (cmd == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << "\n";
				d.pop_front();
			}
			else { cout << "-1" << "\n"; }
		}
		else if (cmd == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << "\n";
				d.pop_back();
			}

			else { cout << "-1" << "\n"; }
			}
		else if (cmd == "size") {
		
			cout << d.size() << "\n";
		}
		else if (cmd == "empty") {
		
			if (d.empty()) { cout << "1" << "\n"; }
			else { cout << "0" << "\n"; }
		}
		else if (cmd == "front") {
		
			if (!d.empty()) {
				cout << d.front() << "\n";
				
			}
			else { cout << "-1" << "\n"; }
		}
		else if (cmd == "back") {
			if (!d.empty()) {
				cout << d.back() << "\n";
				
			}

			else { cout << "-1" << "\n"; }
		}
			
	}

	return 0;
		
	}
	

	
	
	
	


