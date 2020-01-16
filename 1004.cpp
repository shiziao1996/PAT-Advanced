/*
输入：
第一行： N  M
        N：结点个数
        M：非叶节点个数
下面M行每行： 节点的编号id， 这个节点的孩子数量k， 这个节点的孩子的编号id*k

9 3
1 3 2 3 4
2 2 10 11
4 3 6 8 9

输出：每一层的叶节点数量
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

typedef struct TreeNode{
    vector<int> childs;
}TreeNode;



int main(){
    int n, m;
    cin >> n >> m;
    vector<TreeNode> nodes(100, TreeNode());
    int id, k, childNum;
    for(int i = 0; i < m; i++){
        cin >> id >> k;
        for(int j = 0; j < k; j++){
            cin >> childNum;
            nodes[id].childs.push_back(childNum);
        }
    }

    queue<TreeNode* > q;
    q.push(&nodes[1]);
    TreeNode *p;
    ostringstream ss;
    while(!q.empty()){
        int leaves = 0;
        int q_len = q.size();
        for(int i = 0; i < q_len; i++){
            p = q.front();
            q.pop();
            int childNum = p->childs.size();
            if(childNum == 0){
                leaves++;
            }
            else{
                for(int j = 0; j < p->childs.size(); j++)
                    q.push(&nodes[p->childs[j]]);
            }
        }
        ss << leaves << " ";
    }
    string line = ss.str();
    line.erase(line.end()-1, line.end());
    cout << line;
    return 0;
}