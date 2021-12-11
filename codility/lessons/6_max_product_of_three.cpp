/*
- non-empty array A
- 3개 뽑아서 가장 maximal한 곱의 값
- 순서에 상관 없이 3개를 뽑는다 = 조합
*/

#include <vector>
#include <algorithm>
#include <iostream>
#include <limits.h>

using namespace std;

int answer = INT_MIN;

int non_solution(vector<int> &A) {
    int aSize = A.size();

    vector<int> comp(A.size(), 0);
    // 3개를 뽑을 거니까 끝에 1을 3개 삽입
    for(int i = aSize - 1 ; i > (aSize-1) - 3 ; i--){
        comp[i] = 1;
    }

    int cSize = comp.size();
    do{
        // 조합 뽑기
        int temp = 1;
        for(int i = 0 ; i < cSize ; i++){
            if(comp[i]){
                temp *= A[i];
            } 
            
        }
        answer = max(answer, temp);
    }while(next_permutation(comp.begin(), comp.end()));
    
    return answer;
}

/*
- 조합으로 3개 뽑아서 모든 경우의 수를 체크했더니 시간 초과 에러가 났다.
- 음수간 곱셈의 고려 (= 음수 2개, 양수 1개)
- 이렇게 하면 o(nlog(n))만에 해결가능이다. / sort덕분에
- 조금 더 쉽게 생각했었어도 됐는데... 후 슬프다..
*/
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int answer = INT_MIN;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int aSize = A.size() - 1;
    answer = max(A[0]*A[1]*A[aSize], A[aSize]*A[aSize-1]*A[aSize-2]);
    
    return answer;
}