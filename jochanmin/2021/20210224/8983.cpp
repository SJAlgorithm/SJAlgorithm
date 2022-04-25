#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll n, m, l,res;

vector<ll> gun;
int func(ll animal) {

	ll l = 0,r=gun.size()-1;
	while (l < r) {
		ll mid = (l + r) >> 1;

		if (gun[mid] < animal) l = mid + 1;
		else r = mid;
	}
    
	if (l > 0) {
		if (abs(animal - gun[l - 1]) < abs(animal - gun[l])) return gun[l - 1];
		else return gun[l];
	}
	else return gun[l];
}
int main() {
	cin >> m >> n >> l;
	for (int i = 0; i < m; i++) {
		ll a;
		cin >> a;
		gun.push_back(a);
	}

	sort(gun.begin(), gun.end());
	for (int i = 0; i < n; i++) {
		ll a, b;
		cin >> a >> b;
		ll p=func(a);
		if (abs(a - p) + b <= l) res++;
	}
	cout <<res << '\n';
	return 0;
}