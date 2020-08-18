#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

    vector<int> v;

    int n;
    int num;
    cin >> n;

    v.reserve(n);

    for( int i = 0 ; i < n ; i++){
        scanf("%d", &num);
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    vector<int>::iterator p;

    for( p = v.begin() ; p != v.end(); ++p){
        printf("%d\n", *p);
    }
}