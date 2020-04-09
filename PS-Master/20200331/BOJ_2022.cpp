// <사다리> BOJ_2022
// Binary Search
// 파라메트릭, 이분탐색 -> 재귀말고 반복문 사용하기

#include<bits/stdc++.h>
using namespace std;

double f(double x, double y, double d) {
	double sqrt1 = sqrt(x*x - d * d);
	double sqrt2 = sqrt(y*y - d * d);
	return sqrt1 * sqrt2 / (sqrt1 + sqrt2);
}
int main(void) {
	double x, y, c;
	(scanf("%lf %lf %lf", &x, &y, &c));
	double st = 0;
	double en = min(x, y);
	while (en - st > 1e-6) {
		double mid = (st + en) / 2;
		if (f(x, y, mid) > c)
			st = mid;
		else
			en = mid;
	}
	printf("%.3f\n", st);
}