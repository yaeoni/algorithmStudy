#include <unordered_map>

using namespace std;

// 항상 1부터 N 인거면, N을 초과하는 수가 나오면 틀린 답.
// 연속적인지 체크
// 중복 안된다.
int solution(vector<int> &A) {
    unordered_map<int, int> um;

    for(auto a : A){
        if(a > A.size()) return 0;
        if(um.find(a) != um.end()){
            // 이미 존재한다 = 중복
            return 0;
        }else{
            um.insert({a, 1});
        }
    }

    if(um.size() == A.size()) return 1;
    else return 0;
}