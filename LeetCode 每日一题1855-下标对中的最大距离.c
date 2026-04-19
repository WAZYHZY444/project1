int maxDistance(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int i=0,j=0;
    int cur=0;
    int max=0;
    while(i<nums1Size&&j<nums2Size){
        if(nums1[i]<=nums2[j]){
            cur=j-i;
            if(cur>max){
                max=cur;
            }
            j++;
        }else{
            i++;
        }
    }
    return max;
}

//注意：如果条件提到数组有序，就可以考虑把暴力双循环改成双指针单循环
//非递增数组=递减数组