#include <vector>
#include <algorithm>

using namespace std;

bool isTriplet(vector<long long> &v){
    if((long long)(v[0] + v[1]) > v[2] && 
        (long long)(v[0] + v[2]) > v[1] && 
        (long long)(v[1] + v[2] > v[0])){

        return true;
    }
    return false;
}

int solution(vector<int> &A) {

    int aSize = A.size();
    if(aSize < 3) return 0;

    vector<int> comp(A.size(), 0);
    // 3개를 뽑을 거니까 끝에 1을 3개 삽입
    for(int i = aSize - 1 ; i > (aSize-1) - 3 ; i--){
        comp[i] = 1;
    }

    vector<long long> temp;
    int cSize = comp.size();
    do{
        // 조합 뽑기
        temp.clear();
        for(int i = 0 ; i < cSize ; i++){
            if(comp[i]){
                temp.push_back((long long)A[i]);
            } 
            
        }
        if(isTriplet(temp)) return 1;
    }while(next_permutation(comp.begin(), comp.end()));
    

    return 0;
}

/*
- triangular triplet이 "있으면" 1, 없으면 0
- 3 값 중 더한 값이 다른 하나 보다 클 때
- 원소 값의 range가 int를 벗어남 -> long long 사용하기.

- 이건 정말 모든 케이스의 3가지를 뽑아야하는거아닌가! 조합아닌가!! 재도전... 도전하지말자..
- 있으면 1 자체니까 바로 끝내버리면 된다. 미띤
- 음수도 있으니까. 있으면 바로 끝내기
=> 아니다!! 아니야!!!!!

"풀이의 핵심은 배열을 정렬한 상태에서 인접한 세개의 인덱스간의 비교만 진행하면 됩니다."
- 이미 배열이 정렬 되어있기 때문에 / 앞에 2개 & 가장 큰 값 만 비교하면 나머지는 충족..
- 조합은 삼각형의 개수를 알아내라 할 때만 하면 되겠다...위로위로
*/
#include <vector>
#include <algorithm>

int solution(vector<int> &A) {

    int aSize = A.size();
    if(aSize < 3) return 0;

    sort(A.begin(), A.end());

    for(int i = 0 ; i < aSize-2 ; i++){
        if((long)A[i] + (long)A[i+1] > A[i+2]) return 1;
    }
    
    return 0;
}