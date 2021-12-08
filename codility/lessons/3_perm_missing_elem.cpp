#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {

    if(A.size() == 0) return 1;

    sort(A.begin(), A.end());
    for(int i = 1 ; i <= A.size() ; i ++){
        if(i != A[i-1]) return i;
    }

    return A.size() +1 ;
}
