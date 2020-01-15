#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int a, b, sum;
    cin >> a >> b;
    sum = a + b;
    if(sum < 0){
        cout << "-";
        sum = -sum;
    }
    string s = std::to_string(sum);
    reverse(s.begin(), s.end());
    int i = 1;
    for(auto it = s.begin(); it != s.end(); it++){
        auto temp = it; temp++;
        if((i%3) == 0 && temp != s.end()){
            s.insert(temp, ',');
            it++;
        }
        i++;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;


    return 0;
}
