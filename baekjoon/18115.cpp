/*
1)제일 위의 카드 1장을 바닥에 내려놓는다.
2)위에서 두 번째 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.
3)제일 밑에 있는 카드를 바닥에 내려놓는다. 카드가 2장 이상일 때만 쓸 수 있다.

- 위에서부터 순서대로 1,2,,,N 이면 내려놓을 때는 N, N-1,,,,1 

기술 : 2 3 3 2 1
카드 : 1 5 2 3 4

위에서 두번째 5 [? 5 ? ? ?]
제일 밑에 4 [? ? ? 4] -> [? 5 ? ? 4]
제일 밑에 3 [? ? 3] -> [? 5 ? 3 4]
위에서 두번째 2 [? 2] 
제일 위 1 [1] 

- 배열에 넣고 매번 해당 요소를 삭제하기엔 N (1 ≤ N ≤ 10^6) => 시간 초과

[생각한 방법]
1.  - 시작과 끝의 index를 가지고 왔다갔다 하기,,? => 이러면 뭔가,, 자료구조를 쓰는 느낌이 아닌디.
    - 그래도 해봤따... 마치 투포인터,,

2. 역순으로 해보기,,,, 생각하다 말았다.


[방법]
- 기술은 N, N-1, ,,, 1 카드를 순서대로 빼낸다.

- 정답 크기만큼 벡터를 선언하고 0(비어있는 값)으로 초기화한다.
- 배열의 시작(start)과 끝(end)의 index를 기억한다.(비어있는 곳을 가리키게!) 
- 기술의 순서대로 카드를 집어넣는데, 이때 기술1이나 기술3이 쓰였을 때엔 값을 채우고 start or end 인덱스를 옮긴다.
=> 위의 방식대로만 하면 틀렸었는데, start와 end를 멋대로 ++,-- 하면안됐다. next index도 둬서 체크해야함
=> 근데 맨 위 / 맨 아래 / 위에서 두 번째 이렇게 밖에 없어서 next가 항상 옆칸 or 옆옆칸 이렇게 된당.

=> 그냥 deque 써라!!!
*/


#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//deque 버전(거슬러 올라가기)
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> v(n, 0); // 순서 기억 용
    deque<int> dq;

    for(int i = 0 ; i < n ; i++){
        cin >> v[i];
    }

    int num = 1;
    for(int i = v.size()-1 ; i >= 0 ; i--){
        if(v[i] == 1){
            dq.push_front(num);
        }else if(v[i]==2){  
            int temp = dq.front();
            dq.pop_front();
            dq.push_front(num);
            dq.push_front(temp);
        }else{
            dq.push_back(num);
        }
        num++;
    }
    
    for(auto d: dq) cout << d << " ";
    return 0;
}

void useIndex(){
    int n;
    cin >> n;
    vector<int> v(n, 0);

    int start = 0;
    int next = start+1;
    int end = n-1;

    for(int i = n ; i > 0 ; i--){ // N, N-1, ,,, 1 카드를 순서대로 빼낸다.
        int op;
        cin >> op;

        if(op == 1){
            //맨 위에 고르기
            v[start] = i;
            if(v[start+1] == 0) start++;
            else start = next+1; //한 칸 옆으로 옮기기
        }else if(op == 2){
            // 위에서 두번째 고르기(=다음으로 비어있는 한 칸 고르기)
            if(v[start+1] == 0) next = start+1;
            else next++;
            v[next] = i;
        }else{
            //맨 아래 고르기
            v[end] = i;
            end--;
        }
    }

    for(auto num : v) cout << num << " ";

}
