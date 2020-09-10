#include <iostream>

using namespace std;

/* Use Dynamic programming with static ary */

int board[100][100];
int cache[100][100];
int num;

int jump2(int row, int col){

    if( row >= num || col >= num ) return 0;
    if( row == num -1 || col == num-1) return 1;

    int& ret = cache[row][col];

    if( ret != -1 ) return ret;

    int jumpSize = board[row][col];

    //cache에 갱신
    ret = jump2(row, col + jumpSize) || jump2(row+jumpSize, col);

    return ret;
}

int main(void){

    cin >> num;

    for( int i = 0 ; i < num ; i++){
        for(int j = 0 ; j < num ; j++)
            cin >> board[i][j];
    }

    memset(cache, -1, sizeof(cache));

    
    return 0;
}