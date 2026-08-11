class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> vis(n, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

        minHeap.push({0, 0});

        int totCost = 0;
        int pointsAdd = 0;

        while(pointsAdd < n){
            auto[cost, i] = minHeap.top();
            minHeap.pop();

            if(vis[i]) continue;

            vis[i] = true;
            totCost += cost;
            pointsAdd++;

            for(int j = 0; j < n; j++){
                if(!vis[j]){
                    int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                    minHeap.push({dist, j}); 
                }
            }
        }
        return totCost;
    }
};
