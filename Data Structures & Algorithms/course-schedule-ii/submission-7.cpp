class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> adj(numCourses);
       vector<int> ans;

      vector<int> indegree(numCourses, 0);

      for(auto &p : prerequisites){
        int course = p[0];
        int prereq = p[1];

        adj[prereq].push_back(course);
        indegree[course]++;
      }

      queue<int> q;

      for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
           q.push(i);
        } 
      }

      int completed = 0;

      while(!q.empty()){
        int curr = q.front();
        ans.push_back(curr);
        q.pop();

        completed++;

        for(int next : adj[curr]){
            indegree[next]--;

            if(indegree[next] == 0){
                q.push(next);
            }
        }
      }

      if(ans.size() != numCourses) return {};
      return ans;    
    }
};
