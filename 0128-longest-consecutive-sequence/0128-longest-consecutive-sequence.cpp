class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();
       set<int>st;
       int maxi=0;
       for(int i=0;i<n;i++){
        st.insert(nums[i]);
       }
       for(auto it:st){
          if(st.find(it-1)==st.end()){
            int cnt=1;
            int x=it;
            while(st.find(x+1)!=st.end()){
                cnt++;
                x++;
            }
            maxi=max(maxi,cnt);
          }
       }
       return maxi;
    }
};