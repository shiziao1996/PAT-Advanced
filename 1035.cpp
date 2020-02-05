/**
 1 -> @
 0 -> %
 l -> L
 O->o   */

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    string name;
    string pwd;
    vector<string> names;
    vector<string> pwds;
    vector<bool> isModified(n, false);
    for(int i = 0; i < n; i++){
        cin >> name >> pwd;
        names.push_back(name);
        pwds.push_back(pwd);
    }
    int m = 0;
    for(int i = 0; i < n; i++){
        int len = pwds[i].length();
        bool f = false;
        for(int j = 0; j < len; j++){
            if(pwds[i][j] == '1' || pwds[i][j] == '0' || pwds[i][j] == 'l' || pwds[i][j] == 'O') f = true;
            if(pwds[i][j] == '1') pwds[i][j] = '@';
            if(pwds[i][j] == '0') pwds[i][j] = '%';
            if(pwds[i][j] == 'l') pwds[i][j] = 'L';
            if(pwds[i][j] == 'O') pwds[i][j] = 'o';
        }
        if(f){
            isModified[i] = true;
            m++;
        }
            
    }
    if( m == 0){
        if(n == 1) cout << "There is 1 account and no account is modified" << endl;
        if(n > 1 ) cout << "There are " << n << " accounts and no account is modified" << endl;
    }
    else {
        cout << m << endl;
        for(int i = 0; i < n; i++){
            if(isModified[i] == true){
                cout << names[i] << " " << pwds[i] << endl;
            }
        }
    }
    return 0;
}
