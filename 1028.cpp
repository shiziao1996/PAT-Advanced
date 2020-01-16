#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

struct Stu{
    int id;
    string name;
    int grade;
};

bool sort1(const Stu &s1, const Stu &s2){
    return s1.id < s2.id;
}

bool sort2(const Stu &s1, const Stu &s2){
    if(s1.name == s2.name)
        return s1.id < s2.id;
    return s1.name < s2.name;
}

bool sort3(const Stu &s1, const Stu &s2){
    if(s1.grade == s2.grade)
        return s1.id < s2.id;
    return s1.grade < s2.grade;
}

int main(){
    int n, c;
    cin >> n >> c;
    vector<Stu> v;
    for(int i = 0; i < n; i++){
        Stu s;
        cin >> s.id >> s.name >> s.grade;
        v.push_back(s);
    }
    if(c == 1) sort(v.begin(), v.end(), sort1);
    else if (c == 2) sort(v.begin(), v.end(), sort2);
    else sort(v.begin(), v.end(), sort3);

    for(int i = 0; i < n; i++){
        printf("%06d ", v[i].id);
        cout << v[i].name << " " << v[i].grade << endl;
    }
    return 0;
}