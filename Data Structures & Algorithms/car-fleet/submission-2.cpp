class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
       int n = position.size();
       vector<pair<int, double>> cars;
       double maxTime = 0;
       int fleet = 0;

       for(int i = 0; i < n; i++){
         double time = (double)(target - position[i]) / speed[i];
         cars.push_back({position[i], time});
       }

       sort(cars.rbegin(), cars.rend());

       for(int i = 0; i < cars.size(); i++){
        double time = cars[i].second;

        if(time > maxTime){
           maxTime = time;
           fleet++;
        }
       }
       return fleet;
    }
};
