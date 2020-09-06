#include <iostream>

using namespace std;

int recursiveSum(int n){
    if( n == 1 ) return 1;
    else
    return n + recursiveSum(n-1);
}

int fastSum(int n){
    if( n == 1) return 1;
    if( n % 2 == 1) return fastSum(n-1) + n;
    return 2*fastSum(2/n) + (n/2)*(n/2);
}

int main(void){
    
    int num;

    cout << "Enter a num : ";
    cin >> num;

    cout << "recursiveSum : " << recursiveSum(num) << endl;
    cout << "fastSum : " << fastSum(num) << endl;

    return 0;
}
