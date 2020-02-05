#include <iostream>
#include <cmath>
#include <string>
#include <stdio.h>
#include <climits>
using namespace std;
typedef long long L;
L convertToDecimal(const string &n, const L &radix){
    L sum = 0;
    int len = n.length();
    for(int i = 0; i < len; i++){
        char c = n[i];
        int number;
        if(c>='0' && c<='9')
            number = c - '0';
        else
            number = c - 'a' + 10;
        sum = sum*radix + number;
    }
    return sum;
}

int compare1(L a, string b){
    int result = -1;
    L m;
    for(int i = 2; i <= 36; i++){
        m = convertToDecimal(b, i);
        if(a == m)
            return i;
    }
    return result;
}
// 二分法计算十进制数a是否能由?进制的b表示
void compare2(const L &a, const string &b, const L &left, const L &right, int &result){
    if(left > right) return;
    L mid = (left + right)/2;
    L m = convertToDecimal(b,mid);
    if(a > m){
        compare2(a, b, mid+1, right, result);
    }
    if(a == m){
        result = mid;
        return;
    }
    if(a < m){
        compare2(a, b, left, mid -1, result);
    }


}
int main(){
    string n1;
    string n2;
    int tag;
    L radix;
    cin >> n1 >> n2 >> tag >> radix;
    int result =-1;
    L m;
    if(tag == 1){
        m = convertToDecimal(n1, radix);
        result = compare1(m, n2);
        if(result == -1)
            compare2(m, n2, 2, m, result);
    }
    if(tag == 2){
        m = convertToDecimal(n2, radix);
        result = compare1(m, n1);
        if(result == -1)
            compare2(m, n1, 2, m, result);
    }
    if(result == -1) cout << "Impossible" << endl;
    else cout << result << endl;
    return 0;
}
