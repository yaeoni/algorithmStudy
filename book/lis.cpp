#include <iostream>
#include <vector>
using namespace std;


int ary[501];
int cache[100];

// 완전탐색  O(2^n)
// main에서 vector로 받아야함
int lis(const vector<int>& A){
    if(A.empty()) return 0;

    int ret = 0;
    for( int i = 0; i < A.size() ; i++){
        vector<int> B;

        for( int j = i+1; j < A.size() ; j++){
            // 기준점보다 큰 것들 먼저 담음
            if( A[i] < A[j])
                B.push_back(A[j]);
        }
        // lis(B) + 1 하면서 증가수열 개수를 늘려가는 것
        // B가 존재한다면 +1 / 재귀로 호출되면서 계쏙 +1 +1 ... 하게 되는 것 
        ret = max(ret, 1+lis(B)); 
    }
    return ret;
}


/* Dynamic programming 1 */
// 입력값을 좀 더 간단하게 만들기, O(n^2)
// 배열로 입력을 받고, 배열 위치 하나씩 순회하면서 최대의 길이 수로 찾아줘야함.
int lis2(int start, int size){
    int& ret = cache[start];
    if( ret != -1) return ret;

    // 항상 ary[start]는 존재하기에 최소 길이는 1
    ret = 1;
    for( int next = start +1 ; next < size ; next++){
        if(ary[start] < ary[next])
            ret = max(ret, lis2(next, size) +1);
    }

    return ret;
}
int main(void){

    int caseCount;
    cin >> caseCount;

    for(int i = 0 ; i< caseCount ; i++){
        int num;
        cin >> num;

        for(int j = 0 ; j < num ; j++){
            cin >> ary[j];
        }
        
        

    }


    return 0;
}