#include <bits/stdc++.h>
using namespace std;

int N, cnt;
vector<pair<int ,int>> v;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    int start, end;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &start, &end);
        v.push_back(make_pair(start, end));
    }
    sort(v.begin(), v.end(), compare);
    int endTime = v[0].second;
    for (int i = 1; i < N; i++) {
        if (endTime <= v[i].first) {
            endTime = v[i].second;
            cnt++;
        }
    }
    
    printf("%d\n", cnt+1);
    
    return 0;
}

