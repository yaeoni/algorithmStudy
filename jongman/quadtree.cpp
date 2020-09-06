#include <iostream>
#include <string>
#define MAX_SIZE 100

using namespace std;

// 주어진 크기로만 따지면 MAX_SIZE 2^20로 해줘야함 => 넘 큼 ! 
char decompressed[MAX_SIZE][MAX_SIZE];

// x, y = 배열의 어느 부분에 지정되어야 하는가
// size = N*N 배열의 N ~ 넘 큼 !
void decompress(string::iterator& it, int y, int x, int size){

    char head = *(it++);

    // 기저 사례 - 첫 글자가 w, b 일경우
    if( head == 'w' || head == 'b' ){
        for( int i = 0 ; i < size ; i++){
            for( int j = 0 ; j < size; j++){
                decompressed[y+i][x+j] = head;
            }
        }
    }
    else{
        // 4등분 하기 -> 첫 글자가 w, b 일 때까지 계쏙 돌림 
        int half = size/2;
        decompress(it, y, x, half);
        decompress(it, y, x+half, half);
        decompress(it, y+half, x, half);
        decompress(it, y+half, x+half, half);
    }
}

//바로 생성하는 코드
string reverse(string::iterator it){

    char head = *(it++);

    if( head == 'w' || head == 'b'){
        return string(1, head);
    }
    // 함수 지나가면서 주어진 압축 string 가리키는 포인터 계쏙 +1씩 된다. ( 래퍼런스 타입으로 참조하니까 )
    string upLeft = reverse(it);
    string upRight = reverse(it);
    string downLeft = reverse(it);
    string downRight = reverse(it);

    // 위 아래 조각 각각 바꾸기
    return string("x") + downLeft + downRight + upLeft + upRight;
}