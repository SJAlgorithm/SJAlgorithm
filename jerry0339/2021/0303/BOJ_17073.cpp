#include<iostream>
using namespace std;

int N;
double K;
int deg[500002]{};

int main() {
	ios_base::sync_with_stdio(false); 
    cin.tie(0);
    cin>>N;
    cin>>K;
    int a,b;
    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
    }

    double cnt = 0;
    for(int i=2; i<=N; i++){
        if(deg[i]==1) cnt++;
    }
    
    cout.precision(10);
    cout<<fixed;
    cout<<K/cnt;
}