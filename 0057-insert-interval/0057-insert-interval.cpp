class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size(),nis=newInterval[0],nie=newInterval[1],ms,me; bool overlap_phase=false,merge_completed=false;
        vector<vector<int>>res;
        if(n>0 && nie<intervals[0][0]){
            merge_completed=true;
            res.push_back(newInterval);
        }
        for(int i=0;i<n;i++){
            if(merge_completed){
                res.push_back(intervals[i]);
            }
            else if(!overlap_phase){
                if(nis<=intervals[i][1]){
                    if(nie<intervals[i][0]){
                        merge_completed=true;
                        res.push_back(newInterval);
                        res.push_back(intervals[i]);
                    }else{
                        overlap_phase=true;
                        ms=min(nis,intervals[i][0]);
                        me=max(nie,intervals[i][1]);
                    }
                }else{
                    res.push_back(intervals[i]);
                }
            }else{
                if(me>=intervals[i][0]){
                    me=max(me,intervals[i][1]);
                }else{
                    overlap_phase=false;
                    merge_completed=true;
                    res.push_back({ms,me});
                    res.push_back(intervals[i]);
                }
            }
        }
        if(!merge_completed && !overlap_phase){
            res.push_back(newInterval);
        }
        else if(!merge_completed && overlap_phase){
            res.push_back({ms,me});
        }
        return res;
    }
};