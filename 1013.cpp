/**
 * 给定一个地图， 图中有n个城市， 求不经过其中一个城市需要额外修几条路
 * 思路：
 *      使用邻接矩阵和dfs， 遍历时跳过给定的城市， 从而求出连通分量的数量， 需要额外修的路的数量 = 连通分量-1
 */


#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

/*
  g: 图
  n：图的节点数
  i：要遍历的节点号
  visit： visit数组
*/
void dfs(vector<vector<int> > &g, int n, int i, vector<bool> &visit, int c){
//    cout << i <<  endl;
    visit[i] = true;
    for(int j = 0; j < n; j++){
        if((g[i][j] != 0 && visit[j] ==0 && j != c )){
            dfs(g, n, j, visit, c);
        }
    }
}


int solve(vector<vector<int> > &g, int c, int n){
    // bfs
    vector<bool> visit(n, false);
    int turn = 0;
    for(int i = 0; i < n; i++){
        if(visit[i] == false && i != c){
            turn++;
            dfs(g, n, i, visit, c);
        }
    }
    return turn - 1 ;
}

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<int> > g(n, vector<int>(n, 0));
    int x,y;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        x--; y--;
        g[x][y] = 1;
        g[y][x] = 1;
    }
    int c;
    for(int i = 0; i < k; i++){
        cin >> c;
        c--;
        cout << solve(g, c, n) << endl;
    }
    return 0;
}