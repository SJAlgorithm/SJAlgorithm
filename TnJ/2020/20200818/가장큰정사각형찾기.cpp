#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> board)
{
    
    int rsz = board.size();
    int csz = board[0].size();
    int maxn=0;
    for(int j=0; j<csz; j++){
        if(board[0][j]) {maxn=1; break;}
    }
    for(int i=1; i<rsz; i++){
        for(int j=1; j<csz; j++){
            if(board[i][j]){
                board[i][j] = min({board[i-1][j-1],board[i-1][j],board[i][j-1]}) + 1;
                maxn = max(maxn, board[i][j]);
            }
        }
    }

    return maxn*maxn;
}