#include <iostream>

using namespace std;

int mat[4][4] = { {1, 3, 1, 5},
                {2, 2, 4, 1},
               {5, 0, 2, 3},
               {0, 6, 1, 2}};
int width = 4;
int height = 4;

int goldTable[4][4] = {0, };

//시바릿발
int getMax(int row, int col){
    
    if(row >= height || col >= width)
        return 0;

    /*
    int right = mat[row][col] + getMax(row, col+1);
    int rightUp = mat[row][col] + getMax(row-1,col+1);
    int rightDown = mat[row][col] + getMax(row+1,col+1);
    
    return max(right, max(rightUp, rightUp));
    */
   return mat[row][col] + max(getMax(row, col+1), max(getMax(row-1,col+1),getMax(row+1,col+1)));
}
int main(void){

    int sum = 0;
    int max = 0;

    //달라진건 이거같음 wow..증말 바보당나 
    for(int i = 0 ; i < height ; i++){
        int temp = getMax(i, 0);

        if( max < temp) max =temp;
    }

    cout << max << endl;

    

    return 0;

}

/*
def getMaxGold(gold, i, j):

if 0 <= i < len(gold) and 0 <= j < len(gold[0]):

return max(gold[i][j] + getMaxGold(gold, i + d[0], j + d[1]) for d in dir)

return 0

print max(getMaxGold(gold, i, 0) for i in range(len(gold)))

*/