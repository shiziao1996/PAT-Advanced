#include <iostream>
#include <vector>

using namespace std;

bool isPalin(vector<int> &v){
    int len = v.size();
    for(int i = 0; i < len/2; i++){
        if(v[i] != v[len-i-1])
            return false;
    }
    return true;
}


int main(){
    int N, b;
    cin >> N >> b;
    vector<int> v;
    while(N){
        v.insert(v.begin(), N%b);
        N = N/b;
    }
    isPalin(v)? cout << "Yes" : cout << "No";
    cout << endl;
    for(int i = 0; i < v.size()-1; i++){
        cout << v[i] << " ";
    }
    cout << v[v.size() - 1] << endl;
    return 0;
}