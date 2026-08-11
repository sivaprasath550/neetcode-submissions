class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
       vector<vector<int>> adj(n);
       vector<bool> vis(n, false);
       
       int cnt = 0;

       for(auto &e : edges){
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
       }
       
       for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt++;
            
            queue<int>q;
            q.push(i);
            vis[i] = true;

            while(!q.empty()){
               int curr = q.front();
               q.pop();

               for(int next : adj[curr]){
                  if(!vis[next]){
                    q.push(next);
                    vis[next] = true;
                  }
                }
            }
        }
    }
    return cnt;
    }
};
