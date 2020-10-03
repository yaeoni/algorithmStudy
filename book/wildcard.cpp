#include <iostream>
#include <vector>

using namespace std;

/* 
'*' 의 늪에 걸려버린 상태 
bool isPossible(const string& pattern, vector<string>& fileName){

    for(int i = 0 ; i < fileName.size() ; i++){

        for( int j = 0 ; j < pattern.size() ; j++ ){}
            string temp = fileName[i];

                switch(pattern[j]){
                    case '?' :
                        temp.substr(0);
                        break;

                    case '*' :
                        

                    default : 
                        if( pattern[j] == fileName[i].at(j)) temp.substr(0);
                        else return false;
                        break;
                }
        }
    }

}
*/

/* book */
bool match(const string& w, const string& s){

    //비교 위치 
    int pos = 0;

    // 하나의 문자열이 끝나기 전까지 , 패턴의 문자가 ? 이거나, 패턴과 파일명의 문자 값이 같을 때까지
    // 즉 패턴의 문자가 * 일 때까지 pos를 늘림
    while(pos < s.size() && pos < w.size() && ( w[pos] =='?' || w[pos] == s[pos] ) )  
        pos++;

    // 2. w끝에 도달한 경우
    // if 문 중첩으로 쓸 수 있지만 return문 자체를 조건문으로 씀
    // 패턴이 끝나고, 문자열도 끝났다면 여기서 true가 반환됨.
    // 재귀에서 여기가 false면 되돌아가서 다시 *인 상태로(skip++은 된 채로) 문자열의 대응여부를 알 수 있음.
    if(pos = w.size()) 
        return pos == s.size();
    
    // 하나씩 넘겨가면서 순회 ( * 가 몇글자에 대응되는가 하나하나 확인 하는 것 )
    // true가 반환되는걸 보고(2번), 최종적 true 반환
    if(w[pos]=='*'){
        // 남은 문자열 순회
        for(int skip = 0 ; pos+skip <= s.size() ; skip++){
            if( match(w.substr(pos+1), s.substr(pos+skip)))
                return true;
        }
    }

    //나머지 경우에 대해 false
    return false;
} 

/* memoization */
int cache[101][101];
string W, S;

// 패턴이 대응되는지의 여부를 반환
// O(n^3)
bool matchMemoized(int w, int s){

    //memoization
    int& ret = cache[w][s];
    if(ret != -1 ) return ret;

    //W[w]와 S[s]를 맞춰나간다.
    while(s < S.size() && w < W.size() && (W[w] =='?' || W[w] == S[s] ) ){
        w++;
        s++;
    }

    if(w == W.size())
        return ret = ( s== S.size());
    
    //while문 끝난 뒤의 처리 + s가 끝에 도달했을 때가 여기 있지
    if(W[w] == '*'){
        for( int skip = 0 ; w + skip < W.size() ; skip++ ){
            if(matchMemoized(w+1, s+skip))
                return ret = 1;
        }
    }

    return ret = 0;

}

// O(n^2)로 돌리는 법
bool optimizedMatchMemoized(int w, int s){

    //memoization
    int& ret = cache[w][s];
    if(ret != -1 ) return ret;

    //W[w]와 S[s]를 맞춰나간다.
    while(s < S.size() && w < W.size() && (W[w] =='?' || W[w] == S[s] ) ){
        // 첫 글자씩만 떼어내고 대응하는지 확인 
        return ret = optimizedMatchMemoized(w+1, s+1); // cache에 할당하면서 리턴
    }

    if(w == W.size())
        return ret = ( s== S.size());

    // 대응하지 않았을 경우 ( * 를 만났을 때 )
    // 매 단계에서 *에 글자를 대응시키지 않을 것인지, 한 글자 더 대응시킬 것인지 결정
    if( W[w] == '*'){
        // 0글자 대응되는 경우 || 1글자 대응되는 경우
        if(optimizedMatchMemoized(w+1, s) || s < S.size() && optimizedMatchMemoized(w, s+1) ){
            return ret = 1;
        }
    }

    return ret = 0;

}



int main(void){

    int caseCount;
    cin >> caseCount;

    for( int i = 0 ;  i < caseCount ; i ++){
        
        memset(cache, -1, sizeof(cache));

        int fileCount;
        string pattern;
        vector<string> fileName;

        cin >> pattern;
        cin >> fileCount;
        for(int j = 0 ; j < fileCount ; j++){
            string name;
            cin >> name;
            fileName.push_back(name);
        }

        cout << pattern << endl;
        cout << fileCount << endl; 
    }



    return 0;
}