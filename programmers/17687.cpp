/*
- 문제가 이해 안되는디,, ㅎ,,
- 미리 구할 숫자 4개 -> !0 1 !1 0 !1 1 !1 0 0 => 아 이런식으로,,

- 미리 만들어두고,, 순서에 맞게 뽑아내는 방식,,? -> 숫자를 어디까지 만들어놔야할 지 모르겠긴한데
- 만들어가면서,, 체크,, <= 이 방식으로 했다. 내가 이해할 수 있는 , , 방식
*/
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>

using namespace std;

// n을 b진수로 나타내기
string change(int n, int b){
    string ret = "";
    
    if(n==0) return "0";
    while(n > 0){
        int r = n % b;
        
        if(r < 10){
            ret += (char)(r + '0'); // 숫자로 넣기
        }else{
            ret += (char)(r - 10 + 'A'); // A-F 로 넣기
        }
        
        n /= b;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}
string solution(int n, int t, int m, int p) {
    string answer = "";

    p -= 1; // 차례 계산 쉽도록
    
    int number = 0;
    int count = 0;
    int turn = 0;
    
    bool flag = true;
    
    while(flag){
        
        string s = change(number, n);

        for(auto c : s){
            
            if(count == t){
                flag = false;
                break;
            }   
            
            // 자기 차례라면

            if(turn % m == p){
                answer += c;
                count++;
            }
            
            turn++;
        }
        number++;
    }
    
    return answer;
}