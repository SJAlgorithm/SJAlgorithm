#include<bits/stdc++.h>
using namespace std;
int main(){
	double x,y,c;
	scanf("%lf %lf %lf",&x,&y,&c);
	double left=0.0,right=min(x,y);
	double mid;
	while(abs(right-left)>1e-3){
		mid=(left+right)/2.0;
		double h1=sqrt(x*x-mid*mid);
		double h2=sqrt(y*y-mid*mid);
		double h=(h1*h2)/(h1+h2);
		if(h>c)
			left=mid;
		else
			right=mid;
	}
	printf("%.3lf",mid);
	return 0;
}