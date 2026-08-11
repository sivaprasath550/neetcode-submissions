class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
      if(edges.size() != n - 1) return false;

      vector<vector<int>> adj(n);

      for(auto &e : edges){
        int first = e[0];
        int second = e[1];

        adj[first].push_back(second);
        adj[second].push_back(first);
      }

      queue<int> q;
      vector<bool> vis(n, false);

      q.push(0);
      vis[0] = true;

      int completed = 0;

      while(!q.empty()){
        int curr = q.front();
        q.pop();

        completed++;

        for(int next : adj[curr]){

            if(!vis[next]){
              vis[next] = true;
              q.push(next);
            }
        }
      }
      return completed == n;
    }
};
