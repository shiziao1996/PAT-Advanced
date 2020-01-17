#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

struct record{
    string id;
    int h1;
    int m1;
    int s1;
    int h2;
    int m2;
    int s2;
};

int main(){
    int n; cin >> n;
    record r1 = {"", 23, 59, 59, 0, 0, 0};
    record r2 = {"", 0, 0, 0, 0, 0, 0};
    record r;
    for(int i = 0; i < n; i++){
        cin >> r.id;
        scanf("%d:%d:%d %d:%d:%d", &r.h1, &r.m1, &r.s1, &r.h2, &r.m2, &r.s2); 
        if(r.h1 < r1.h1) r1 = r;
        if(r.h1 == r1.h1 && r.m1 < r1.m1) r1 = r;
        if(r.h1 == r1.h1 && r.m1 == r1.m1 && r.m1 < r1.m1) r1 = r;
        if(r.h2 > r2.h2) r2 = r;
        if(r.h2 == r2.h2 && r.m2 > r2.m2)  r2 = r;
        if(r.h2 == r2.h2 && r.m2 == r2.m2 && r.m2 > r2.m2) r2 = r;
    }

    cout << r1.id << " " << r2.id << endl;

    return 0;
}