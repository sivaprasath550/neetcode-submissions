class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

      vector<int> indegree(numCourses, 0);
      vector<vector<int>> adj(numCourses);

      stack<int> st;
      queue<int> q;

      int completed = 0;
        
      for(auto p : prerequisites){
        int course = p[0];
        int pre = p[1];

        adj[pre].push_back(course);
        indegree[course]++;
      }

      for(int i = 0; i < numCourses; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
      }

      while(!q.empty()){
        int val = q.front();
        q.pop();
        
        completed++;

        for(int next : adj[val]){
            indegree[next]--;

            if(indegree[next] == 0){
                q.push(next);
            }
        }
      }

      return completed == numCourses;
    }
};
