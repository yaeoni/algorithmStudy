#include <cmath>
#include <math.h>
#include <algorithm>
#include <limits.h>
#include <iostream>

using namespace std;
int answer = INT_MAX;

int solution(vector<int> &A) {
    // 합계 계산
    int all = 0;
    for(auto a : A) all += a;

    int first = 0;
    int second = all;

    unsigned int p = 1;

    while(p < A.size()){
        first += A[p-1];
        second -= A[p-1];

        int diff = abs(second - first);
        answer = min(answer, diff);
        p++;
    }
    return answer;
}
