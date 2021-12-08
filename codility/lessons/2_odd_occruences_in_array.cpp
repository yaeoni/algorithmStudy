#include <unordered_map>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
   unordered_map<int, int> um;

    for(int value : A){
        auto item = um.find(value);

        if(item != um.end()){
            um.erase(value);
        }else{
            um.insert({value, 1});
        }
        
    }

    auto iter = um.begin();
    return iter->first;
}