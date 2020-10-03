#include <iostream>
#include <vector>

using namespace std;

int getBroad_for(const vector<int>& v){

    int maxBoard = 0;
    int temp;

    for(int i = 0; i < v.size() ; i++){
        int minHeight = v[i];
        for(int j = i ; j < v.size(); j++ ){
            minHeight = min(minHeight, v[j]);
            temp = (j-i+1)*minHeight;

            if(temp > maxBoard){
                maxBoard = temp;
            }
        }
    }
    return maxBoard;
}

int getBoardRecursive(const vector<int>& v, int left, int right){

    // if the num of panel is one
    if(left == right) return v[left];

    // left, right recursive
    int mid = (left + right) / 2;

    int ret = max(getBoardRecursive(v, left, mid-1), getBoardRecursive(v, mid, right));

    int le = mid, re = mid+1;
    int height = min(v[le], v[re]);

    // mid 기준 양 옆
    ret = max(ret, 2*height);

    // 왼쪽, 오른쪽 "한 칸씩"  비교해가면서 넓이 비교 ( 전체 너비 다 덮는 경우 까지 비교하는 거임 )
    // 더 높이가 높은 방향으로 진행을 해간다. 하지만 넓이를 구할 떄의 높이는 더 작은 놈 기준 인거지!
    while(left < le || re < right){

        // re 가 제일 오른쪽까지 가지 않으면서, le가 왼쪽 끝까지 도달했을 경우에
        if( (re < right) && ( le == left || v[le-1] < v[re+1]) ){
            re++; 
            height = min(height, v[re]);
        }else{
            le--;
            height = min(height, v[le]);
        }
        
        ret = max(ret, (re - le + 1)*height);
    }

    return ret;
}

int main(void){

    return 0;
}
