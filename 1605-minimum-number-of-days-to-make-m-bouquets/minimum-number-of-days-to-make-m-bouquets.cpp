class Solution {
public:
    vector<int> findMinMax(vector<int>& bloomDay, int m, int k){
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i : bloomDay){
            mini = min(mini, i);
            maxi = max(maxi, i);
        }

        return {mini, maxi};
    }


    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt = 0;
        int noOfBo = 0;

        for(int i : bloomDay){
            if(day >= i){
                cnt++;
            }
            else{
                noOfBo += cnt/k;
                cnt = 0;
            }
        }

        noOfBo += cnt/k;

        return noOfBo >= m;
    }


    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> mm = findMinMax(bloomDay, m, k);
        int l = mm[0];
        int r = mm[1];

        if(bloomDay.size() < 1LL * m * k) return -1;

        while(l <= r){
            int mid = l + (r-l)/2;
            bool t = possible(bloomDay, mid, m, k);
            
            if(t) r = mid - 1;
            else l = mid + 1; 
        }

        return l;
    }
};