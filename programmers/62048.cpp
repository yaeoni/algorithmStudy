/*
- 문제에 주어진 풀이는 대각선을 잘랐을 때 사용할 수 없는 정사각형 개수를 빼는 것
- 문제 기준으로 그리면 빠지는 직사형의 개수 규칙이 잘 안보임 
	-> 잘린 직각삼각형 기준으로 보면 어떨까
	-> 이건 뭐 규칙도 모르겄따
- 차분히 그려보기 .. 그래도 모르겠음 
[검색!]
- 반복되는 블럭 패턴 찾기 -> 규칙 찾기가 핵심이었따! / 해당 패턴은 최대공약수의 수 만큼 나타난다.
- 하나의 패턴 속에서 빠지는 정사각형 개수 (w/최대공약 + h/최대 공약) -1
- 반복되는 패턴 속에서 빠지는 정사각형의 개수 = 하나의 패턴에 대해 * 최대공약수 하면 된다. 
    : (W + H) - 최대공약수
- 규칙을 찾는게 쉽지는 않지만, 규칙 찾아!! 하는 문제니까 좀 더 열심히 찾아보자,,, 가까이서도 봤다가, 멀리서도 봤다가!
*/

using namespace std;

//최대공약수 구하는 함수 = 유클리드 호제법
/*
 f(a,b)= gcd(a,b)일때
 a mod b = 0 이면 f(a,b) = b
 a mod b != 0 이라면 f(a,b) = f(b, a mod b)
*/
int gcd(int w, int h){
    int mod = w%h;
    while(mod > 0){
        w = h;
        h = mod;
        mod = w%h;
    }
    return h;
}

long long solution(int w,int h) {
    long long answer = 1;
    
    // 전체 사용 가능한 직사각형 = (전체 직사각형) - (w+h - 최대공약수)
    long long total = (long long)w*(long long)h; // long long 변환을 해줬어야 했다!
    long long sub = w+h - gcd(w,h);
    
    answer = total - sub;
    return answer;
}