class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int total = n1 + n2;
        int half = total / 2;
        int lo = 0, hi = n1;
        while (lo <= hi) {
            int mid1 = lo + (hi - lo) / 2;
            int mid2 = half - mid1;

            int l1 = mid1 > 0 ? nums1[mid1 - 1] : INT_MIN;
            int l2 = mid2 > 0 ? nums2[mid2 - 1] : INT_MIN;
            int r1 = mid1 < n1 ? nums1[mid1] : INT_MAX;
            int r2 = mid2 < n2 ? nums2[mid2] : INT_MAX;

            if (l1 > r2) {
                hi = mid1 - 1;
            } else if (r1 < l2) {
                lo = mid1 + 1;
            } else {
                if ((n1 + n2) % 2 == 0) {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                } else {
                    return min(r1, r2);
                }
            }
        }

        return -1;
    }
};
