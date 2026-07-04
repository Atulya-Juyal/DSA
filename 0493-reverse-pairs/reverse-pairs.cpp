class Solution {
public:
    int cnt = 0;

    void merge(vector<int>& arr, int l, int mid, int r){
        
        vector<int> temp;
        
        int i = l;
        int j = mid+1;
        
        while((i <= mid) && (j <= r)){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        
        while(j <= r){
            temp.push_back(arr[j]);
            j++;
        }
        
        for(int i = l; i < l+temp.size(); i++) arr[i] = temp[i-l];
    }

    void countReversePairs(vector<int>& arr, int l, int mid, int r){
        int right = mid + 1;
        for(int i = l; i <= mid; i++){
            while(right <= r && arr[i] > (2 * (double)arr[right])) right++;
            cnt += right - (mid + 1);
        }
    }
    
    void mergeSort(vector<int>& arr, int l, int r) {
        
        if(l >= r) return;
        int mid = l + (r - l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        countReversePairs(arr, l, mid, r);

        merge(arr, l, mid, r);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0
        , n-1);
        return cnt;
    }
};