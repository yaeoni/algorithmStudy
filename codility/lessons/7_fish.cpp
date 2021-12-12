/*
- P < Q 이면 P물고기가 Q물고기보다 앞에 있는겨
- A : 물고기 크기 / 모두 유니크 값
- B : 물고기 방향(0: upstream, 1: downstream)

- 만나면, 크기 큰 놈이 작은 놈을 먹는다.
- P < Q, B[P] = 1(down) and B[Q] = 0(up) 이고, 가운데에 물고기 없으면 만난다.

- 모두 같은 속도 / 같은 방향은 절대 안만난다.
- 최종 alive 한 물고기 수를 구하기.
*/
#include <vector>
#include <stack>
using namespace std;

using namespace std;

int direction = -1;
stack<int> s;

int non_solution(vector<int> &A, vector<int> &B) {
    
    int size = A.size();

    // init
    s.push(A[0]);
    direction = B[0];

    for(int i = 1 ; i < size ; i++){
        if(direction == B[i]) s.push(A[i]);
        else{
            if(direction == 1 && B[i] == 0){ // 부딪힌다.
                //cout << "crash! " << i << endl;
                if(s.top() > A[i]){
                    continue;
                }else{
                    // stack 속에 있는 것이 잡아먹힘
                    s.pop();
                    s.push(A[i]);
                    //cout << "out and push" << endl;
                    direction = 0;  
                }
            }else{
                direction = B[i];
                s.push(A[i]);
            }
        }
        //cout << direction << " " << s.size() << endl;
    }

    return s.size();
}

/*
- P < Q 이면 P물고기가 Q물고기보다 앞에 있는겨
- A : 물고기 크기 / 모두 유니크 값
- B : 물고기 방향(0: upstream, 1: downstream)

- 만나면, 크기 큰 놈이 작은 놈을 먹는다.
- P < Q, B[P] = 1(down) and B[Q] = 0(up) 이고, 가운데에 물고기 없으면 만난다.

- 모두 같은 속도 / 같은 방향은 절대 안만난다.
- 최종 alive 한 물고기 수를 구하기.
*/
#include <vector>
#include <stack>
using namespace std;

using namespace std;

// "내려오는 물고기들이 올라오는 물고기를 만났을 때 부딪히므로, 거기서 삭제되는 물고기만 생각해주면된다. 아!" 흑흑
stack<int> down;

int solution(vector<int> &A, vector<int> &B) {
    int alive = A.size();
    int size = A.size();

    for(int i = 0 ; i < size ; i++){
        if(B[i] == 1) down.push(A[i]);
        else{
            // 크면 계속 지워준다.
            while(!down.empty() && A[i] > down.top()){
                alive--;
                down.pop();
            }

            // 작으면 먹힌다.(안들어간다)
            if(!down.empty() && A[i] < down.top()) alive--;
        }
    }
    

    return alive;
}