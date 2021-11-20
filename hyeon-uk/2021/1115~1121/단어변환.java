class Solution {
    static boolean visited[]=new boolean[50];
    static int answer=99;
    public void dfs(String now,String target,int cnt,String[] words){
         if(now.equals(target)){
             answer=Math.min(answer,cnt);
             return;
         }
        
        for(int i=0;i<words.length;i++){
            if(visited[i]) continue;
            int c=0;
            String t=words[i];
            for(int j=0;j<t.length();j++){
                if(now.charAt(j)==t.charAt(j)) c++;
            }
            if(c==t.length()-1){
                visited[i]=true;
                dfs(t,target,cnt+1,words);
                visited[i]=false;
            }
        }
    }
    
    public int solution(String begin, String target, String[] words) {
        dfs(begin,target,0,words);
        answer=(answer==99)?0:answer;
        return answer;
    }
}
