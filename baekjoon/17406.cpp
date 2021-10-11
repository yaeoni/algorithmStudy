/*
- 정사각형 내부 요소 돌리기
- 순서 임의 지정(순열, next_permutation 활용)
- 여러 순서가 존재하니까 기존 배열을 기억해야함.(복사로 하기)

- 정사각형 돌리기 로직 -> 하나하나 돌리면 되는데,,
    - 젤 큰 정사각형부터 속의 정사각형까지 돌리기
    - 정사각형 시작&끝점 (r-s, c-s) / (r+s, c+s)  | (r,c)는 중심점
    - 속에 s개의 정사각형만큼 돌려주어야하는것이다..... 요건 이해가 잘 안가지만 또 가는거같음...

** 윽!! 이어서 돌리면 안됐잖아아아아ㅡ아으아
*** 정말,,,,, 정말,,,,,,,힘들었,, 다,,,
*/

#include <iostream>

#include <climits> // 각 타입 맥스값위해서,, => 그냥 limits가 아니라 climits로 활용해야한다.
#include <algorithm>
#include <vector>

using namespace std;

// 배열의 값 구하기
int getValue(vector<vector<int> > ary, int n, int m){
    int ret = INT_MAX;
    for(int i = 0 ; i < n ; i++){
        int temp = 0;
        for(int j = 0 ; j < m ; j++){
            temp += ary[i][j];
        }
        ret = min(ret, temp);
    }
    return ret;
}

void rotate(vector<vector<int> >& v, int r, int c, int s){
    // 중심점(r,c)부터 하나씩 늘려가면서!
    for(int i = 1 ; i <= s ; i++){
        int x = r - i;
        int xx = r + i ;
        int y = c - i ;
        int yy = c + i;
        
        //cout << "(" <<x<<", "<<y<<")"<<" / "<< "(" <<xx<<", "<<yy<<")"<< endl;
        
        // 시작점(왼쪽 상단)
        int temp = v[x][y];

        // 왼쪽 (위로 땡겨주기)
        for(int k = x ; k < xx ; k++){
            v[k][y] = v[k+1][y];
        }

        // 아래쪽
        for(int k = y ; k < yy ; k++){
            v[xx][k] = v[xx][k+1];
        }

        // 오른쪽
        for(int k = xx ; k > x ; k--){
            v[k][yy] = v[k-1][yy];
        }

        // 위쪽
        for(int k = yy ; k > y ; k--){
            v[x][k] = v[x][k-1];
        }

        // 채워주기
        v[x][y+1] = temp;
        
    }
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m, k;
    cin >> n >> m >> k;

    // 배열
    vector<vector<int> > ary(n, vector<int>(m, 0));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            int temp;
            cin >> temp;
            ary[i][j] = temp;
        }
    }

    // 회전 정보
    vector<vector<int> > rotateInfo(k);
    // 순서 벡터(순열 돌릴 것)
    vector<int> index; 
    for(int i = 0 ; i < k ; i++){
        int r, c, s;
        cin >> r >> c >> s;

        // 1,1 로 시작하므로 배열 값 맞춰주기
        rotateInfo[i].push_back(r-1);
        rotateInfo[i].push_back(c-1);
        rotateInfo[i].push_back(s);

        index.push_back(i); // (자동)오름차순 삽입
    }
    
    // 회전순서 구하기 => 내부에서 정사각형을 돌리고, min 값을 얻으면 되겠다.
    int answer = INT_MAX;
    do{
        // 입력받은 배열 복사
        vector<vector<int> > temp(n, vector<int>(m));
        temp = ary;
        for(auto it = index.begin(); it != index.end() ; it++){
            int r = rotateInfo[(*it)][0];
            int c = rotateInfo[(*it)][1];
            int s = rotateInfo[(*it)][2];

            rotate(temp, r, c, s);
        }
        // getValue 콜 (call by reference 방식!)
        int isMin = getValue(temp, n ,m);
        answer = min(answer, isMin); 
        
    }while(next_permutation(index.begin(), index.end()));

    cout << answer << "\n";
    return 0;
}