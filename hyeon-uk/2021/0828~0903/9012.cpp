#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

void push(char *arr,char c,int *top) {
	arr[++(*top)] = c;
	return;
}

bool pop(char *arr, int *top) {
	if (*top == -1) return false;
	(*top)--;
	return true;
}

void VPS(char st[]) {
	char arr[51];
	int top = -1;
	int len = strlen(st);
	for (int i = 0; i < len; i++) {
		if (st[i] == '(') {
			push(arr, '(', &top);
		}
		else if (st[i] == ')') {
			if (!pop(arr, &top)) {
				cout << "NO" << endl;
				return;
			}
			
		}
		else;
	}
	if (top == -1) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int t;
	char st[51];
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%s", st);
		VPS(st);
	}
}