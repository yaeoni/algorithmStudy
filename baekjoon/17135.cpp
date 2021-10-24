/*
- 궁수 3명을 배치 / 각각의 턴마다 궁수는 적 하나를 공격할 수 있고, 모든 궁수는 동시에 공격
- 공격하는 적은 거리가 D이하인 적 중에서 가장 가까운 적 / 적이 여럿일 경우에는 가장 왼쪽에 있는 적을 공격 / 같은 적 공격 가능
- 궁수의 공격이 끝나면, 적이 이동한다. 적은 아래로 한 칸 이동
- 적이 제외되는 경우 : 공격받을 때 & 성에 도착했을 때

- 궁수의 공격으로 제거할 수 있는 적의 최대 수를 계산
- 두 위치 (r1, c1), (r2, c2)의 거리는 |r1-r2| + |c1-c2|

[나]
- 궁수는 성 아래 한 줄에 위치하면 된다.
- 도둑의 위치를 기억 해놔야한다! => 어디다 저장해둘까 ? 벡터밖에 떠오르지 않아,,
    - 매 턴마다 한 칸씩 내려야하고
    - 궁수에게 있어서 가장 가까운 위치를 계산해내야함

- 궁수는 어떻게 배치해야할까 -> 다 해보기(1초) -> mC3 해서 순서를 알아내야할 것 같은데! -> 했다
- 궁수의 공격 
    - 거리 D 이하의 적 중 가장 가까운 적 & 거리가 같다면 가장 왼쪽의 적 => 정말 하나하나 핸들링
    - 같은 적 공격가능 이므로 따로 표시하는 쪽으로 해야해

    ** 검색
    - 공격이 가능한 사람들(D 이하)를 다 모아놓고 -> 정렬(거리가 가장 가까운 순 & 왼쪽에 있는 순)
    - 표시 -> 삭제.

[결론]
- 도둑의 위치를 vector로 기억하면 인덱스 문제로 애매하게 삭제된다.
- 매번 map을 돌면서 좌표를 바꿔주는 식으로 방식을 바꿨다.
- 차근차근하게 생각하는게 되게 어려웠다 ㅠ 겁나 오래걸렸다 하..
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
// abs 위해서
#include <cmath>
#include <cstdlib>

using namespace std;

int N;
int M;
int D;
// 궁수가 위치한 곳까지 포함해서, row == N 일 때 적은 제외된다.
int ary_copy[16][16];
int ary[16][16];

typedef struct node{
    int row;
    int col;

    bool operator <(const node &a) const{
        if(row == a.row) return col < a.col;
        return row < a.row;
    }
}NODE; // map의 key로 구조체를 사용하려면 안에 operator 재정의가 필요하다


// 도둑 위치
map<NODE, int> kill;
vector<pair<NODE, int>> thieves;

// 궁수 위치
vector<NODE> archers;

bool isExist(){
    for(int i = 0; i < N ; i++){
        for(int j = 0 ; j < M ; j++){
            if(ary[i][j] == 1){
                return true;
            }
            
        }
    }
    return false;
}
// 정렬 기준 -> 가장 거리가 작게 / 가장 왼쪽의 놈(col!!!!값이 작은 순서대로)
bool comp(pair<NODE, int> a, pair<NODE, int> b){
    if(a.second == b.second){
        return a.first.col < b.first.col;
    }
    return a.second < b.second; // 거리가 작게
}

int getDistance(NODE a, NODE b){
    return abs(b.row - a.row) + abs(b.col - a.col);
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> D;
    
    int temp = 0;

    // 0 : 적 X
    // 1 : 적 O
    for(int i = 0 ; i < N ; i++){
        for(int j = 0; j < M ; j++){
            cin >> ary_copy[i][j];
        }
    }
    
    
    // 궁수 배치 조합 = mC3
    vector<int> num(M, 0);
    vector<int> sup(M, 1);
    for(int i = 0 ; i < num.size() ; i++) num[i] = i;
    for(int i = 0 ; i < num.size() - 3 ; i++) sup[i]=0;

    int answer = 0;
    int count =0;
    do{
        // 초기화
        int killNumber = 0;

        for(int i = 0 ; i < N ; i++){
            for(int j = 0; j < M ; j++){
                ary[i][j] = ary_copy[i][j];
            }
        }
        archers.clear();
        
        for(int i = 0; i < sup.size() ;i++){
            if(sup[i]){
                archers.push_back({N, num[i]});
            }
        }

        while(isExist()){ 
            for(auto archer : archers){
                // 범위 내의 적 구하기 및 표시
                for(int i = 0; i < N ; i++){
                    for(int j = 0 ; j < M ; j++){
                        if(ary[i][j]){
                            int distance = getDistance(archer, {i, j});

                            // 범위 내 적 push
                            if(distance <= D){
                                thieves.push_back({{i, j}, distance});
                            }
                        } 
                    }
                }
                // 0번째 -> 제거할 적
                if(thieves.size() != 0){
                    sort(thieves.begin(), thieves.end(), comp);
                    
                    NODE key = {thieves[0].first.row, thieves[0].first.col};
                    if(kill.find(key) == kill.end()){
                        kill.insert({key, 0});
                    }
                }
                thieves.clear();
            }
            
            // 제거
            for(auto it = kill.begin() ; it != kill.end() ; it++){
                killNumber += 1;
                ary[it->first.row][it->first.col] = 0;
            }
            kill.clear();

            //한 칸씩 내려가기(row 증가)
            vector<pair<int, int>> temp;
            for(int i = 0; i < N ; i++){
                for(int j = 0 ; j < M ; j++){
                    if(ary[i][j] == 1){
                        ary[i][j] = 0;
                        if(i+1 != N) temp.push_back({i+1, j});
                    }
                    
                }
            }
            for(auto t : temp){
                ary[t.first][t.second] = 1;
            }

        }
        answer = max(answer, killNumber);
        
    }while(next_permutation(sup.begin(), sup.end()));
    
    cout << answer << "\n";
    return 0;
}