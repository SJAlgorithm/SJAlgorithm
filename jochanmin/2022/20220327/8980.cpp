#include <iostream>
#include <algorithm>
using namespace std;

struct box {
	int u;
	int v;
	int w;
};

box arr[10000];
int capacity[10001] = { 0 };
int n = 0, c = 0, m = 0;
int result = 0;

bool cmp(box a, box b) {
	if (a.v < b.v)return true;
	else if (a.v == b.v)
		if (a.u < b.u)
			return true;
		
	return false;
}

int main() {
	cin >> n >> c;
	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> arr[i].u >> arr[i].v >> arr[i].w;

	sort(arr, arr + m,cmp);

	for (int i = 0; i < m; i++) { 
		int maxcnt = 0;
		for (int j = arr[i].u; j < arr[i].v; j++)  
			maxcnt = max(capacity[j], maxcnt); 
		int val = min(arr[i].w, c - maxcnt);
		result += val;
		
		for (int j = arr[i].u; j < arr[i].v; j++) {
			capacity[j] += val;
		}

	}
	cout << result << endl;
}