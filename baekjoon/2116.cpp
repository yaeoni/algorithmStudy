/*
- 아래에서부터 1번 주사위, 2번 주사위, 3번 주사위, … 의 순서로 쌓는 것
- 서로 붙어 있는 두 개의 주사위에서 아래에 있는 주사위의 윗면에 적혀있는 숫자는 위에 있는 주사위의 아랫면에 적혀있는 숫자와 같아야 한다
    - 1번 주사위는 마음대로 놓을 수 있따
-  4개의 옆면 중에서 어느 한 면의 숫자의 합이 최대가 되도록 주사위를 쌓고자 한다 => 돌려서 확인
- 주사위의 전개도에서 A, B, C, D, E, F 의 순서로 입력된다.
- 주사위의 개수는 10,000개 이하

- backtracking 을 이용해 윗-아래 규칙이 안되면 return => 규칙이 안될 수가 없었다... 반드시 되는거였따... ㅎ하
- 처음 1은 6개의 경우가 다 되기때문에,,, 여기서 어떻게 backtracking을 구하나 했지만 한 번 계속 도전.

- 위 아래 -> 0 - 5 / 1 - 3 / 2 - 4
- 첫번째 주사위가 정해지면 위에는 결정된다! 쇽쇽 쇽 올리자.
- 옆면 계산은 어떻게할까. 미춌따 => 각 주사위를 위 아래를 고정한 채 옆으로 90도, 180도, 또는 270도 돌릴 수 있다.
    => 그냥 그때마다 매 옆면의 최대값을 구하면 되는 것임
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
int dices[10000][7];
int up[6];


int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // 주사위 입력받기
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        cin >> dices[i][0] >> dices[i][1] >> dices[i][2] >> dices[i][3] >> dices[i][4] >> dices[i][5];
    }

    // 윗면 매칭
    up[0] = 5;
    up[1] = 3;
    up[2] = 4;
    up[3] = 1;
    up[4] = 2;
    up[5] = 0;
    
    int answer = 0;

    for(int i = 0 ; i < 6 ; i ++){
        int upside = dices[0][i]; // 첫번째 윗면 결정

        int maxSum = 0; // 해당 면의 최댓값
        int numt = 0; // 더할 값

        // 위아래 제외하고 옆면 최댓값 구하기
        for(int temp = 0; temp < 6 ; temp++){
            if(temp != i && temp != up[i]){
                numt = max(dices[0][temp], numt);
            }
        }

        maxSum += numt;

        // 다음 순서의 주사위 부터
        for(int j = 1 ; j < n ; j++){

            numt = 0; // 재활용
            for(int side = 0 ; side < 6 ; side++){
                if(dices[j][side] == upside){

                    // 이전 주사위의 upside와 같은 면이라면
                    upside = dices[j][up[side]];

                    for(int temp = 0; temp < 6 ; temp++){
                        if(temp != side && temp != up[side]){
                            numt = max(dices[j][temp], numt);
                        }
                    }
                    maxSum += numt;
                    
                    break;
                }
            }
        }
        answer = max(answer, maxSum);
    }

    cout << answer << "\n";
    return 0;
}