#include <iostream>
#include <stack>
#include <queue>

#define MAX 1001

using namespace std;


int visited[MAX];
int connected[MAX][MAX] = {0,};

void visited_init(){
    for( int i = 1 ; i <= MAX ; i++)
        visited[i] = 0;
}

void dfs(int start, int size){


    stack<int> s;

    s.push(start);

    visited[start] = 1;
    cout << start << " ";

    while( ! (s.empty()) ){

        int top = s.top();
        int min = MAX ;

        for( int i = 1 ; i <= size ; i++){
            
            if (connected[top][i] == 1 && visited[i] != 1 ){
                if( i < min )
                    min = i;
            }
        }

        if(min != MAX){

            s.push(min);
            visited[min] = 1;
            cout << min << " ";
            
        }else
        {
            s.pop();
        }
    }
};

void bfs(int start, int size){

    queue<int> q;

    
    visited[start] = 1;
    cout << start << " ";

    q.push(start);

    while( ! (q.empty()) ){
        
        int top = q.front();

        q.pop();

        //Find smallest & not visited value
        for( int i = 1 ; i<= size; i++){
        
            if( connected[top][i] == 1 && visited[i]!= 1 ){
    
                visited[i] = 1;
                q.push(i);
                cout << i << " ";
            }
        }

    }
};

int main(void){
    
    int n, m, v;
    
    cin >> n >> m >> v;

    //init edge
    for( int i = 1 ; i<= m ; i++){

        int a, b;
        cin >> a >> b;

        connected[a][b] = 1;
        connected[b][a] = 1;
    }

    visited_init();
    dfs(v, n);
    
    cout << endl;
    visited_init();
    bfs(v, n);
    return 0;
}