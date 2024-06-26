class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long XOR=0;
        for(int i=0;i<n;i++){
            XOR=XOR^nums[i];
        }
        int rightbit=(XOR&(XOR-1))^XOR;
        int b1=0,b2=0;
        for(int i=0;i<n;i++){
            if(rightbit&nums[i]){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
       return {b1,b2};
    }
};