// <파일 합치기2> - BOJ_13974
// DP 최적화 - Knuth's Optimization : O(N^2)풀이

/*
(동적계획법 최적화 기법)

<< Knuth's Optimization >>
naive complexity         : O(n^3)
Optimization complexity  : O(N^2)

아래를 만족하는 경우 최적화를 진행할 수 있음.

Recurrence: DP[i][j] = Min(DP[i][k] + DP[k+1][j] + C[i][j]): (i≤k<j) , C는 cost
    -> 점화식
Condition: C[i][j] is a Monge array, and satisfies C[a][d] ≥ C[b][c] for a≤b≤c≤d. (Monge array? 아래참고)
    -> 사각 부등식(Quadrangle Inequality) : C[a][c]+C[b][d] ≤ C[a][d]+C[b][c] (Monge arry조건)
    -> 단조성 (Monotonicity)              : C[b][c]≤C[a][d] (a≤b≤c≤d)

Lemma: opt[i][j−1] ≤ opt[i][j] ≤ opt[i+1][j]
    -> opt[x][y]의 값은 dp[x][y]가 최소가 되게 하는 k. (위의 점화식에서의 k와 동일)

       이렇게 순회했을 경우 총 루프가 도는 횟수는, j−i=k 라고 두었을 때
       ∑(opt[i+1][i+k] − opt[i][i+k−1]) = (opt[n−k+1][n] − opt[1][k]) ≤ n 으로, 하나의 (j−i) 에 대해서 O(n) 이니 총 O(n2) 이다.

Proof: http://www.egr.unlv.edu/~bein/pubs/knuthyaotalg.pdf (증명은 쉽지않음....)


+ O(NlogN) 풀이도 있음.
    ->  Garsia-Wachs algorithm
    ->  Hu-Shing Algorithm

- 출처: https://koosaga.com/243 [구사과]
*/


/*
<< Monge array >> 
{ C[a][c]+C[b][d] ≤ C[a][d]+C[b][c] } 를 만족
대부분 C[i][j]가 구간[i,j]를 사용할 때의 비용을 의미하므로 (a ≤ b ≤ c ≤ d) 라고 할 수 있음.

ex)
| x .. y | x:(a,c) , y:(a,d)
| ..  .. |
| z .. k | z:(b,c) , k:(b,d)
즉, x+k ≤ y+z 를 만족
    a ≤ b ≤ c ≤ d 를 만족
*/


#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;

int T,N;
int cost[5001]{};
int ps[5001]{};
int dp[5001][5001]{};
int opt[5001][5001]{};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>T;
    while(T--){
        memset(dp, 0, sizeof(dp));
        cin>>N;
        for(int i=1; i<=N; i++){
            cin>>cost[i];
            ps[i] = ps[i-1] + cost[i];
            opt[i][i] = i;
        }

        for(int d=1; d<N; d++){
            for(int x=1; x+d<=N; x++){
                int y = x+d;
                dp[x][y] = INF;
                // opt[i][j−1] ≤ opt[i][j] ≤ opt[i+1][j] 인 k만 탐색함
                for(int k=opt[x][y-1]; k<=opt[x+1][y]; k++){ // 이 부분에 의해 
                    int t = dp[x][k]+dp[k+1][y] + ps[y]-ps[x-1];
                    if(dp[x][y] > t){
                        dp[x][y] = t;
                        opt[x][y] = k; // opt[i][j] 업데이트
                    }
                }
                
            }
        }

        cout<<dp[1][N]<<'\n';
    }
}