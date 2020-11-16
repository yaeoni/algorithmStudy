#include <string>
#include <vector>

using namespace std;

/* https://programmers.co.kr/learn/courses/30/lessons/42584 */

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    for(int i = 0 ; i < prices.size() ; i++){
        bool flag = false;
        int time = 0;

        for(int j = i+1; j < prices.size() ; j++){
            if(prices[i] <= prices[j]){
                time++;
            }else{
                flag = true;
                time++;
                answer.push_back(time);
                break;
            }
        }
        if(!(flag) && i != prices.size() -1 ){
             answer.push_back(time);
        }
    }
    answer.push_back(0);
    return answer;
}
