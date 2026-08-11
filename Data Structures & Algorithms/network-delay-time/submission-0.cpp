class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       // build adj list
       unordered_map<int, vector<pair<int, int>>> adjList;
       for(auto& edge : times){
        adjList[edge[0]].push_back({edge[1], edge[2]});
       }

       priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

       vector<int> dist(n + 1, INT_MAX);
       dist[k] = 0;
       pq.push({0, k});

       while(!pq.empty()){
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto& [v, w] : adjList[u]){
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
       } 
       // finding maximum

       int maxi = 0;
       for(int i = 1; i <= n; i++){
        if(dist[i] == INT_MAX) return -1;
        maxi = max(maxi, dist[i]);
       }

       return maxi;
    }
};
