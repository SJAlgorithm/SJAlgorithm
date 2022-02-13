#include<cstdio>
using namespace std;

int main(){
    for(int i=1;i<=100;i++){
        for(int j=2;j<=i;j++){
            for(int k=j;k<=i;k++){
                for(int q=k;q<=i;q++){
                    if(i*i*i==j*j*j+k*k*k+q*q*q){
                        printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,q);
                    }
                }
            }
        }
    }
    
    return 0; 
}