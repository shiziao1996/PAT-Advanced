#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


bool isPrime(int n){
    // 0 和 1 不是质数 
    if(n == 0 || n == 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++){
        if(n%i ==0)
            return false;
    }
    return true;
}

int reverse(int n, int d){
    vector<int> v;
    while(n){
        v.push_back(n%d);
        n = n/d;
    }
    int result = 0;
    int e = 0;
    for(int i = v.size() - 1; i >= 0; i--){
        result = result + v[i] * pow(d,e);
        e++;
    }
    return result;
}

int main(){
    int N;
    while(scanf("%d", &N) == 1 && N >= 0){
        int D;
        cin >> D;
        if(isPrime(N)){
            N = reverse(N, D);
            if(isPrime(N)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
}