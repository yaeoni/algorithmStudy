#include <iostream>
#include <unordered_map>

using namespace std;

// 1부터 X 까지 다 채워졌는가...
// unordered_map을 이용해서 X보다 큰 수는 버리고,
// 그 아래가 X만큼 채워졌는지 확인
int solution(int X, vector<int> &A) {
    unordered_map<int, int> um;

    for(unsigned int i = 0 ; i < A.size() ; i++){
        if(A[i] > X) continue;

        um.insert({A[i], 1});
        if(um.size() == X) return i;
    }

    return -1;
