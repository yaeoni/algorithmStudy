/*
- A 를 항상 나눌 수 있는 수로 만들고 answer = 1 세팅
    - 이때 B를 넘으면 범위 초과(return 0)
- 해당 답 정확도 85 %
- For example, for the input [101, 123456789, 10000] the solution returned a wrong answer (got 12346 expected 12345).
- 아예 이 방법이 아닌가..

앗.. 바보.. 그 사이에서 볼 게 아니라 양 옆 끝 값의 몫값에서 뺴면돼.. 와.. 하.... 현타!
*/
using namespace std;

int answer = 0;
int non_solution(int A, int B, int K) {
    if(A % K){
        A += A % K;
        if(A > B) return answer;
    }
    answer++;
    return answer + (B-A)/K;
}

// h ㅏ .. 힘내자아!
using namespace std;
int solution(int A, int B, int K) {
    int a = A / K;
    int b = B / K;

    int answer = b - a;
    
    if(A%K == 0) answer++;
    return answer;
}