/*
- n 퀸 갈겨보자

- 같은 대각선이다 = 위치 A, B 일 때 / (A 행 - B 행 )== (A 열 - B 열)

- 그때 이제, 하나의 배열로도 풀 수 있다 했따.
    - index = 행 / 값 = 열
    - index 가 행이기 때문에 따로 행 체크는 안해도 된다.
- 가지치기의 접목
*/

#include <iostream>

// 절대값 위해서
#include <cmath>
#include <math.h>

using namespace std;

int ary[15];
int N;
int answer = 0;

bool check(int row){
    // 상위 행이 공격할 수 있는가 체크
    for(int i = 0 ; i < row ; i++){
        // 같은 열에 있는가
        if(ary[i] == ary[row]){
            return false;
        }

        // 대각선에 있는가
        if(abs(row - i) == abs(ary[i] - ary[row])){
            return false;
        }
    }

    // 해당 자리에 퀸을 놓을 수 있다
    return true;
}

void queen(int row){
    if(row == N){
        answer += 1;
        return; // 끝 행까지 왔으므로 마무리
    }
    // 모든 열을 돌면서 검사
    for(int i = 0 ; i < N ; i ++){
        ary[row] = i; // 퀸을 둔다.

        // 해당 열이 괜찬흥ㄴ가 검사
        if(check(row)){
            queen(row+1);
        }
    }
}
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    queen(0);
    cout << answer << "\n";

    return 0;
}