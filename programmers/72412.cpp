/* 효율성 고려
[해설]
- 정해진 4가지의 영역 -> 경우의 수 16가지 존재
- vector<조건, 점수> 로 세워야하는데, 같은 조건을 가졌지만 다른 점수를 가진 사람이 있을 수 있으므로 점수 자체도 vector로 설계

모든 지원자들을 위와 같은 방식으로 분류한 후 같은 그룹의 지원자끼리 묶어두고, 해당 그룹에서 점수를 기준으로 오름차순 정렬해 둡니다.
이제, 검색 조건이 주어질 경우 INFO 배열에서 지원자들을 찾지 않고, 미리 분류해둔 그룹에서 X점 이상 맞은 지원자 수를 세주기만 하면 됩니다.

- 앞으론 다른 문자열 자르는 방법을 사용해봐야겠따. stringstream을 token으로 활용하는건 공백 기준 자를 때!

- lower_bound / algorithm header
    용도 : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 찾기 위함
    
[느낀점]
- 완전탐색으로도 힘들게 힘들게(?) 풀어냈지만 효율의 중요성을 깨달은것같다.
- 갈 길이 멀다 아자아자!
*/
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;


// info 공백문자 기준 파싱
vector<string> split(string value){
    
    vector<string> ret;
    string split = " ";
    size_t prev = 0, cur;
    
    cur = value.find(split);
    while(cur != string::npos){
        string sub = value.substr(prev, cur - prev);
        ret.push_back(sub);
        prev = cur + split.size();
        cur = value.find(split, prev);
    }
    string last = value.substr(prev, cur - prev);
    ret.push_back(last);
    return ret;
}

vector<int> solution(vector<string> infos, vector<string> queries) {
    vector<int> answer(queries.size(), 0);
    
    unordered_map<string, vector<int>> cases;
    
    for(auto info : infos){
    
        vector<string> tokens = split(info);
        
        // 4가지 케이스
        vector<vector<string>> str(4, vector<string> (2, "-"));
        int score = 0;
        for(int i = 0 ; i < 5 ; i++){
            if(i < 4) str[i][0] = tokens[i];
            else score = stoi(tokens[i]);
        }
        
        // case 생성
        for(int i = 0 ; i < 2 ; i++){
            string t1, t2, t3, t4;
            t1 = str[0][i];
            for(int j = 0 ; j < 2 ; j++){
                t2 = str[1][j];
                for(int k = 0 ; k < 2; k++){
                    t3 = str[2][k];
                    for(int l = 0; l < 2 ; l++){
                        t4 = str[3][l];
                        cases[t1+t2+t3+t4].push_back(score);
                        
                    }
                }
            }
        }
    }
    
    // map 점수들 오름차순 정렬 -> 이후 점수 이분탐색을 위해 필요하다
    for(auto iter = cases.begin() ; iter != cases.end() ; iter++){
        sort(iter->second.begin(), iter->second.end());
    }
    
    for(int i = 0 ; i < queries.size() ; i++){
        string query = "", token;
        stringstream ss(queries[i]);
        int index = 0, score = 0;
        
        while(ss >> token){
            if(token == "and") continue;
            
            if(index++ < 4) query += token;
            else score = stoi(token);
        }
        
 
        // 반환형 : iterator
        auto iter = lower_bound(cases[query].begin(), cases[query].end(), score);
        // 오름차순으로 정렬해놨으니까 lower_bound 기준점 뒤에있는것들로 리턴
        answer[i] = cases[query].size() - (iter - cases[query].begin());
    }
    return answer;
}

/* 효율성 0점 ver
- info 하나의 문자열로 구성(공백문자로 구성)
- query : '-' = 해당조건 고려X
- query가 여러개임 -> 1사람의 정보를 돌을 때 query 다 돌면서 해당하는지 확인.
    => 전체적으로 50,000 * 100,000 인데 넘 비효율적인거 아닌지,, 이 방법밖에 모르겠는디
- 근데 굳이 파싱을 . 해야겠ㄷ ㅏ.
=> 효율성 0점 ㅎ
*/
#include <string>
#include <vector>

#include <iostream>

using namespace std;

vector<vector<string>> split(string split, vector<string> values){
    vector<vector<string>> ret;
    for(auto value : values){
        vector<string> temp;
        size_t prev = 0, cur;
        cur = value.find(split);
        while(cur != string::npos){
            string sub = value.substr(prev, cur - prev);
            temp.push_back(sub);
            prev = cur + split.size();
            cur = value.find(split, prev);
        }
        string last = value.substr(prev, cur - prev);
        temp.push_back(last);       
        ret.push_back(temp); 
    }
    return ret;
}

vector<int> solution(vector<string> a, vector<string> b) {
    vector<int> answer(b.size(), 0);
    
    vector<vector<string>> querySplit = split(" and ", b);
    vector<vector<string>> infoSplit = split(" ", a);
    
    for(auto info : infoSplit){

        for(int i = 0 ; i < querySplit.size() ; i++){
            // 해당 정보가 조건에 만족하는가?
            vector<string> q = querySplit[i];
            
            // 0 : cpp, java, python
            // 1 : backend, frontend
            // 2 : junior, senior
            // 3 : chicken, pizza
            // 4 : score
            // 3,4 는 따로 같이 해야함 and가 안껴있음
            if(q[0] != "-" && q[0] != info[0]){
                //cout << "here0" << endl;
                continue; 
            }
            if(q[1] != "-" && q[1] != info[1]){
                //cout << "here1" << endl;
                continue; 
            }
            if(q[2] != "-" && q[2] != info[2]){
                //cout << "here2" << endl;
                continue; 
            }
            
            size_t prev = 0, cur = q[3].find(" ");
            
            string pc = q[3].substr(prev, cur - prev);
            prev = cur + 1;
            cur = q[3].find(" ", prev);
            string score = q[3].substr(prev, cur - prev);
            
            //cout << pc << endl;
            //cout << score << endl;
            
            if(pc != "-" && pc != info[3]){
                //cout << "here3" << endl;
                continue;
            }
            if(score != "-" && stoi(score) > stoi(info[4])){
                //cout << "here4" << endl;
                continue;
            }

            // 모든 조건을 통과했다면
            answer[i]++;
        }
    }
    return answer;
}
