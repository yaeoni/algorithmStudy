#include <iostream>
#include <vector>
using namespace std;

/* Use flag */
int hugCount2(const vector<char>& star, const vector<char>& fan){
    int ret = 0;
    bool flag = true;
    int waiting = fan.size() - star.size();

    for (int i = 0 ; i <= waiting ; i++){
        
        for( int j = 0 ; j < star.size() ; j++){
            if(star[j] == 'M' && fan[j + i] == 'M')
                flag = false;
        }
        if( flag )
            ret++;
    }
    for( int i = 0 ;  i < star.size() ; i++ ){
        if(star[i] == 'M' && fan[i] == 'M')
            flag = false;
    }
    return ret;
}

/* Use count */
int hugCount1(const string& star, string& fan){
    int ret = 0;
    int waiting = fan.size() - star.size();
    
    if (waiting < 0)
        return 0;

   
    for( int i = 0 ; i <= waiting ; i++){

        int count = 0;

        for(int j = 0 ; j < star.size() ; j++){
            if(star[j] == 'F')
                count++;
            else if(star[j] =='M' && fan[j] =='F')
                count++;
        }

        if(count == star.size())
            ret++;

        fan.erase(0,1);
    }
    return ret;
}

int main(void){
    string star, fan;
    int count;

    cin >> star;
    cin >> fan;

    //count = hugCount1(star, fan);

    vector<char> a(star.begin(), star.end());
    vector<char> b(fan.begin(), fan.end());

    count = hugCount2(a, b);

    cout << count;

    return 0;


}