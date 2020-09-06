#include <iostream>
#define MAX 101
using namespace std;

int board[MAX][MAX];

/* my answwer */
bool isPossible(int** arr, int row, int col, int num){

    /* 틀린 부분 ~ 이미 판의 경계를 넘어간 ( 할당 되지 않은 ) 값을 먼저 참조할 수 없지 !!! 와우..
     int state = arr[row][col];
    */

    if(row >= num || col >= num) return false;
    // 도착 시 
    if(row == num-1 && col == num-1) return true;

    // 모든 조건을 다 거친 뒤에 ( 뛸 수 있는 경우, jumpSize를 정해줘야 함.)
    int state  = arr[row][col];
    if( state == 0 )
        return false;

    // 뛸 수 있는 경우의 리턴 값
    //return isPossible(arr, row, col + state, num) || isPossible(arr, row+state, col, num); 
  
    /* 틀린 부분 ~ 리턴이 하나 없어지는 거니까 해당 함수에 대한 최종적인 결과를 가져오지 못하는거지? 보이는 그대로? 
    isPossible(arr, row, col + state, num);
    isPossible(arr, row+state, col, num); 
    */

    // 암튼 최종적으로 뛴 다음을 해결해줘야하는 거였음 !! 
    bool a, b;

    a = isPossible(arr, row, col + state, num);
    b = isPossible(arr, row+state, col, num); 

    return a||b;
    
}

/* book */
bool jump(int** arr, int row, int col, int num){

    // 판 범위 넘어갔을 때
    if( row >= num || col >= num) return false;
    
    // 마지막 칸에 도착했을 때
    if(row== num-1 && col == num-1) return true;

    int jumpSize = arr[row][col];

    return jump(arr, row, col+jumpSize, num) || jump(arr, row+jumpSize, col, num);
}

int main(void){

    int caseCount;
    bool result = false;
    cin >> caseCount;
    
    for( int tc = 0 ; tc < caseCount ; tc++){

        int n;
        cin >> n;

        int** ary = (int**)malloc(sizeof(int*)*n);
        for( int i = 0 ; i < n ; i++){
            *(ary+i) = (int*)malloc(sizeof(int)*n);
        }

        for( int i = 0 ; i < n ; i++){
            for( int j = 0 ; j < n ; j++){
                cin >> ary[i][j];
            }
        }

        result = isPossible(ary, 0, 0, n);
        //result = jump(ary, 0, 0, n);
        for( int i = 0 ; i < n ; i++)
            free(ary[i]);
        free(ary);

        
        if(result)
            cout << "yes" << endl;
        else
            cout << "No" << endl;
        
    }
    return 0;
}
