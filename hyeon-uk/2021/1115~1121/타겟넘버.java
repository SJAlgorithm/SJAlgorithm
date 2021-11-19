class Solution {
    public static int answer=0;
    
    public void dfs(int[] numbers,int i,int ret,int target){
        if(i==numbers.length){
            if(target==ret) answer++;
            return;
        }
        dfs(numbers,i+1,ret+numbers[i],target);
        dfs(numbers,i+1,ret-numbers[i],target);
    }
    
    public int solution(int[] numbers, int target) {
        dfs(numbers,0,0,target);
        return answer;
    }
}

 

