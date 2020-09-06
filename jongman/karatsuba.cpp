#include <iostream>
#include <vector>

using namespace std;

/* 카라츠바 곱셉 알고리즘 */

void normalize(vector<int>& num) 
{
	num.push_back(0);

	int size = num.size();
	for (int i = 0; i < size - 1; i++)
	{
		if (num[i] < 0)
		{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
}

//a += b*(10^k)
void addTo(vector<int>& a, const vector<int>& b, int k)
{
    // b * 10^k 100 -> 1000 , a 10 (01)
    int originalASize = a.size(); // 2

    if( a.size() < b.size() + k ){
        a.resize(b.size()+k); // a,size = 2-> 4, 0100
    }
    // a+b*10^k 과정 중 혹시 모를 자리 올림을 위해서
    a.push_back(0); // 01000
    
    /*
    int aSize = a.size();
    for( int i = originalASize ; i < aSize ; i++ ){
        a[i] = 0; // 0으로 초기화해줄라하ㅡ는건데 딱히 안해도 될듯?
    }
    */

    int bSize = b.size();
    for( int i = 0; i < bSize ; i++)
        a[ i+k ] += b[i];

    normalize(a);

}

// a -= b ( Suppose a > b )
void subFrom(vector<int>& a, const vector<int>& b){
    int bSize = b.size();

    for( int i = 0 ; i < bSize ; i ++){
        a[i] -= b[i];
    }
    normalize(a);
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b){
    int an = a.size(), bn = b.size();

    if( an < bn ) return karatsuba(b, a);

    if( an == 0 || bn == 0 ) return vector<int> ();

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() +half);
    vector<int> a1(a.begin() + half, a.end());
    
    // b < a 이기 때문에  b의 size가 a의 half보다 작을 수 있음
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    // half의 승끼리 두 번 곱하므로 지수는 half + half
    vector<int> z2 = karatsuba(a1, b1);
    vector<int> z0 = karatsuba(a0, b0);

    // a0 = a0 + a1
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);

    vector<int> z1 = karatsuba(a0, b0);

    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half+half);

    return ret;
}

/*코드 7.9*/
int hugs(const string& members, const string& fans){

    vector<int> star, fan;
    for(int i = 0 ; i < members.size() ; i++ ) star[i] = (members[i]=='M');
    for(int i = 0 ; i < fans.size(); i++) fan[i] = (fans[i] == 'M');
    
    vector<int> result = karatsuba(star, fan);

    int ret = 0;

    for(int i = members.size()-1 ; i < fans.size() ; i++ ){ // == waiting
        if(result[i] == 0)
            ret++;
    }

    return ret;

}

int main(void){
    vector<int> a, b;
    
    // a = 1 
    a.push_back(1);

    // b = 10 -> 01 in array
    b.push_back(0);
    b.push_back(1);

    // 1 + 10 * 10^1 = 1 + 100 = 101
    addTo(a, b, 1);

    for( int i = 0 ; i < a. size() ; i++)
        cout << i << "th : " << a[i] << endl;
}