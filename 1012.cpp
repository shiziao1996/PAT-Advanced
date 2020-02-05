#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct stu{
    int id;
    int c;
    int m;
    int e;
    int a;
    int cr;
    int mr;
    int er;
    int ar;
};
bool cmpc(const stu &s1, const stu &s2){
    return s1.c > s2.c;
}
bool cmpm(const stu &s1, const stu &s2){
    return s1.m > s2.m;
}
bool cmpe(const stu &s1, const stu &s2){
    return s1.e > s2.e;
}
bool cmpa(const stu &s1, const stu &s2){
    return s1.a > s2.a;
}
bool cmpid(const stu &s1, const stu &s2){
    return s1.id < s2.id;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<stu> v;
    int id, c, M, e, a;
    for(int i = 0; i < n; i++) {
        scanf("%d %d %d %d", &id, &c, &M, &e);
        a = (c + M + e) / 3;
        stu s;
        s.id = id;
        s.a = a;
        s.c = c;
        s.e = e;
        s.m = M;
        s.cr = 0;
        s.ar = 0;
        s.er = 0;
        s.mr = 0;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), cmpc);
    for(int i = 0; i < n; i++){
        v[i].cr = i+1;
    }
    sort(v.begin(), v.end(), cmpm);
    for(int i = 0; i < n; i++){
        v[i].mr = i+1;
    }
    sort(v.begin(), v.end(), cmpe);
    for(int i = 0; i < n; i++){
        v[i].er = i+1;
    }
    sort(v.begin(), v.end(), cmpa);
    for(int i = 0; i < n; i++){
        v[i].ar = i+1;
    }
    sort(v.begin(), v.end(), cmpid);
    stu *p[1000000] = {NULL};
    for(int i = 0; i < n; i++){
        p[v[i].id] = &v[i];
    }
    for(int i = 0; i < m; i++){
        cin >> id;
        if(p[id] == NULL){
            printf("N/A\n");
        } else {
            int maxr = p[id]->ar;
            char maxc = 'A';
            if(p[id]->cr > maxr){
                maxr = p[id]->cr;
                maxc = 'C';
            }
            if(p[id]->mr > maxr){
                maxr = p[id]->mr;
                maxc = 'M';
            }
            if(p[id]->er > maxr){
                maxr = p[id]->er;
                maxc = 'E';
            }
            printf("%d %c\n", maxr, maxc);
        }
    }
    return 0;
}
