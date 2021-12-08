// 나타나지 않은 가장 작은 자연수
// 전형적인 방법 : 소팅하고 끊어진 부분 찾기
// 테스트 케이스 : edge, empty(N >= 1 이라 없음)

#include <algorithm>
#include <vector>

using namespace std;
int expected = 1;

int solution(vector<int> &A) {
    
    sort(A.begin(), A.end());

    for(auto a : A){
        // 원하는 자연수가 나오면 다음 기댓값 ++
        if(a == expected) expected++;
        else if(a > expected) break;
    }
    return expected;
}