#include<iostream>
using namespace std;

int n;
int maze[100][100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> maze[i][j];

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (maze[i][k] == 1 && maze[k][j] == 1) maze[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << maze[i][j] << " ";
		}
		cout << "\n";
	}
}