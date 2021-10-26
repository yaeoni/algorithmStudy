#include <iostream>
#include <algorithm>
#include <deque>
#include <stack>

using namespace std;

deque<char> front;
deque<char> back;

string input;
int M;
char command;
char add;

int cursor;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> input;

    for(auto c : input) front.push_back(c);

    cin >> M;

    while(M--){
        cin >> command;

        if(command == 'L'){ // 커서 왼쪽으로
            if(front.empty()) continue;
            back.push_front(front.back());
            front.pop_back();
        }else if(command == 'D'){ // 커서 오른쪽으로
            if(back.empty()) continue;
            front.push_back(back.front());
            back.pop_front();
        }else if(command == 'B'){ // 커서 왼쪽 문자 삭제
            if(front.empty()) continue;
            front.pop_back();
        }else{ // 문자 추가
            cin >> add;
            front.push_back(add);
        }
    }

    string answer;
    while(!front.empty()){
        answer += front.front();
        front.pop_front();
    }

    while(!back.empty()){
        answer += back.front();
        back.pop_front();
    }

    cout << answer << "\n";
    return 0;
}