#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int> > merged;

void merge(vector<pair<int,int> > v){
    //정렬
    sort(v.begin(), v.end());

    merged.push_back(v[0]);

    for(int i = 1; i < v.size() ; i ++){
        if(merged.back().second < v[i].first){
            merged.push_back(v[i]);
        }
        else{
            merged.back().second = max(merged.back().second, v[i].second);
        }
    }

}
//입력을 어떻게 받는지에 대해서 고민 했었음
int main(void){

    int size;
    cin >> size;
    vector<pair<int, int> > v;

    for(int i =0 ; i < size ; i++){
        int first, second;
        cin >> first;
        cin >> second;
        v.push_back(make_pair(first, second));
    }

    merge(v);

    for(int i = 0 ; i < merged.size(); i ++){
        cout << merged[i].first << " ";
        cout << merged[i].second << endl;
    }
    return 0;
}