
/*
- 탑 개수 50만
- 높이 1억

- 왼쪽으로 발사(끝에서부터 빼기 -> 스택)
- 가장 먼저 만나는 탑(수신한 탑) 번호 출력

- stack에 (높이, index) 쌓기 -> pop()하면서 비교해야할 것 같은데
    => 바로 옆 탑과 만나지 않은 경우 그 값들을 어떻게 기억해야할까?
    => 스택을 하나 더 만들어서 이전 값을 기억하려했는데 이러면 너무 오래걸릴 것 같았다.

=> 스택 한 가지만으로 된다. 
    => 입력 받으면서 수신탑이 될 수 있는 것들을 남긴다(=입력받는 값보다 스택값이 클 때)
    => 입력값이 top보다 크다면, 해당 top은 지운다(그 뒤의 요소들의 수신탑이 될 수없음)

=> 잉 ? 시간 초과 scanf, printf 쓰자!
*/
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);

    stack<pair<int, int> > stack;
    for(int i = 0 ; i < n ; i++){
        int height;
        scanf("%d", &height);

        while(!stack.empty()){
            if(height < stack.top().second){
                // 수신탑 만났다면
                printf("%d ", stack.top().first+1);
                break; 
            }else{
                // 입력값이 top보다 크다면 top은 pop 시킨다
                stack.pop();
            }
        }
        // 스택이 비어있다면(= 수신탑 할만한게 없음) 0 출력 & 값 푸쉬
        if(stack.empty()) printf("%d ", 0);
        stack.push(make_pair(i,height)); // index, value
    }

    return 0;
}