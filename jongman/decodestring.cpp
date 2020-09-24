#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> input;

string decode(string input){

    string result;
    int n;  

    stack<char> strBucket;
    stack<int>  intBucket;

    for(int i = 0 ; i < input.size() ; i++){
        string str;
        if( 48 <= (int)input[i] && (int)input[i] <= 57){
             intBucket.push(input[i] - '0');
        }else{
           if(input[i] != ']'){
                strBucket.push(input[i]);
            } else{
                while(strBucket.top() != '['){
                    //cout << strBucket.top();
                    str.push_back(strBucket.top());
                    strBucket.pop();
                    cout << str << endl;
                }
                //cout << i << "th : "<< str << endl;
                strBucket.pop();
            
                 // 더 남은 경우, 끝난 경우.. 근데 계속계속 끝나지않으며?-
                int num = intBucket.top();
                intBucket.pop();

                if(strBucket.empty()){

                    reverse(str.begin(), str.end());
                    
                    for(int i = 0 ; i < num-1 ; i++){
                        str += str;
                        //cout << i << "th : " << str << endl;
                    }
                   
                }else{
                    for(int count = 0; count < num ; count++){
                        for(int index = str.size() -1 ; index >= 0 ; index--){
                            strBucket.push(str[index]);
                        }
                    }
                }
            }
        }
        result = str;
    }
    return result;
}


int main(void){
    string result;
    /*
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; i++){
        string s;
        cin >> s;
        input.push_back(s);
    }
    */
    //2[a2[bc]] == abcbc abcbc
    string s ="2[a2[bc]]";
    result = decode(s);
    cout << result << endl;
    return 0;
}