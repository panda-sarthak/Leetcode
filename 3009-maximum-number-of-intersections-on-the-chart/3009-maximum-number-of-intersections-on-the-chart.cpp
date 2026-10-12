class Solution {
public:
    int maxIntersectionCount(vector<int>& y) {//max interval stabbing point prob., think intervals by projrction on y axis
        vector<pair<int,int>>events;//timestamp,delta
        int n=y.size();
        for(int i=0;i<n-1;i++){
            //int u=y[i],v=y[i+1];
            // Double the coordinates to simulate evaluating midpoints (e.g., Y = 1.5)
            int u=2*y[i],v=2*y[i+1];
            if(i<n-2){
                if(u<v){
                    events.push_back({u,1});//included start
                    events.push_back({v,-1});//excluded end
                }
                else{
                    events.push_back({v+1,1});//excluded start
                    events.push_back({u+1,-1});//included end
                }
            }
            else{
                if(u<v){
                    events.push_back({u,1});//included start
                    events.push_back({v+1,-1});//included end
                }
                else{
                    events.push_back({v,1});//included start
                    events.push_back({u+1,-1});//included end
                }
            }
        }
        sort(events.begin(),events.end());
        int best_shot=-1,curr_delta=0,max_delta=INT_MIN;
        for(int i=0;i<events.size();){
            curr_delta+=events[i].second; int curr_time=events[i].first; i++;
            while(i<events.size() && events[i].first==curr_time){
                curr_delta+=events[i].second;i++;
            }
            if(curr_delta>max_delta){
                max_delta=curr_delta;
                best_shot=curr_time;
            }
        }
        return max_delta;
    }
};