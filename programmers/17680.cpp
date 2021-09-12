/*
- LRU 사용(가장 "오래전"에 사용한!)
- 근데 그러면 매번 +1을 해줘야하는건디 + miss나고 자리 없으면 가장 오래된 넘을 뽑는 iterate 필요
- 대소문자 구분하지 않는다.

- 효율성 0점짜리로 한 번 만들어봤슴ㄴ다. => 효율성 점수는 없었네용

[7, 17만 틀림]
cacheSize가 0일 때 만약 cities에 ["LA", "LA"]가 있는 경우
cacheSize가 0이기 때문에 불러올때마다 cache miss이므로 총 10초의 시간이 걸리지만
정의해주지 않게 되면 6초의 시간이 걸리기 때문에 틀리게 됩니다
cacheSize가 0일 때를 예외로 정의해주시면 정답이 됩니다.

=> 0 일때는 매번 miss가 나야하니까 cache에서 찾을 필요도 없는겨,,와우
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    unordered_map<string, int> um;
    
    for(auto city : cities){
        transform(city.begin(), city.end(), city.begin(), ::tolower);
        
        // cache 안에 있는 지 판단
        unordered_map<string, int>:: iterator it;
        it = um.find(city);
        
        if(cacheSize != 0 && it != um.end()){
            // cache hit
            //cout << city << "   hit" << endl;
            answer += 1;
            um[city] = 0;
        }else{
            // cache miss
            answer += 5;
            
            // cache 크기가 아직 다 채워지지 않았으면 채워준다.
            if(um.size() < cacheSize){
                //cout << city << "   miss - 채우기" << endl;
                um[city] = 0;
            }else{
                // 가장 오래전에 쓰인것(second값이 가장 큰 것)
                int max = -1;
                string key;
                for(auto iter = um.begin() ; iter != um.end() ; iter++){
                    if(iter->second > max){
                        key = iter->first;
                        max = iter->second;
                    }
                }
                //cout << city << "   miss - 교체하기 with " << key << endl;
                um.erase(key);
                um[city] = 0;
            }
        }
        
        // 1씩 추가
        for(auto iter = um.begin() ; iter != um.end() ; iter++){
            iter->second += 1;
            //cout << iter->first << " : " << iter->second << endl;
        }
    }
    return answer;
}

/* vector 이용 버전
[검색]
- 굳이 unordered_map을 이용해 찾는데 1번, 교체할 곳 찾는데 1번, 가중치 늘리는데 1번 
    총 3번의 iterate하지 말고, vector를 이용해서 요소찾고 queue마냥 뒤로 돌리는 방식이 
    시간이 덜 걸림!
*/
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    
    vector<string> cache; // cache 역할
    
    for(vector<string>:: iterator it = cities.begin() ; it != cities.end() ; it++){
        transform(it->begin(), it->end(), it->begin(), ::tolower);
        
        bool flag = false;
        for(vector<string>:: iterator itt = cache.begin() ; itt != cache.end() ; itt++){
            // vector는 따로 find 없으니 직접 값 비교하기!
            if(*itt == *it){
                //cache hit, 뒤로 빼주기
                answer += 1;
                cache.erase(itt); // vector erase는 iterator로 들어가네요!
                cache.push_back(*it); // *itt 는 삭제되었으므로 쓰레기 값이 들어가나 보다!
                flag = true;
                
                break;
            }
        }
        
        // cache miss
        if(!flag){
            answer += 5;
            
            // 캐시 사이즈가 0 보다 크고, 캐시가 포화 됐을 때 -> 빼주기
            if(cacheSize != 0 && cache.size() >= cacheSize){
                cache.erase(cache.begin());
            }
            
            // 자리 있을 때
            if(cache.size() < cacheSize){
                cache.push_back(*it);
            }
            
        }
    }
    return answer;
}