/*
- 각각의 곡 정보는 음악이 시작한 시각, 끝난 시각, 음악 제목, 악보 정보가 ','로 구분된 문자열 => 파싱 필요
- 찾으려는 음악의 제목 구하기
- 조건 일치 음악이 있으면 -> 시간 제일 긴것 -> 먼저 입력된 것
- 시간 대로 악보를 만들어놓고 해당 string이 있는지 확인
*/
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// string(제목)은 정렬에 아무 상관 없다!
// sort 기준은 재생시간에 대해서만 해야한다!
bool compare(pair<int, string>  x, pair<int, string> y){
    return x.first > y.first;
}

vector<string> split(string str, string sp){
    
    vector<string> ret;
    
    size_t prev = 0, cur;
    cur = str.find(sp);
    
    while(cur != string::npos){
        string sub = str.substr(prev, cur - prev);
        
        ret.push_back(sub);
        
        prev = cur + sp.size();
        cur = str.find(sp, prev);
    }
    string last = str.substr(prev, cur - prev);
    ret.push_back(last);
    
    return ret;
}


string solution(string m, vector<string> musicinfos) {
    string answer = "";
    
    vector<pair<int, string> > pass;
    
    for(auto musicinfo : musicinfos){
        // 시작한 시각, 끝난 시각, 음악 제목, 악보 정보
        vector<string> v = split(musicinfo, ",");
        
        // 재생 시간(play) 계산(1분 단위)
        vector<string> start = split(v[0], ":");
        vector<string> end = split(v[1], ":");
        
        int play = (stoi(end[0])*60 + stoi(end[1]))- (stoi(start[0])*60 + stoi(start[1]));
    
        
        // # 을 고려한 악보만들기
        int idx = 0;
        string playSheet = "";
        string sheet = v[3];
        for(int i = 0 ; i < play ; i++){
            
            if(idx == sheet.size()) idx = 0;
            
            playSheet += sheet[idx++];
            if(idx < sheet.size() && sheet[idx] == '#'){
                playSheet += sheet[idx++];
            }
            
            
        }
        
        // 있는지 확인 => 얘도 find
        // => ABC#ABC 일 수도 있기때문에 끝까지 다 찾아줘야한다!
        size_t prev = 0, cur = playSheet.find(m);
        while(cur != string::npos){
            // m은 포함되어있지만 끝에 #이 있으면 다른 플레이임!
            if(playSheet[cur+m.size()] != '#'){
                pass.push_back(make_pair(play, v[2]));
                break;
            }
            
            prev = cur + m.size();
            cur = playSheet.find(m, prev);
        }
 
    }
    
    if(pass.size()== 0) return "(None)";
    
    // 여기서 stable sort가 안먹히나,,? => 기준을 직접 잡아줬어야했음!
    stable_sort(pass.begin(), pass.end(), compare);
    
    return pass[0].second;
}