/**
 * 一个电梯上升一个楼层需要6s，下降一个楼层需要4s， 每次停顿需要5s
 * 有一系列请求，要求计算出电梯运行总时间
 * 
 */

#include <iostream>

using namespace std;

int main(){
    int N;
    cin >> N;
    int result = 0;
    int cur = 0;
    int next;
    for(int i = 0; i < N; i++){
        cin >> next;
        if(next > cur){
            result = result + (next-cur)*6 + 5;
        }
        if(next < cur){
            result = result + (cur-next)*4 + 5;
        }
        if(next == cur){
            result = result + 5;
        }
        cur = next;
    }
    cout << result << endl;


    return 0;
}