/*
- 효율성 0 점인 방법 -> 2중 포문으로 요소 각각에 대해 판단하는법(길이가 100,000이니까 0점 나옴)
- 이게 스택/큐에 영역에 있어서 그쪽으로 생각을 한 번 해보게 되는데, 잘 감이 안잡히는군?!
=> 스택 큐 활용법은 정망ㄹ 안떠올라서 brute force 썼는데, 그래도 효율성을 통과하네,,?!
*/
#include <string>
#include <vector>

#include <iostream>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0 ; i < prices.size() ; i++){

        int count = 0;
        
        for(int j = i+1 ; j < prices.size(); j++){
            if(prices[i] <= prices[j]) count++;
            else{
                count++;
                break;
            }
        }
        
        answer.push_back(count);
    }
    return answer;
}