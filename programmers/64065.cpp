/*
- 특정 튜플 표현하는 문자열 -> 표현하는 튜플 리턴하기
- (a1, a2, a3, ..., an) 
    => {{a1}, {a1, a2}, {a1, a2, a3}, {a1, a2, a3, a4}, 
        ... {a1, a2, a3, a4, ..., an}}
- c++은 문자열 파싱이 영 고되네,,
- 1. 앞 뒤 {{ }} 짜르고, },{ 기준으로 split처리하기
  2. 길이 순 정렬 
    2-1. 맨 첫번ㅉㅐ 것 -> 첫번째 글자
            그 이후부터는 순서 맞춰서,,!

=> 너무 비효율적인 것 같기는 하다 ;-;
*/
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(string a, string b){
    if (a.size() < b.size()){
        return true;
    }else
        return false;
}
vector<int> solution(string ns) {
    vector<int> answer;
    
    string s = "";
    for(int i = 2 ; i < ns.size()-2 ; i++){
        s += ns[i];
    }
   
    vector<string> v;
    
    string delimiter = "},{";
    size_t pos = 0;
    string token;
    
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        v.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    v.push_back(s);
    
    sort(v.begin(), v.end(), comp);
    
    // initialize
    answer.push_back(stoi(v[0]));
    for(int i = 1 ; i < v.size() ; i++){
        string temp = v[i]; // 여기서도 , 를 기준으로 잘라줘야한다.
        vector<int> vt;
        
        //cout << "START: " << temp << endl;
        
        delimiter = ',';
        pos = 0;
        token = "";
        
        while ((pos = temp.find(delimiter)) != string::npos) {
            token = temp.substr(0, pos);
            vt.push_back(stoi(token));
            temp.erase(0, pos + delimiter.length());
        }
        vt.push_back(stoi(temp));
        
        for(auto t : vt){
            auto it = find(answer.begin(), answer.end(), t);
            if(it == answer.end()) answer.push_back(t);
            else continue;
        }
        
    }
    
    return answer;
}


/* 
- 중복 체크는 set을 이용해서!
- 굳이 split을 안만들어도, iterate하면서 하나씩 확인할 수 있따.
- 좀 더 효율적인 버저언임ㄴ다.
*/

#include<algorithm>
#include<set>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    vector<int> temp;
    
    // 크기(사이즈)순 정렬 위한 pair
    vector<pair<int, vector<int>>> vt;
    
    int size = s.size();
    int num = 0;
    
    // 양끝 괄호 무시
    for(int i = 1 ; i<size-1 ; i++){
        if(s[i] == '{') continue;
        if(s[i] == '}'){
            temp.push_back(num);
            vt.push_back(make_pair(temp.size(), temp));
            
            num = 0;
            temp.clear();
        }
        else if(s[i] == ','){
            // 집합 구분 쉼표라면 컨티뉴
            if(s[i-1]== '}') continue;
            
            temp.push_back(num);
            num=0;
        }
        else{
            // 숫자 형태라면
            num *= 10;
            num += (s[i]-'0'); // int 형태로 집어넣음
        }
    }
    
    sort(vt.begin(), vt.end());
    
    set<int> res;
    
    for(pair<int, vector<int>> p : vt){
        for(int num : p.second){
            if(res.find(num) == res.end()){
                res.insert(num);
                answer.push_back(num);
            }
        }
    }
    return answer;
}