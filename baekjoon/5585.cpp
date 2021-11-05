/*
- 수업때 진행한 것 쇽쇽. 풀어보기

- 500, 100, 10, 5, 1엔  => 각 요소들은 배수형태
- 거스름돈 개수가 가장 적게 잔돈 주기.

=> 각 요소들이 배수 형태고, 가장 적은 거스름돈으 주어야하므로 그리디하게 가능!
*/

#include <iostream>

using namespace std;

int money;
int answer = 0;

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> money; // 지불할 돈

    int left = 1000 - money; // 거스름돈

    while(left){
        if(left - 500 >= 0){
            left -= 500;
            answer++;
        }else if(left - 100 >= 0){
            left -= 100;
            answer++;
        }else if(left - 50 >= 0){
            left -= 50;
            answer++;
        }else if(left - 10 >= 0){
            left -= 10;
            answer++;
        }else if(left - 5 >= 0){
            left -= 5;
            answer++;
        }else if(left - 1 >= 0){
            left -= 1;
            answer++;
        }
    }

    cout << answer << "\n";
    return 0;
}