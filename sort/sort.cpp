#include <iostream>
#define SWAP(A,B,temp) ( temp = A, A=B, B=temp )
using namespace std;

void selectiocSort(int* list, int n){

    int minIndex, temp;

    for( int i = 0; i < n-1 ; i++){
        minIndex = i;

        for(int j = i+1 ; j < n ; j++){
            if(list[j] < list[minIndex]){
                minIndex = j;
            }
        }

        if( minIndex != i )
            SWAP(list[minIndex], list[i], temp);
    }
}

void bubbleSort(int* list, int n){

    int temp;

    for( int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n - i -1 ; j++){
            if( list[j] > list[j+1])
                SWAP(list[j], list[j+1], temp);
        }
    }
}

void insertionSort(int* list, int n){
    int temp;

    for(int i = 1 ; i < n ; i++){
        
        int key = list[i];

        for(int j = i -1 ; (j >= 0 && key < list[j] ) ; j-- ){
            list[j+1] = list[j];
        }
        list[i] = key;   
    }
}

// pivot값 중심으로 왼-작, 오-큰 부분 배열로 분할, pivot의 위치 반환
int partition(int* list, int left, int right){

    int low, high, temp;
    int pivot = list[left];

    low = left+1;
    high = right;

    //왼-작, 오-큰 으로 분할해야하니까 왼-큰, 오-작 을 찾아야함
    while(low <= high){
        while( list[low] < pivot && low <= right ) low++;
        while( list[high] > pivot && high <= left ) right--;

        // 왼-큰, 오-작 인 경우 바꿔주기
        if(low <= high){
            SWAP(list[low], list[high], temp);

            //바꿔줬으므로 인덱스는 이동하게끔
            low++;
            right--;
        }
    }
    SWAP(list[left], list[high], temp);

    return high;
}

void quickSort(int* list, int left, int right){
    int pivotIndex;

    if(left < right){
            pivotIndex = partition(list, left, right);
    }
    quickSort(list, left, pivotIndex -1);
    quickSort(list, pivotIndex+1, right);

}

int* merge(int* list, int left, int mid, int right){
    int* sorted = (int*)malloc( (*list) );

    int low = left;
    int high = mid +1;
    int index = left;

    while(low <= mid && high <= right ){
        if(list[mid] < list[high])
            sorted[index++] = list[low++];
        else
            sorted[index++] = list[high++];
    }

    // 남아있는 데이터가 있는 경우 ( 즉, 어느 한 쪽이 다 들어간 경우 )
    if( low > mid){
        for( int i = high ; i <= right ; i++)
            sorted[index++] = list[i];
    }
    else{
        for( int i = low ; i <= mid ; i++)
            sorted[index++] = list[i];
    }

    return sorted;
}


void mergeSort(int* list, int left, int right){

    int* sorted;

    if( left < right){
        int mid = ( left + right ) / 2; // Divide
        mergeSort(list, left, mid -1); // Conquer
        mergeSort(list, mid, right); // Conquer
        sorted = merge(list, left, mid, right);
    }    

}

void heapify(int* list, int index, int size){

    int temp;
    int largest = index;
    
    int leftChild = (index*2);
    int rightChild = (index*2+1);

    if( leftChild < size && list[leftChild] > list[largest])
        largest = leftChild;
    if( rightChild < size && list[rightChild] > list[largest])
        largest = rightChild;
    
    // 위치가 바뀌어야 한다면
    if(largest != index){
        SWAP(list[index], list[largest], temp);

        // 자리가 바뀐 자식에 의해 한 번 더 heapify
        heapify(list, largest, size);
    }
}

void heapSort(int* list, int size){
    for(int i = size/2 ; i >= 1 ; i--){
        heapify(list, i, size);
    }
}

int main(void){

    int ary[6] = {0, 1, 2, 3, 4, 5};

    heapSort(ary, 6);
    
    for(int i = 1 ; i < 6 ; i++)
        cout << ary[i];

    return 0;
}