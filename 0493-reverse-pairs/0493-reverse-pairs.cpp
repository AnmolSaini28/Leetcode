class Solution {
public:
     void merge(vector<int>& arr, int l, int m, int r)
    {
        int n1 = m-l+1;
        int n2 = r-m;
        int left[n1] , right[n2];
        for(int i=0 ; i<n1 ; i++){
            left[i] = arr[l+i];
        }
        for(int i=0 ; i<n2 ; i++){
            right[i] = arr[m+i+1];
        }
        int i=0 , j=0 , k=l;
        while(i<n1 && j<n2){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                k++;
                i++;
            }
            else{
                arr[k] = right[j];
                k++;
                j++;
            }
        }
        while(i<n1){
            arr[k] = left[i];
            k++;
            i++;
        }
        while(j<n2){
            arr[k] = right[j];
            k++;
            j++;
        }
    }
    int countpairs(vector<int>& arr, int l, int m, int h){
        int cnt = 0;
        int right = m+1;
        for(int i=l ; i<=m ; i++){
            while(right <= h && arr[i] > 2*(long long)arr[right]){
                right++;
            }
            cnt += (right-(m+1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& arr, int l, int r)
    {
        int cnt = 0;
        if (l >= r) return cnt;
        int m = l + (r-l)/2;
        cnt += mergeSort(arr,l,m);
        cnt += mergeSort(arr,m+1,r);
        cnt += countpairs(arr,l,m,r);
        merge(arr,l,m,r);
        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums,0,nums.size()-1);
    }
};