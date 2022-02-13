#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001
using namespace std;

int n, cost =  0;
struct Planet{
    int idx, x, y, z;
};
bool cmpx (Planet a, Planet b){
    return a.x < b.x;
}
bool cmpy (Planet a, Planet b){
    return a.y < b.y;
}
bool cmpz (Planet a, Planet b){
    return a.z < b.z;
}
struct Tunnel{
    int i, j, w;
    bool operator < (const Tunnel &t) const {
        return w < t.w;
    }
};
Planet planet[MAX];
vector<Tunnel> tunnel;
int tree[MAX];

int findRoot(int v){
    if(tree[v] == v) return v;
    return tree[v] = findRoot(tree[v]);
}

int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
    	scanf("%d %d %d",&planet[i].x,planet[i].y ,planet[i].z);
        planet[i].idx = i;
        tree[i] = i;
    }
    sort(planet+1, planet+n+1, cmpx);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back({planet[i].idx, planet[i+1].idx, abs(planet[i].x-planet[i+1].x)});
    }
    sort(planet+1, planet+n+1, cmpy);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back({planet[i].idx, planet[i+1].idx, abs(planet[i].y-planet[i+1].y)});
    }
    sort(planet+1, planet+n+1, cmpz);
    for(int i = 1; i <= n-1; i++){
        tunnel.push_back({planet[i].idx, planet[i+1].idx, abs(planet[i].z-planet[i+1].z)});
    }
    sort(tunnel.begin(), tunnel.end());
    for(Tunnel t : tunnel){
        int i = findRoot(t.i);
        int j = findRoot(t.j);
        if(i != j){
            tree[j] = i;
            cost += t.w;
        }
    }
    printf("%d",cost);

    return 0;
}