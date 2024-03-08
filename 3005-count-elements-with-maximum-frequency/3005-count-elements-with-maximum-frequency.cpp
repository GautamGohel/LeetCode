class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
  map<int , int>m;
  int c= 0;
  int max = 0;
  for(int i = 0; i<nums.size();i++){
    m[nums[i]]++;
  

    if(m[nums[i]]>max){
      max=m[nums[i]];
      c=0;
    }

      if(m[nums[i]]==max)
      c++;
  }

return c*max;
        
}
};