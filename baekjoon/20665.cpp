
/*
- 규칙
1. 사람들은 가장 가까이에 앉아있는 사람이 가장 먼 자리를 선호한다. 만약 독서실을 이용하는 사람이 없다면 좌석번호 1번 자리를 가장 선호한다.
2. 1번 규칙으로 비교할 수 없다면, 가장 먼 좌석들 중에서 좌석 번호가 가장 작은 자리를 선호한다.

- 독서실은 09:00 부터 21:00 까지 운영 / 자신이 선호하는 자리를 얼마나 이용할 수 있는지 계산해보고자 한다.
- 좌석의 개수 N, 독서실 예약자 수 T, 민규가 좋아하는 좌석 번호 P (1 ≤ N ≤ 100, 1 ≤ T ≤ 500, 1 ≤ P ≤ N)
- T개의 줄에 입실 시간, 퇴실 시간이 HHMM HHMM 형태로 입력

- 독서실 예약이 같은 시각에 시작된다면 짧은 이용시간을 가진 사람을 먼저
- 예약자들이 좌석이 없어서 못 앉는 상태는 존재하지 않는다 => 자리만 알 수 있으면 된다.


[필요]
- 입력받은 입/퇴실 시간 정렬
    - (정렬기준) 1. 입실시간 2. 퇴실시간 (오름차순)
    - 사용할 자료구조 pair<string, string>
        - 시간, 분을 나눠야한다면  /100, mod 100으로 자르기

- ** 시간-자리구조를 어떻게 설계할 것인가,,? **
    - 09~21사이에서 모든 입/퇴를 찍어서 나누기
    - 어떻게 찍어나눌건데,, 으음 머리 아퍼,, 으음 ㄴㅏ 정말모르겠어


[도움] - pair는 int로!
- 1. han 선생
    - 여러가지 자료 구조 이용
    - 전체 시간 - 사람들이 P에 앉아있던 시간 으로 답 도출
    - 퇴실 시간 관리하는 pq따로 
*/
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int N, T, P;
typedef pair<int, int> reserve;

// 좌석 규칙(번호, 거리)
// 거리(second)가 멀게, 거리가 같다면 번호가 작게(first)
bool rule(pair<int, int> a, pair<int, int> b){
    if(a.second == b.second){
        return a.first > b.first;
    }
    return a.second < b.second;
}

// 전체적으로 오름차순 정렬
bool cmp(reserve a, reserve b){
    if(a.first == b.first){
        return a.second < b.second; 
    }
    return a.first < b.first;
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<reserve> list; // 예약 정보 리스트
    vector<reserve> log; // 좌석 P 이용 로그

    priority_queue<reserve, vector<reserve>, greater<>> leave; // 퇴실 시간 기록, 퇴실이 가장 빠른 순(시간, 자리)
    map<int, int> seat; // 좌석 정보(좌석번호, (누군가 앉아있는) 가장 가까운 좌석과의 거리)

    cin >> N >> T >> P;

    while(T--){
        int enter, exit;
        cin >> enter >> exit;
        
        list.push_back({enter, exit});
    }
    
    // 입-퇴실 시간 정렬
    sort(list.begin(), list.end());
    
    // seat 초기화
    for(int i = 1 ; i <= N ; i++){
        seat[i] = N;
    }

    // 예약 정보 돌면서 현재 시간 change
    for(int i = 0 ; i < list.size() ; i++){
        int curTime = list[i].first;
        int leaveTime = list[i].second;

        while(1){
            // 퇴장 할 사람이 없는 경우 Break
            if(leave.empty()) break;

            // 퇴장해야 한다 = 현재 시각이 퇴장 시각을 넘었다.
            // 퇴장 할 사람이 있다면 -> 퇴장 시키고 기존 좌석 정보 업데이트
            if(leave.top().first <= curTime){

                // 좌석 번호 갖고 퇴장시킴
                int leaveNum = leave.top().second;
                leave.pop();

                // 범위 밖으로 초기화(= 좌우 아무도 없는 상황 가정)
                int left = 0;
                int right = N+1;

                // 퇴장 좌석 기준 좌 우로 가장 가까운 좌석 확인 -> 업데이트

                // 퇴장 좌석 기준 왼쪽 확인
                for(int j = 1 ; j < leaveNum ; j++){
                    if(seat[j] == 0){
                        left = j;
                    }
                }
                // 오른쪽 확인
                for(int j = N ; j > leaveNum; j--){
                    if(seat[j] == 0){
                        right = j;
                    }
                }


                // 양 옆에 있을 때
                if(left != 0 && right != N+1){
                    for(int j = left ; j <= right ; j++){
                        // 좌석 오른쪽 왼쪽 중 가까운 위치 정보 업데이트
                        seat[j] = min(j-left, right-j);
                    }
                }
                // 왼쪽에만 있을 때
                else if(left != 0 && right == N+1){
                    for(int j = left ; j < right ; j++) seat[j] = j - left; 
                }
                // 오른쪽에만 있을 때
                else if(left == 0 && right != N+1){
                    for(int j = left+1 ; j <= right ; j++) seat[j] = right-j; 
                }
                // 아무도 없을 때 -> 다시 초기화
                else if(left == 0 && right == N+1){
                    for(int j = 1 ; j <= N ; j++) seat[j] = N;
                }
            }else{
                // 현재 시간이 퇴장 시간 전이다.
                break;
            }
        }

        // 현재 예약자가 앉을 자리
        // Seat 속에서 다른 좌석들과 가장 멀리 떨어져 있는 좌석
        int seatNum = max_element(seat.begin(), seat.end(), rule)->first;

        // 퇴장 정보 등록(정렬 기준 : 시간)
        leave.push({leaveTime, seatNum});
        
        // 좌석 배정
        seat[seatNum] = 0;

        // 좌석 정보 업데이트
        // 가장 가까이에 있는 좌석에만 영향을 끼침(좌,우)
        // 왼쪽
        for(int j = seatNum-1 ; j > 0 ; j--){
            if(seat[j]==0) break;
            seat[j] = min(seat[j], seatNum - j);
        }

        // 오른쪽
        for(int j = seatNum+1 ; j <= N ; j++){
            if(seat[j]==0) break;
            seat[j] = min(seat[j], j - seatNum);
        }

        // 관리자 자리에 앉았을 경우 log에 남기기
        if(seatNum == P) log.push_back({curTime, leaveTime});
    }

    // 0900~2100 -> 12시간 -> 720분
    // 720 - (사람들이 관리자의 자리에 앉던 시간)
    int usedTime = 0;

    // 로그에서 exit-enter 분  계산하기.
    for(int i = 0 ; i < log.size() ; i++){
        int en = log[i].first;
        int ex = log[i].second;

        int enHour = en / 100; // 앞에 두자리
        int enMin = en % 100; // 뒤에 두자리

        int exHour = ex / 100;
        int exMin = ex % 100;

        usedTime += (exHour * 60 + exMin) - (enHour * 60 + enMin);  

    }
    cout << 720 - usedTime;
    return 0;
}