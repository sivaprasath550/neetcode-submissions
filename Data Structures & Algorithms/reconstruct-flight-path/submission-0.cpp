class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> ans;
    
    void dfs(string airport){
        auto& pq = adj[airport];

        while(!pq.empty()){
            string next = pq.top();
            pq.pop();
            dfs(next);
        }

        ans.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

       for(auto& ticket: tickets){
         adj[ticket[0]].push(ticket[1]);
       }

       dfs("JFK");

        reverse(ans.begin(), ans.end());
        return ans;
    }
};