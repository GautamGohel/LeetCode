class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
        
        int l = 0, h = n1, left = (n1 + n2 + 1) / 2;
        while (l <= h) {
            int mid1 = (l + h) / 2;
            int mid2 = left - mid1;
            
            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;
            
            if (l1 > r2) {
                h = mid1 - 1; 
            } else if (l2 > r1) {
                l = mid1 + 1; 
            } else {
                if ((n1 + n2) % 2 == 1) {
                    return max(l1, l2); 
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;  
                }
            }
        }
        return 0.0;  
    }
};
