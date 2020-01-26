/**
 *
 * 桶排序
 *
 */


#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> v(10001, 0);
    vector<int> arr;
    int a;
    for(int i = 0; i < n; i++){
        cin >> a;
        v[a]++;
        arr.push_back(a);
    }
    bool f = false;
    for(int i = 0; i < n; i++ ){
        if(v[arr[i]] == 1){
            cout << arr[i];
            f = true;
            break;
        }
    }
    if(f == false){
        cout << "None" << endl;
    }
    return 0;
}