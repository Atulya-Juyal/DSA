class Solution {
public:

    int findMax(vector<int>& piles){
        int maxi = INT_MIN;
        for(int i : piles)
            maxi = max(maxi, i);
        return maxi;
    }

    long long totalHours(vector<int>& piles, int hr) {
        long long total = 0;

        for(int i : piles)
            total += ((long long)i + hr - 1) / hr;

        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int l = 1;
        int r = findMax(piles);

        while(l <= r){

            int m = l + (r-l)/2;

            long long t = totalHours(piles, m);

            if(t <= h)
                r = m - 1;
            else
                l = m + 1;
        }

        return l;
    }
};