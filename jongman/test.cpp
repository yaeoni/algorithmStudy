#include <iostream>

using namespace std;

int main(void){

    string s = "2[ab]";

    string b = "absc";

    strcat(s, b);

    cout << s << endl;

    return 0;
}