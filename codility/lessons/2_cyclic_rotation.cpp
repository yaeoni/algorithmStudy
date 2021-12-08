// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    if(A.size() == 0 || A.size() == K){
        return A;
    }

    deque<int> dq;
    vector<int> answer;

    for(auto a : A) dq.push_back(a);
    for(int i = 0; i < K ; i++){
        dq.push_front(dq.back());
        dq.pop_back();
    }

    for(auto v: dq){
        answer.push_back(v);
    }
    return answer;
}