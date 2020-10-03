#include <iostream>

#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)

using namespace std;

// (한 index씩 돌면서) 만나는 0 <-> 첫번째로 만날 수 있는 숫자
void moveZero(int* ary, int size){

    for(int i = 0 ; i < size ; i++){
        if(ary[i] == 0){
            for( int j = i + 1 ; j < size ; j++){
                if(ary[j] != 0) {
                    SWAP(ary[i], ary[j], int);
                    break;
                }
            }
        }
    }
}

int main(void){

    int size;
    cin >> size;

    int* ary = (int*)malloc(sizeof(int)*size);

    for( int i = 0 ; i < size ; i++)
        cin >> ary[i];

    moveZero(ary, size);

    for( int i = 0 ; i < size ; i++)
        cout << ary[i] << ' ';

    return 0;
}