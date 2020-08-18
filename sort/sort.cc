#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

/* can make criteria by ourselves */



class Student{

public : 
    string name;
    int score;    

    Student(string name, int score){
        this->name = name;
        this->score = score;
    }

    // make criteria
    const bool operator< (Student const& student){
        return this->score < student.score;
    }
};

bool compare( Student a , Student b){

    //return true when a < b 
    return a.score > b.score; 
}


int main(void){
  
    /*
    int a[10] = {9, 3, 5, 4, 1, 10, 8, 6, 7, 2};

    // address of first value & last value
    sort(a, a+10);

    for( int i = 0; i <10; i++){
        cout << a[i] << ' ';
    }

    */

    Student students[] = {
        Student ("예원", 100),
        Student ("병현", 0),
        Student ("정은", 90)
    } ;

    sort(students, students + 2);

    for( int i =0 ; i < 3 ; i ++){
        cout << students[i].name << ' ';
    }
}