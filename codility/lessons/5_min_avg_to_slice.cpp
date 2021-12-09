// c++ 나누기 소수점 필요할 때엔 앞에 double로 캐스팅하기
// 수학... ㅎㅎ 에횽 빨리 포기하길 잘했다..
#include <vector>
using namespace std;

int solution(vector<int> &A) {
    int answer = 0;
    double minAvg = (A[0] + A[1]) / 2;

    int aSize = A.size();
    for(int i = 2 ; i < aSize ; i++){

        // 3개 요소 체크
        double tempAvg = (A[i] + A[i-1] + A[i-2]) / (double)3;
        if(tempAvg < minAvg){
            answer = i-2;
            minAvg = tempAvg;
        }

        // 2개 체크
        tempAvg = (A[i] + A[i-1]) / (double)2;
        if(tempAvg < minAvg){
            answer = i-1;
            minAvg = tempAvg;
        }
    }

    return answer;
}