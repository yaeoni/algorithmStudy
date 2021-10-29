/*
-  크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 프로그램
- 주어지는 정수의 절댓값은 100,000을 넘지 않는다.
- N <= 20, 시간 제한 2초 => 충분 충분,,

[나]
- 크기가 양수일 때 -> 1, 2, 3, 4,,, 수열의 크기 별로 매번 검사하기?
    => *** 부분 수열은 마치 부분집합과도 같은 개념이였다...(어떤 규칙이 있다는게 다르지만, 여기서는 그냥,,이네.)
    => 아오, 그러면 해당 인덱스의 수를 포함하거나. 안하거나. 로 모든 경우를 따지면 된다.

- 투포인터를 이용해서 어떻게 안될까?
    => 안된다. 투포인터는 배열의 원소가 다 자연수일 때 가능!(start가 늘어나면 원소 값을 빼주고 / end가 늘어나면 원소 값을 더해주는 방식이라.)

- 이게 원래 문제 이름은 부분집합의 합 이구나..
    => 뭐가 틀렸는지 보니까 "크기가 양수인" 부분 집합이므로, S==0이면 맨 처음 dfs 에서 ans++에서 걸린다.
    => 따라서 크기 제한도 걸어줘야한다!
*/
#include <iostream>

using namespace std;

int N, S, answer;
int ary[20];

void dfs(int index, int sum, int len){
    if(index >= N){
        if(sum == S && len > 0) answer++;
        return;
    }
    dfs(index+1, sum + ary[index], len+1); // 해당 원소 포함했을 때
    dfs(index+1, sum, len); // 포함하지 않았을 때
}

int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    answer = 0;

    cin >> N >> S;

    for(int i = 0 ; i < N ; i++){
        cin >> ary[i];
    }

    dfs(0, 0, 0);
    cout << answer << "\n";
    return 0;
}