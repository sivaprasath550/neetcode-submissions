class Solution {
public:
vector<int>parent;

int find(int x){
    if(parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unionSet(int a, int b){
    int rootA = find(a);
    int rootB = find(b);

    if(rootA == rootB) return false;
    parent[rootA] = rootB;
    return true;
}

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);

        for(int i = 1; i < n; i++)
          parent[i] = i;

          for(auto& edge: edges){
            if(!unionSet(edge[0], edge[1])){
                return edge;
            }
          }
        return {};
    }
};
