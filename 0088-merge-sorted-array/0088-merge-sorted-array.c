void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int arr1[m+5] = {};
    for(int i=0;i<m;i++){
        arr1[i] = nums1[i];
    }
    
    int start = 0;
    int left = 0, right = 0;
    while(left<m && right < nums2Size){
        // printf("left %d\n", left);
        if(arr1[left]<=nums2[right]){
            nums1[start++] = arr1[left++];
        }
        else{
            nums1[start++] = nums2[right++];
        }
    }
    while(left<m){
        nums1[start++] = arr1[left++];
    }
    while(right < nums2Size){
        nums1[start++] = nums2[right++];
    }
}