class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       vector<int> freq(26, 0);

       for(char t : tasks){
        freq[t - 'A']++;
       }

       priority_queue<int> pq;
       for(int f : freq){
        if(f > 0) pq.push(f);
       }

       int time = 0;

       while(!pq.empty()){

        vector<int> temp;
        int cycle = n + 1;

        while(cycle > 0 && !pq.empty()){
            int top = pq.top(); pq.pop();

            if(top - 1 > 0) temp.push_back(top - 1);

            time++;
            cycle--;
        }

        for(int i : temp){
            pq.push(i);
        }

        if(!pq.empty()){
            time += cycle;
        }
       }

       return time; 
    }
};
