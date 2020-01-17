#include <iostream>
#include <stdlib.h>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    // Input
    map<int, double> m1;
    map<int, double> m2;
    int n1, n2;
    cin >> n1;
    int e;
    double c;
    for(int i = 0; i < n1; i++){
        cin >> e >> c;
        m1[e] = c;
    }
    cin >> n2;
    for(int i = 0; i < n2; i++){
        cin >> e >> c;
        m2[e] = c;
    }

    // Solution
    int e1, e2, e3;
    double c1, c2, c3;
    map<int, double,greater<int> > m3;
    for(auto it1 = m1.begin(); it1 != m1.end(); it1++){
        e1 = it1->first;
        c1 = it1->second;
        for(auto it2 = m2.begin(); it2 != m2.end(); it2++){
            e2 = it2->first;
            c2 = it2->second;
            e3 = e2 + e1;
            c3 = c2 * c1;
            m3[e3] = c3 + m3[e3];
        }
    }
    // 删除系数=0
    for(auto it3 = m3.begin(); it3 != m3.end(); it3++){
        if(it3->second == 0.0){
            m3.erase(it3);
        }
    }
    //Output
    cout << m3.size();
    for(auto it3 = m3.begin(); it3 != m3.end(); it3++){
        printf(" %d %.1f", it3->first, it3->second);
    }
    cout << endl;
    return 0;
}