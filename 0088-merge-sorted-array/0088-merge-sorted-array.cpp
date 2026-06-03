class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;

        // Compare from the back and place the largest element at 'p'
        while (p1 >= 0 && p2 >= 0) {
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--; // Always move the placement pointer left
        }

        // Catching the leftovers
        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};

// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int l = 0, r = 0;

//         if(n==0) return;
//         while(l < (m+n) && r < n){
//             if(nums1[l] <= nums2[r]){
//                 l++;
//                 // continue;
//             }else{
//                 nums1[l+1] = nums1[l];
//                 nums1[l] = nums2[r];
//                 l++;
//                 r++;
//             }
//         }

//         l -= (n - r + 1);
//         while(r < n){
//             nums1[l] = nums2[r];
//             l++;
//             r++;
//         }
//     }
// };