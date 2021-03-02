#include<iostream>
#include<algorithm>
#include<cmath>
typedef unsigned long long ull;
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int d;
        double t;
        int k=-1;
        for(d=2;d*d<=n*2;d++){           
            t=((double)n/d)-(d/2.0)-0.5;
            if(t-(int)t==0){
                k=(int)t;
                break;
            }
        }
        if(k==-1){
            cout<<"IMPOSSIBLE\n";
        }
        else{
            cout<<n<<" = ";
            for(int i=k+1;i<k+d;i++){
                cout<<i<<" + ";
            }
            cout<<k+d<<"\n";
        }
    }
	return 0;
}


//k+(k+1)+(k+2)+....+(k+d)=(k+d+1)*(k+d)/2 - (k*(k+1)/2)
//                        =((k+d)*(k+d)+(k+d)-k*k-k)/2
//                        =2kd+d^2+d/2  =  d*(2k+d+1)/2 = n
//                           d*(2k+d+1)=2n
//     k=n/d-d/2-1/2
