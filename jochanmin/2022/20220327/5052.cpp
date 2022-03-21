#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  int T, n, i;
  cin >> T;
  while(T--){
    cin >> n;
    string s;
    vector<string> v(n);
    for(i=0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    bool answer = true;
    for(i=0; i <n-1; i++){
      if(v[i] == v[i+1].substr(0, v[i].length())){
        answer = false;
        break;
      }
    }
    cout << (answer ? "YES":"NO") <<endl;
  }
  return 0;
}