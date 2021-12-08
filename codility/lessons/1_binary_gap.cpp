#include <iostream>
#include <algorithm>
using namespace std;

int answer = 0;
bool isGap = false;

int cnt = 0;

int solution(int N) {

    while(N != 1){
        if(N%2){
            // 첫번째 1이 나와야 갭이 시작이다.
            if(!isGap){
                isGap = true;
            }else{
                // 세어진 0 이 있고, 1을 만나면 gap이 끝난 것이다.
                if(cnt > 0){
                    answer = max(answer, cnt);
                    cnt = 0;
                }
            }  
        }else{
           if(isGap){
               cnt++;
           }
        }
    
        N /= 2;
    }

    answer = max(answer, cnt);

    return answer;
}
