class Solution {
public:
    int removeDuplicates(vector<int>&a) {
        /*
      set<int>st;
      for(int i=0;i<a.size();i++){
        st.insert(a[i]);
      }
      int i=0;
      for(auto it:st){
        a[i]=it;
        i++;
      }
      return i;*/
      int i=0;
      for(int j=1;j<a.size();j++){
        if(a[j]!=a[i]){
            a[i+1]=a[j];
            i++;
        }
      }
      return i+1;
    }
};
