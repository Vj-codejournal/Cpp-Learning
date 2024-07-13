//linear space opt




#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}



// Binary

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2 = nums2.size();
        if(n1 > n2) return findMedianSortedArrays(nums2,nums1);//first array should be smaller
        int low = 0,high = n1;
        int left = (n1 + n2 +1)/2;
        int n = n1+n2;
        while(low <= high){
            int mid1 = (low+high) >> 1;//div by 2
            int mid2 = left - mid1;
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            if(mid1<n1) r1 = nums1[mid1];
            if(mid2<n2)r2 = nums2[mid2];
            if(mid1 -1 >=0)l1 = nums1[mid1-1];
            if(mid2 - 1 >=0) l2 = nums2[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2 ==1)return max(l1,l2);
                return ((double)(max(l1,l2)+ min(r1,r2)))/ 2.0;
            }
            else if(l1>r2) high = mid1-1;
            else low = mid1+1;


        }
        return 0;
    }
};

//linear
//while loop like when we merge two arr then see side if even 2 element in middle mid+1/2 and mid/2 and if odd only mid/2

