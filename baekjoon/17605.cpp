#include <iostream>
#include <vector>

using namespace std;

// 나 -> 완전 탐색
int canPalindrome(string input){
    for(int i = 0 ; i < input.size() / 2 ; i++){
        if( input[i] != input[input.size()-i-1] ) return 0;
    }
    return 1;
}

int isPalindrome(string& input){
    
    for(int i = 0 ; i < input.size() / 2 ; i++){
        if( input[i] != input[input.size()-i-1] ){
            // 한 글자씩 빼오기 이건 한번만 돌아야돼.
            string originLeft = input;
            string originRight  = input;

            string left = originLeft.erase(i,1);
            string right = originRight.erase(input.size()-i-1, 1);

            // 한 글자 빼온게 회문인지 '한 번만' 확인하면 된다! 내가 원래 했던건 계속 해서 유사회문도 확인하는거.. 그럼 메모리 초과 
            int ret = max( canPalindrome(left), canPalindrome(right));
    
            // 한글자 빼서 회문이 된 경우엔 = 유사회문
            if(ret == 1) return 1;

            return 2;
        }
    }
    return 0;

}

int main(void){
    
    int caseCount;
    cin >> caseCount;

    vector<string> v;

    for(int i = 0; i < caseCount ; i++){
        string s;
        cin >> s;
        v.push_back(s);
    }

    for(int i = 0 ; i< caseCount ; i++){
        cout << isPalindrome(v[i]) << endl;
    }
 

    return 0;
}