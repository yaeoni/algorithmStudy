/*
- N 명이 원 / K번째 제거 / N명이 제거될 때 까지
- circular linked list 생각났으나 구현하기 벅찰 것같다.

[생각1]
- index만을 활용한
- count : 모두가 제거 되었는가 -> n이 될 때까지
- index : 위치 탐색
- vector<boolean> deleted : 제거 되었는지 판단
=> 근데 인덱스도 거의 매번 순회하는 것과 다름이 없다.
=> 별로다.. 다른 방법 뭐가있을까 ㅠ?

[검색]
- queue,,,?를 여기서 어떻게 사용하냐 ㅠㅠ 생각은 했어도 활용법은 떠오르지 않아 패스했었다.
- 아~ K까지 빼주고 (뺀 것들은 다시 push처리) 와우,,,, z zz,,,왜 이렇게 생각하지 못했을까 현타.

윽! 속 ! 상 ! 해 ! 하지만 다음에 이런문제 나오면 잘 활용해보자!!!!
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void){

    int n, k;
    scanf("%d %d", &n, &k);

    queue<int> q;
    for(int i = 1; i <=n ; i++){
        q.push(i);
    }

    cout << "<";
    while(!q.empty()){
        // k번째에 있는 것이 제일 앞에 오도록
        for(int i = 0 ; i < k-1 ; i++){
            q.push(q.front());
            q.pop();
        }

        //출력
        // 한 개 남았을 때는 닫는 꺽쇠
        if(q.size() == 1){
            cout << q.front() << ">" << endl;
            q.pop();
        }else{
            cout << q.front() << ", ";
            q.pop();
        }

    }
    return 0;
}