/*
- distinct value 개수 찾기
- set 처리하고 개수 세면 되는거 아닌가 ,,?
*/
#include <vector>
#include <set>

using namespace std;

set<int> s;
int answer = 0;

int solution(vector<int> &A) {
    int aSize = A.size();
    if(aSize == 0) return 0;

    for(auto a : A){
        s.insert(a);
    }
    
    answer = s.size();
    return answer;
}