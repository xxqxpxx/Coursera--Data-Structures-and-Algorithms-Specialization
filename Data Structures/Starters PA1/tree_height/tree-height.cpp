#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TreeHeight {
int n;
vector<int> parent;
vector<int> adj[100001];

public:
void read() {
        std::cin >> n;
        parent.resize(n);
        for (int i = 0; i < n; i++)
                std::cin >> parent[i];
}

int compute_height_helper(int node) {
        int ret = 1;
        for(int i=0; i<adj[node].size(); i++) {
                cout << node << " " << i << endl;
                cout << adj[node][i] << endl;
                ret = max(ret, 1 + compute_height_helper(adj[node][i]));
        }
        return ret;
}

int compute_height() {
        int root = -1;
        for(int i=0; i<n; i++) {
                if(parent[i] == -1) {
                        root = i;
                }else{
                        adj[parent[i]].push_back(i);
                }
        }
        return compute_height_helper(root);
}
};

int main() {
        std::ios_base::sync_with_stdio(0);
        TreeHeight tree;
        tree.read();
        std::cout << tree.compute_height() << std::endl;
}
