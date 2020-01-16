/*
输入：
第一行：城市数量N 道路数量M 城市1C1 城市2C2
第二行：每个城市点急救队数量
剩下M行(路)：城市1， 城市2， 长度

输出：
一行： C1到C2不同最短路径的数量   能集结点最多救援队的数量

INPUT:
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1

OUTPUT:
2 4


*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;




int main(){
    int n, m, c1, c2;
    cin >> n >> m >> c1 >> c2;
    vector<int> w(n, 0);
    for(int i = 0; i < n; i++)
        cin >> w[i];
    vector<vector<int> > g(n, vector<int>(n, INT_MAX));
    for(int i = 0; i < n; i++){
        g[i][i] = 0;
    }
    for(int i = 0; i < m; i++){
        int x, y, val;
        cin >> x >> y >> val;
        g[x][y] = val;
        g[y][x] = val;
    }

    vector<int> D;
    for(int i = 0; i < n; i++){
        D[i] = g[0][i];
    }
    if(c1 > c2) swap(c1, c2);
    for(int i = 0; i < n; i++){
        
    }
    


}