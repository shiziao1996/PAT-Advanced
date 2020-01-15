#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int N = s.length();
    int n1 = (N+2)/3;
    int n2 = N - 2*n1 + 2;
    string s1 = s.substr(0, n1-1);
    string s2 = s.substr(n1-1, n2);
    string s3 = s.substr(n1 + n2 - 1);
    reverse(s3.begin(), s3.end());
    for(int i = 0; i < s1.size(); i++){
        cout << s1[i];
        for(int j = 0; j < n2-2; j++){
            cout << " ";
        }
        cout << s3[i] << endl;

    }
    cout << s2 << endl;
    return 0;
}