import java.util.ArrayList;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayList<Integer> tempAns = new ArrayList();
        
        
        int index = 0;
        int temp = index;
        
        for(int i = 0 ; i <= 100 ; i++){
            //System.out.println(i+"th");
            
            if(index >= progresses.length)
                break;
            //큰 포문 탈출 조건
            
            for(int j = 0 ; j < progresses.length ; j++){
                progresses[j] += speeds[j];
            }
            int count = 0;
            
                if( index < progresses.length && progresses[index] >= 100){
                    count++;

                    while( ++temp < progresses.length && progresses[temp]>=100){
                        count++;
                    }
                    
                    index = temp;
                    
                    tempAns.add(count);
                }
            
        }
        int[] ret = new int[tempAns.size()];
        
        for (int i=0; i < ret.length; i++)
        {
            ret[i] = tempAns.get(i);
        }
        return ret;
    }
}