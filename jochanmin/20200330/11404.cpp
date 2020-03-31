#include<bits/stdc++.h>
using namespace std;
#define INF 0x7fffffff
vector<pair<int,int>> edge[20001];
int dist[20001];

int main(void){
    int st;
    int V, E;
    scanf("%d %d", &V, &E);
    for(int i = 1; i <= V; i++)
        dist[i] = INF;
    scanf("%d", &st);
    dist[st] = 0;
    while(E--){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edge[u].push_back({v, w});
    }
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
    pq.push({0, st}); 
    while(!pq.empty()){
        int my_dist = pq.top().first;
        int current = pq.top().second;
        pq.pop();
        if(dist[current] < my_dist)
            continue;
        for(int i = 0; i < edge[current].size(); i++){
            if(dist[edge[current][i].first] > my_dist + edge[current][i].second){
                dist[edge[current][i].first] = my_dist + edge[current][i].second;
                pq.push({dist[edge[current][i].first], edge[current][i].first});
            }
        }
    }
    for(int i = 1; i <= V; i++){
        if(dist[i] == INF)
            printf("INF\n");
        else
            printf("%d\n", dist[i]);
    }
}