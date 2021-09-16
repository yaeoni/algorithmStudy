/*
- 파일명 속 포함된 숫자를 반영한 정렬 기능
- 영문 대소문자, 숫자, 공백, , , - 로 이루어짐
- HEAD(문자), NUMBER, TAIL(나머지) 로 나눠서 각기 비교해야된다.
- files.size() * 3 의 크기면 되겠다. => split 처리 완료
- 커스텀 compare 함수를 넣어서 비교한다.

* 끝까지 같은 경우에는 순서 유지하라고 했는데, c++은 unstable 정렬이라 따로 정렬도 맞춰줘야하는디 , , ,
    => c++ algorithm header에 stable_sort
    
=> 로직은 맞는데, 어디서 오류가 나는걸까~ 아~ 숫자가 5글자면 끝나는거임,,
=> 아~ transform 은 영어외에도 다른문자들이 낑겨있을 수 있음!! 따로 만들어줘야했다.
*/
#include <string>
#include <vector>
#include <algorithm>

#include <iostream>
using namespace std;

string to_lower(string str){
    string ret = "";
    for(int i = 0 ; i < str.size() ; i++){
        if( 'A' <= str[i] && str[i] <= 'Z'){
            ret += str[i] + ('a' - 'A');
        }else ret += str[i];
    }
    return ret;
}
bool compare(vector<string> x, vector<string> y){
    string nx = to_lower(x[0]);
    string ny = to_lower(y[0]);
    
    if(nx != ny){
        return nx < ny;
    }
    return stoi(x[1]) < stoi(y[1]);

}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    
    // files.size() * 3(H, N, T)의 크기의 배열
    vector<vector<string>> v;
    
    // split 해서 집어 넣기
    for(int idx = 0 ; idx < files.size() ; idx++){
        
        string head = "";
        string number = "";
        string tail = "";
        
        int flag = 0;
        
        for(int i = 0 ; i < files[idx].size() ; i++){
            
            // 숫자일 때
            if('0' <= files[idx][i] && files[idx][i] <= '9'){
                if(flag == 0) flag = 1;
                               
            }else if( flag == 1){
                // 숫자가 아닌데, 이미 숫자를 보았을 때 
                flag = 2;
            }
            
            if(number.size() == 5) flag = 2;
            
            if(flag == 0) head += files[idx][i];
            else if(flag == 1) number += files[idx][i];
            else tail += files[idx][i];                
        }
        
        //cout << head << " " << number << " " << tail << endl;
        vector<string> temp;
        temp.push_back(head);
        temp.push_back(number);
        temp.push_back(tail);
        
        v.push_back(temp);
    }
    
    stable_sort(v.begin(), v.end(), compare);
    
    for(int i = 0 ; i < v.size() ; i++){
        vector<string> split = v[i];
        string s = "";
        for(int j = 0 ; j < split.size() ; j++){
            s += split[j];
        }
        answer.push_back(s);
    }
    return answer;
}