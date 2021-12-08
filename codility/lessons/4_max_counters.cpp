#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 0;

vector<int> non_solution(int N, vector<int> &A) {
    vector<int> answer(N, 0);

    for(auto a : A){
        // A 요소들은 모두 1 이상
        if(a <= N){
            // a == 3이면 배열에선 2번째
            answer[a-1]++;
            maxNum = max(answer[a-1], maxNum);
        }else{
            std::fill(answer.begin(), answer.end(), maxNum);
        }
    }

    return answer;
}

// fill 함수를 써서 max로 만드는 것도 퍼포먼스 70퍼
// 어떻게 퍼포먼스를 낼 수 있을까...
// 하나하나 돌면서 넣는 방법말고 다른 방법은?
// 시점마다 max 값을 구하고 최종 시점의 Max로 한꺼번에 업데이트 하는 방식,,

#include <vector>
#include <algorithm>

using namespace std;

int maxNum = 0;

// 최종 max 값 - max counter가 동작하지 않을 수 있으니 최종적으로 체크해야한다.
// A[i]가 N+1 안나올 수 있음
int lastMaxNum = 0; 

vector<int> solution(int N, vector<int> &A) {
    vector<int> answer(N, 0);

    for(int i = 0 ; i < A.size() ; i++){
        if(A[i] == N+1){
            lastMaxNum = maxNum; // 최종 max 값 저장
        }else{
            // max counter 돌고 나서도 lastMaxNum보다 작을 때 => 값 바꿔주기
            if(answer[A[i]-1] < lastMaxNum) answer[A[i]-1] = lastMaxNum + 1;
            else answer[A[i]-1]++;

            maxNum = max(maxNum, answer[A[i]-1]);
        }
    }

    // 모든 요소가 최소한 max값 이상이 되어야함
    for(int i = 0 ; i < answer.size() ; i++){
        if(answer[i] < lastMaxNum) answer[i] = lastMaxNum;
    }

    return answer;
}