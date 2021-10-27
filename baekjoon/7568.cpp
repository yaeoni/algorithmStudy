/*
- 학생 N명의 몸무게와 키가 담긴 입력을 읽어서 각 사람의 덩치 등수를 계산하여 출력
- 1초에 N은 50까지 => 충분히 브루트 포스로 풀 수 있을 것 같은?!
- 만일 자신보다 더 큰 덩치의 사람이 k명이라면 그 사람의 덩치 등수는 k+1이 된다. => 이 방식 그대로 따라가면 될 것 같은디. 매 번 비교하기
*/
#include <iostream>

using namespace std;

int N;
int w, h;
typedef struct person{
    int weight;
    int height;
    int idx; // (입력 순서) 
}PERSON;

int answer[50]; // 답 기록
PERSON p[50];

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;

    for(int i = 0 ; i < N ; i++){
        cin >> w >> h;
        p[i] = {w, h, i};
    }
    for(int i = 0 ; i < N  ; i++){
        int k = 0;
        PERSON me = p[i];

        for(int j = 0 ; j < N ; j++){
            if(i == j ) continue; // 자기자신과 비교 X
            PERSON you = p[j];
            if(me.weight < you.weight && me.height < you.height) k++;
        }
        answer[i] = k+1;
    }
    for(int i = 0 ; i < N ; i++){
        cout << answer[i] << " ";
    }
    cout << "\n";
    return 0;
}