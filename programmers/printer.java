import java.util.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Integer> q = new LinkedList<>();
        Queue<Integer> loc = new LinkedList<>();
        
        
        for(int i = 0 ; i < priorities.length ; i++){
            q.add(priorities[i]);
            loc.add(i);
        }
        
        int count = 0;
        
        while(true){
            int temp = q.poll();
            int index = loc.poll();
            
            if(q.isEmpty()){
                answer = count+1;
                break;
            }
            
            if( Collections.max(q) > temp ){
                q.offer(temp);
                loc.offer(index);
            }else{
                count++; // 없다면 항상 증가 해야함
                if(index == location){
                    answer = count;
                    break;
                }
                
            }
            
        }
    
        return answer;
    }
}