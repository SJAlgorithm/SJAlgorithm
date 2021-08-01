#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		string func;
		cin >> func;

		int N;
		cin >> N;
		
		string arr;
		cin >> arr;

		deque<int> dq;

		string temp;
		for (int i = 0; i < arr.length(); i++) {
			if (arr[i] >= '0'&&arr[i] <= '9') {
				temp += arr[i];
			}
			else {
				if (!temp.empty()) {
					dq.push_back(stoi(temp));
					temp.clear();
				}
			}
		}

		bool flag = true;
		bool reverse = false;

		for (int i = 0; i < func.length(); i++) {
			if (func[i] == 'R') {
				reverse = !reverse;
			}
			else {
				if (dq.empty()) {
					flag = false;
					cout << "error\n";
					break;
				}
				else {
					if (!reverse) {
						dq.pop_front();
					}
					else {
						dq.pop_back();
					}
				}
			}
		}
		if (flag) {
			if (!reverse) {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.front();
					dq.pop_front();
					if (!dq.empty()) {
						cout << ',';
					}
				}
				cout << "]\n";
			}
			else {
				cout << '[';
				while (!dq.empty()) {
					cout << dq.back();
					dq.pop_back();
					if (!dq.empty()) {
						cout << ',';
					}
				}
				cout << "]\n";
			}
		}
	}
}