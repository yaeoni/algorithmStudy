using namespace std;

int solution(int X, int Y, int D) {
    // write your code in C++14 (g++ 6.2.0)
    int answer = (Y-X) / D;
    return (Y-X) % D == 0 ? answer : answer+1; 
}