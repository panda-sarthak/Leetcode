class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> umap; 
        for(int i=0;i<nums.size();i++){
            if(umap.find(target-nums[i])==umap.end()){
                umap[nums[i]]=i;
                continue;
            }else{
                auto it=umap.find(target-nums[i]);
                res.push_back(it->second);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};