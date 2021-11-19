class Solution {
    static int parent[]=new int[200];
    public void init(int n){
        for(int i=0;i<n;i++) parent[i]=i;
    }
    public int find_parent(int c){
        if(c==parent[c]){
            return c;
        }
        else{
            return find_parent(parent[c]);
        }
    }
    public void union_parent(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        
        if(a>b){
            parent[a]=b;
        }
        else{
            parent[b]=a;
        }
    }
    public int solution(int n, int[][] computers) {
        int answer = 0;
        init(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && computers[i][j]==1){
                    union_parent(i,j);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(parent[i]==i) answer++;
        }
        return answer;
    }
}