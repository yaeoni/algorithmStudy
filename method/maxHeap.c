#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 256

// indx = 1 부터 시작한다고 가정.

int heap_count;
int heap[HEAP_SIZE];

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;

}

void heap_init(){
    heap_count = 0;
}

int get_size(){
    return heap_count;
}

void push(int data){
    heap[++heap_count]= data;
    
    // Heap은 형제간 대소관계는 따지지 않음
    int child = heap_count;
    int parent = child/2;

    while(child > 1 && heap[parent] < heap[child]){
        swap(&heap[parent], &heap[child]);
        child = parent;
        parent = child/2;
    }
}

int pop(){
    
    int ret = heap[1];

    heap[1] = heap[heap_count];
    heap_count--;

    int parent = 1;
    int child = parent*2;

    //노드의 자식 중에 더 큰놈을 찾는다. 부모로 올려야하니까 더 큰놈으로 해야지.. 이자식아!!
    if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	}

    while(child <= heap_count && heap[parent] < heap[child]){
        swap(&heap[parent], &heap[child]);
        parent = child;

        child = parent*2;
        if (child + 1 <= heap_count) {
		child = (heap[child] > heap[child + 1]) ? child : child + 1;
	    }

    }
    return ret;
}


int main(void){

    return 0;
}