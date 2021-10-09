/*
- 최종 점수 가장 낮게 = 매 번 더할 두 카드의 값이 제일 작은 값이면 된다!
- priority queue (min heap 활용하기)

- n은 2 이상임
- int 형으로 했더니 틀렸다. long-long으로 가야한다...
*/

#include <iostream>
#include <queue>

using namespace std;

int main(void){

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<long long>> pq; // min heap 선언

    for(int i = 0 ; i < n ; i ++){
        long long temp;
        cin >> temp;
        pq.push(temp);
    }

    for(int i = 0 ; i < m ; i++){
        // 가장 작은 값 두개 빼기
        long long first = pq.top();
        pq.pop();

        long long second = pq.top();
        pq.pop();

        long long add = first + second;
        pq.push(add);
        pq.push(add);
    }

    long long sum = 0;
    while(!pq.empty()){
        long long add = pq.top();
        pq.pop();
        sum += add;
    }

    cout << sum << "\n";
    return 0;
}