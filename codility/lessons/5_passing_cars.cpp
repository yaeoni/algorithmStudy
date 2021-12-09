/*
- edge : 모두 east거나, 모두 west 일 때.
*/
#include <iostream>
#include <vector>
using namespace std;

#define MAX 1000000000

int passing = 0;
int east = 0;

int solution(vector<int> &A) {
    for(auto a : A){
        if(a == 0) east++;
        else{
            // east 방향이 있었을 때에만
            if(east){
                passing += east;
                if(passing > MAX) return -1;
            }
        }
    }
    
    return passing;
}
