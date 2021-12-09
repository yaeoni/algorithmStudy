/*
- 문자열 상에서 해당 문자가 얼마나 나왔는지 누적 카운트.
- 시작과 끝점사이의 알파벳 누적 카운트가 변했다면 해당 문자열엔 그 알파벳이 포함된 것
- 0개부터 시작했다는 것을 알기 위해 column수를 하나 더 늘리기
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> answer;

// A C G T
int counter[4][100001] = {0};

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

    int sSize = S.size();
    for(int i = 1 ; i <= sSize ; i++){
        if(S[i-1] == 'A'){
            counter[0][i] += 1;
        }else if(S[i-1] == 'C'){
            counter[1][i] += 1;
        }else if(S[i-1] == 'G'){
            counter[2][i] += 1;
        }else{
            counter[3][i] += 1;
        }
        // 이전 누적 값 더해주기
        for(int j = 0 ; j < 4 ; j++){
            counter[j][i] += counter[j][i-1];
        }
    }
    int qSize = P.size();
    
    for(int i = 0 ; i < qSize ; i++){
        int startIdx = P[i];
        int endIdx = Q[i] + 1;
        if(startIdx == endIdx){
            if(S.at(startIdx) == 'A') answer.push_back(1);
            else if(S.at(startIdx) == 'C') answer.push_back(2);
            else if(S.at(startIdx) == 'G') answer.push_back(3);
            else answer.push_back(4);
        }else{
            if(counter[0][startIdx] != counter[0][endIdx]) answer.push_back(1);
            else if(counter[1][startIdx] != counter[1][endIdx]) answer.push_back(2);
            else if(counter[2][startIdx] != counter[2][endIdx]) answer.push_back(3);
            else answer.push_back(4);
        }

    }
    

    return answer;
}