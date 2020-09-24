#include <iostream>

using namespace std;


int water(int* bar, int n){
    int result = 0;

    for(int i = 1 ; i < n ; i++){

        //기준점
        int left = bar[i];
        int right = bar[i];
        //get left max
        for(int j = 0 ; j < i ; j++){
            left = max(left, bar[j]);
        }
        //get right max 
        for(int j = i+1 ; j < n ;j++){
            right = max(right, bar[j]);
        }

        result += min(left, right) - bar[i];
    }
    return result;
}

int main(void){

    
    int bar[] = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int n = sizeof(bar)/sizeof(int);

    cout << water(bar, n) << endl;
    return 0;
}