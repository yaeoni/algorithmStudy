/*
- A번 , B번은 몇 번째 라운드에서 만나는가?
- 계속 이긴다는 가정

- A와 B가 1씩 차이나고, 더 큰 번호를 가진 애가 2의 배수일때 붙게된다.
*/
#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

    // 더 큰애를 b로 바꿔버리기
    // 즉 a,b의 차이가 1이고 b가 2의 배수일 때 만나는것
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }

    while(1){
        if( (b-a==1) && (b%2==0)){
            break;
        }
        
        if(a%2==0){
            a = a/2;
        }else{
            a = (a+1)/2;
        }
        
        if(b%2==0){
            b = b/2;
        }else{
            b = (b+1)/2;
        }

        answer++;
    }
    

    return answer;
}

// +1해서 몫을 구해도 다음라운드이다.(2의 배수로 잘리니까,,,)
int solution(int n, int a, int b)
{
    int answer = 0;

    while(a!=b){
        a = (a+1)/2;
        b = (b+1)/2;
        answer ++;
    }

    return answer;
}