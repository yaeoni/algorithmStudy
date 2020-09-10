#include <iostream>
#define MAX_NUMBER 100

using namespace std;


int tri[100][100];
int height;

//해당 위치에 오면서 만난 최대합
int cache1[101][101][ MAX_NUMBER*100 +1];
int cache2[101][101];

/* Recursive */
int maxSum(int row, int col, int sum){

    // 마지막 줄에 닿았을 때
    if( row == height -1)
        return sum + tri[row][col];
    
    // 오른쪽 넘었을 때
    if(col+1 > row+1)
        return maxSum(row+1, col, sum+tri[row][col]);
    
    return max(maxSum(row+1, col, sum+tri[row][col]), maxSum(row+1, col+1, sum+tri[row][col]));

}

/* Memoization */
int path1(int row, int col, int sum){

    // 마지막 줄에 닿았을 때
    if( row == height -1)
        return sum + tri[row][col];

    int& ret = cache1[row][col][sum];

    // 여기 내려오기 까지의 합을 안다면
    if(ret != -1)
        return ret;
    
    // 오른쪽 넘었을 때
    if(col+1 > row+1)
        return ret = path1(row+1, col, sum+tri[row][col]);
    
    return ret = max(path1(row+1, col, sum+tri[row][col]), path1(row+1, col+1, sum+tri[row][col]));

}

/* Optimization */
int path2(int row, int col){
    if(row == height -1)
        return tri[row][col];

    int& ret = cache2[row][col];
    if(ret != -1)
        return ret;
    
    
    if( col +1 > row+1 )
        return ret = tri[row][col] + path2(row+1, col);

    return ret = tri[row][col] + max(path2(row+1, col), path2(row+1,col+1));
    

}

int main(void){

    int caseCount;
    cin >> caseCount;

    for( int i = 0 ; i < caseCount ; i++){

        cin >> height;
        memset(cache2, -1, sizeof(cache2));
        // 삼각형 모양을 만들어야하는데
        for(int i = 0 ; i < height; i++){
            for(int j = 0 ; j <= i ; j++){
                cin >> tri[i][j];
            }
        }
        int ret = path2(0,0);
        cout << ret << endl;
    }
    

    return 0;
}