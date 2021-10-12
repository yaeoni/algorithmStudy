
/*
- (N ≤ 500,000, 2 ≤ P ≤ 300,000)

- 줄 별로 누르고 있는 프렛 기록 + 가장 높은 프렛 기록
- 가장 높은 프렛 < 누를 프렛 : 새로 누르기(1)
- 가장 높은 프렛 > 누를 프렛 : 누를 프렛보다 높은 프렛들 손 떼기 (a) + 안눌려있다면 누르기(1) 
- 같으면 손가락을 떼거나 누를 필요 없음.

=> 프렛별 기억해야할 것 : 몇 번을 누르고 있는가? 가장 높은 것은 무엇인가?
=> pq를 요소로 갖는 2차원 vector
=> 인터넷은 스택을 이용한다 그래서,, 그 방식도 한 번 봐야겠따,,, 그래도 예원,, 정말 쀼뜼해,, 흑흑흑흑ㅎㄱㅎㄱㅎㄱㅎㄱㅎ

[리팩토링] - 간결하게 ! !! ! 
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int answer = 0;

    int num, fret;
    cin >> num >> fret;

    // pq 는 디폴트로 max heap으로 되어있다.
    // comparaotor 사용하지 않으면 컨테이너 사용하지 않아도 된다.
    // 배열로도 선언 가능하다(2차원 벡터 안써도 됐다!)
    priority_queue<int> pq[num];

    for(int i = 0 ; i < num ; i++){
        int n, p;
        cin >> n >> p;

        // 통 while로 간결하게 ! (hans,,,, 그저 빛)
        // 내 코드는 뭔가 중복된다 싶은게 많았는데 다음엔 통짜만드는 것도 생각해보자
        while(1){
            if(pq[n].empty() || pq[n].top() < p){
                // 프렛을 넣어야하는데, pq가 비어있거나, 가장 높은 프렛보다 넣을 프렛이 높다면 push
                answer++;
                pq[n].push(p);
                break;
            }else if(pq[n].top() > p){
                // 넣어야할 프렛이 가장 높은 프렛보다 작다면 -> 빼내기
                answer++;
                pq[n].pop();
            }else if(pq[n].top() == p){
                // 같다면, 넣을 필요 X, while 문 빠져나와야함.
                break;
            }   

        }
    }

    /* 기존 코드
    // 내림차순 pq 선언(가장 높은 프렛 기억하기 위해서)
    //vector<priority_queue<int, vector<int>, less<int>> > v(num+1);
    
    
    for(int i = 0 ; i < num ; i++){
        // 줄 번호 / 프렛 번호
        
        int n, p;
        cin >> n >> p;
        
        if(!v[n].empty()){
            // 이미 어떤 프렛을 누르고 있다면
            int top = v[n].top();

            if(p > top){
                //가장 높은 프렛 < 누를 프렛 : 새로 누르기(1)
                answer++;
                v[n].push(p);

                //cout <<  n << ", "<< p << " 새로 누릅니당 " << endl;  
            }else if(p < top){
                // 가장 높은 프렛 > 누를 프렛 : 누를 프렛보다 높은 프렛들 손 떼기 (a) + 안눌려있다면 누르기(1) 
                while(1){
                    // 가장 높은 프렛 손 떼기
                    //cout <<  n << ", "<< top << " 손뗍니다. " << endl; 
                    v[n].pop();
                    answer++;
                     
                    if(v[n].empty()){
                        answer++;
                        v[n].push(p);
                        //cout <<  n << ", "<< p << " 떼다가 누릅니다 " << endl; 
                        break;
                    } 

                    top = v[n].top();
                    //cout << "손떼고 top : " << top << endl;
                    if(p > top){
                        // p가 높다
                        answer++;
                        v[n].push(p);
                        //cout <<  n << ", "<< p << " 떼다가 누릅니다 " << endl;  
                        break;
                    }else if(p == top){
                        // 같다면 더이상 안해도된다.
                        break;
                    }
                }
            }
            // 같으면 누를 필요 없다.

        }else{
            // 어떤 프렛도 누르고 있지 않다면 -> 바로 누르기
            answer++;
            v[n].push(p);
            //cout <<  n << ", "<< p << " init으로 누릅니다. " << endl;
        }
        
    }*/
    cout << answer << "\n";
    return 0;
}