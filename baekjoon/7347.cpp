
/*
- 테케(길이 / 흰-검 배열) => 한줄로 이뤄짐
- 수열 최대길이가 30 => 길진 않다.

- 모을 수 있는 지 없는지 판단!!

[고민]
- 어떤 자료구조에 넣을 것인가
- 좌, 우 flip을 어떤식으로 수행하는가,,,
- 규칙이 있을 것 같아서 찾아보곤있는데 쉽지 않ㄷr
    - 1 0 1 0 있으면 안된다고 생각했는데 것도 아니군


[검색] (https://gdon9031.tistory.com/11)
- 짝/홀로 분리해서 규칙 찾기 -> 어케 알아냄 ㅋ;;
    - 홀수는 언제나 가능 
    - 짝수 체크
- filp을 시도할 때 홀수는 홀수자리로, 짝수는 짝수자리로만 이동 가능(OK)

- 어떤 색을 연속적으로 모을 수 있다 
    = (해당 색의)짝수 번호를 가진 디스크의 수와 홀수 번호를 가진 디스크의 수가 2이상 차이나지 않는다는 것
    => 이걸 어떻게 알지,,,,?ㅋ ㅋ,ㅋ,ㅋ,?
    => 하나의 색이 연속으로 모이려면 홀-짝 이어져야한다.
    => 개수가 2개 이상 차이나버리면 빈 칸이 생기게 되는것.

[결론]
- 규칙을 찾아봐야지 했는데, 잘 생각나지 않았고 ㅠ 앞으로 생각할 수 있을까 싶네,,
- 그래도 이해했다는 거에 의미를 두기로 했다.
*/
#include <iostream>
#include <cstdlib>
// #include <cmath> => double이나 float형의 절대값 계싼
using namespace std;
int ary[30];

// 검은색(1)을 모은다고 생각 
bool canSplit(int n){

    // 홀수인 경우에는 언제나 맞출 수 있음
    if(n%2) return true;
    
    int even = 0;
    int odd = 0;

    for(int i = 0 ; i < n ; i ++){
        if(ary[i]){
            if(i%2) odd++;
            else even++;
        }
    }
    if(abs(even-odd) < 2) return true;
    return false;
}
int main(void){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; 
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        int num;
        cin >> num;

        for(int j = 0 ; j < num ; j++) cin >> ary[j];
        if(canSplit(num)) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}