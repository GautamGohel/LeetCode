class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int s=intervals[0][0];
        int e=intervals[0][1];
        vector<vector<int>>ans;
        for(int i=1;i<n;i++){
           if(intervals[i][0]<=e){
             s=min(intervals[i][0],s);
             e=max(intervals[i][1],e);
           }else{
             ans.push_back({s,e});
             s=intervals[i][0];
             e=intervals[i][1];
           }
        }
        ans.push_back({s,e});
        return ans;
    }
};