/*
- 'l n’은 정수 n을 Q에 삽입하는 연산
 동일한 정수가 삽입될 수 있음

- ‘D 1’는 Q에서 최댓값을 삭제하는 연산
  ‘D -1’는 Q 에서 최솟값을 삭제하는 연산

- 최댓값(최솟값)을 삭제하는 연산에서 최댓값(최솟값)이 둘 이상인 경우, 하나만 삭제됨
- 만약 Q가 비어있는데 적용할 연산이 ‘D’라면 이 연산은 무시

- Q에 저장될 모든 정수는 32-비트 정수 => int형이 32비트 짜리(4byte)

- 모든 연산을 처리한 후 Q에 남아 있는 값 중 최댓값과 최솟값을 출력

[나]
- pq를 2개 세워서,, (최소큐, 최대큐)로 관리하면 어떨까?,,
    - 그러면 중간값들을 어떻게 넣을 지 & 관리할 지 모르잖슴
- deque를 정렬해서 쓰는건 어떨까? => 매 번 정렬을 해줘야한다.
- 시간제한이 6초다!!!! / 최대 100만개 들어온다!! 
    => I 연산할 때마다 sort 처리를 한 번 해보자 => 역시(?) 시간 초과,,
    => I 연산할 때마다는 사실 필요 없음,,, I에서 D로 바뀔 때만 하면 된다 => 이것도 아니네,,

[검색]
- pq 2개 세워서 관리(오우 이게 되는구나,,)
- 여러 key를 허용하는 multiset 활용
*/

#include <deque>
#include <set>
#include <iostream>
#include <algorithm>


using namespace std;
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        
        int k;
        cin >> k;

        multiset<int> ms; // 기본적으로 오름차순 정렬 & key 중복 가능

        for(int i = 0 ; i < k ; i++){
            char op;
            int n;
            cin >> op >> n;

            if(op == 'I'){
                ms.insert(n);
            }else{
                if(ms.size() == 0) continue;

                if(n == 1){
                    // 최대값 삭제

                    // set은 iterator 이용한 접근(end()는 값이 없어서 --연산 써야함)
                    ms.erase(--ms.end());
                }else{
                    // 최소값 삭제
                    ms.erase(ms.begin());
                }
            }
        
        }

        if(ms.size() == 0) cout << "EMPTY" << "\n";
        else cout << *(--ms.end()) << " " << *(ms.begin()) << "\n";
    }
    return 0;
}
/* deque 이용한 풀이 -> 시간 초과
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--){
        
        int k;
        cin >> k;

        deque<int> dq;
        bool flag = true;

        for(int i = 0 ; i < k ; i++){
            char op;
            int n;
            cin >> op >> n;

            if(op == 'I'){
                dq.push_back(n);
                flag = true;
            }else{
                if(flag == true){
                    //cout << "sort!" << endl;
                    sort(dq.begin(), dq.end());
                    flag = false;
                }
                // 비어있으면 무시
                if(dq.size() == 0) continue;

                if(n == -1){
                    // 최소값 삭제
                    dq.pop_front();
                }else{
                    // 최대값 삭제
                    dq.pop_back();
                }
            }

        }

        if(dq.size()==0) cout << "EMPTY" << "\n";
        else{
            cout << dq[dq.size()-1] <<" " <<dq[0] << "\n";
        }
        
    }
    
    return 0;
}
*/