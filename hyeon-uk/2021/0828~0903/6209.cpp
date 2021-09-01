#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> maze;
int n,m,d;

int main() {
    cin>>d>>n>>m;
    
    for(int i=0;i<n;i++){
        int data;
        cin>>data;
        maze.push_back(data);
    }
    int left=0;
    int right=d;
    int ret;
    maze.push_back(0);
    maze.push_back(d);
    sort(maze.begin(),maze.end());
    
    while(left<=right){
        int mid=(left+right)>>1;
        int sum=0;
        int now=0;
        for(int i=1;i<maze.size();i++){
            if(maze[i]-maze[now]<mid){
                sum++;
            }
            else{
                now=i;
            }
        }
        if(sum>m){
            right=mid-1;
        }
        else{
            ret=mid;
            left=mid+1;
        }
    }
    cout<<ret;
	return 0;
}