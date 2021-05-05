#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

class ant {
private:
	map<string, ant *> child;
public:
	void insert(vector<string>& hole, int ind) {
		if (ind == hole.size()) {
			return;
		}

		if (child.find(hole[ind]) == child.end()) {
			child[hole[ind]] = new ant ();
		}
		child[hole[ind]]->insert(hole, ind + 1);
	}

	void print(int lev) {
		for (auto& c : child) {
			for (int i = 0; i < lev; i++) {
				cout << "--";
			}
			cout << c.first << "\n";
			c.second->print(lev + 1);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	ant *r = new ant();

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		vector<string> hole(k);
		for (int j = 0; j < k; j++) {
			cin >> hole[j];
		}

		r->insert(hole, 0);
	}
	r->print(0);

	return 0;
}

