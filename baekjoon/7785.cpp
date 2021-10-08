/*
- enter이면 넣고, leave면 빼고 최종 남아 있는 사람 남기기
- set & 정렬 기준 만들기 
- 시간 초과 왜 ,, 왜나냐,,? => endl 쓰면 안된단다.
*/

#include <iostream>
#include <set>
#include <string>
using namespace std;

/*
// set operator 재정의 -> key 정렬
struct cmp {
    bool operator()(const string& a, const string& b) const {
        return a > b;
    }
};
*/

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    set<string> s;

    for(int i = 0 ; i < n ; i++){
        string name, op;
        cin >> name >> op;
        
        if(op == "enter"){
            s.insert(name);
        }else{
            s.erase(name);
        }

    }

    for(auto iter = s.rbegin() ; iter != s.rend() ; iter++){
        cout << *iter << endl;
    }
    return 0;
}