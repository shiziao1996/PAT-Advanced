#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int k;
    cin >> k;
    vector<int> v(k,0);
    for(int i = 0; i < k; i++){
        cin >> v[i];
    }
    
    vector<int>dp(v);
    int max = dp[0];
    int cur_begin = 0;
    int cur_end = 0;
    int begin = 0;
    int end = 0;
    for(int i = 1; i < k; i++){
        if(dp[i-1] < 0){
            dp[i] = v[i];
            cur_begin = i;
            cur_end = i;
        }        
        else{
            dp[i] = dp[i-1] + v[i];
            cur_end = i;
        }
        if(dp[i] > max){
            max = dp[i];
            begin = cur_begin;
            end = cur_end;
        }             
    }
    if(max < 0){
        cout << 0 << " " << v[0] << " " << v[k-1] << endl;
    }
    else{
        cout << max <<" "<< v[begin] << " " << v[end] << endl;
    }
    
    return 0;
}