#include <iostream>

#define MAX 51;

using namespace std;

typedef struct info{
    int height;
    int weight;
    int rank;
}INFO;

int main(void){
    
    // Initialize

    int n, weight, height;

    cin >> n;

    INFO * info_array = new INFO[n];

    for( int i = 0 ; i < n ; i ++)
    {
        cin >> weight >> height;

        info_array[i].weight = weight;
        info_array[i].height = height;
        info_array[i].rank = 1;
    }

    for( int i = 0 ; i < n ; i++){
        for( int j = i ; j < n ; j++){

            if( (info_array[i].height < info_array[j].height)&&(info_array[i].weight < info_array[j].weight) ){
                info_array[i].rank++;
            }else if((info_array[i].height > info_array[j].height)&&(info_array[i].weight > info_array[j].weight)){
                info_array[j].rank++;
            }
        }
        cout << info_array[i].rank << " ";
    }


    return 0;
}