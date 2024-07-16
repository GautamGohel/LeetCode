class Solution {
public:
    int singleNumber(vector<int>& arr) {

    //brute force O(n2)     
    //      int n = arr.size();
    // for (int i = 0; i < n; i++) {
    //     int num = arr[i];
    //     int cnt = 0;
    //     for (int j = 0; j < n; j++) {
    //         if (arr[j] == num)
    //             cnt++;
    //     }
    //     if (cnt == 1) return num;
    // }
    // return -1;
    //hashing O(3n) O(max(arr))
    // int n=arr.size();
    // int maxi=0;
    // for(int i=0;i<n;i++){
    //     maxi=max(maxi,arr[i]);
    // }
    // vector<int>hash(maxi+1,0);
    // for(int i=0;i<n;i++){
    //     hash[arr[i]]++;
    // }
    // for(int i=0;i<n;i++){
    //     if(hash[arr[i]]==1)
    //     return arr[i];
    // }
    // return -1;

    //using map  tc O(nlogn +m) sc O(m)
    // int n = arr.size();
    // map<int, int> mpp;
    // for (int i = 0; i < n; i++) {
    //     mpp[arr[i]]++;
    // }

    // for (auto it : mpp) {
    //     if (it.second == 1)
    //         return it.first;
    // }
    // return -1;

    //using bitwise operator    
    int XOR=0;
    for(int i=0;i<arr.size();i++){
        XOR=XOR^arr[i];
    }
    return XOR;
    }
};