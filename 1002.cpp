#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

void solution(map<double,double, greater<double> > &m1, map<double,double> &m2, int n1, int n2){
    map<double, double> result;
    for(map<double, double>::iterator it = m2.begin(); it != m2.end(); it++){
        m1[it->first] = it->second + m1[it->first];
    }

    for(map<double, double>::iterator it = m1.begin(); it != m1.end(); it ++){
        if(it->second == 0.0){
            m1.erase(it);
        }
    }

    cout << m1.size();
    if(m1.size()==0){
        cout << endl;
        return;
    }
	else 
		cout << " ";

    for(map<double, double>::iterator it = m1.begin(); it != m1.end(); it ++){
        map<double, double>::iterator f = it; f++;
        if(f == m1.end()){
            printf("%.0f %.1f", it->first, it->second);
        }
        else{
            printf("%.0f %.1f ", it->first, it->second);
        }
    }
    cout << endl;
}



int main() {
    int n1;
    double e, c;
    while(scanf("%d", &n1)==1){
        map<double, double, greater<double> > m1;
        for(int i = 0; i < n1; i++){
            cin >> e >> c;
            m1[e] = c;
        }
        int n2;
        cin >> n2;
        map<double, double> m2;
        for(int i = 0; i < n2; i++){
            cin >> e >> c;
            m2[e] = c;
        }
        solution(m1, m2, n1, n2);
    }
}
