class TimeMap {
public:
unordered_map<string, vector<pair<int, string>>> mpp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       mpp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
       if(mpp.find(key) == mpp.end()) return "";
       
       string ans = "";
       auto &v = mpp[key];

       int low = 0, high = v.size() - 1;

       while(low <= high){
        int mid = low + (high - low) / 2;

        if(v[mid].first <= timestamp){
            ans = v[mid].second;
            low = mid + 1;
        }

        else high = mid - 1;
       }
       return ans;
    }
};
