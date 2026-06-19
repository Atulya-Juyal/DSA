class Solution {
public:
    bool possible(vector<int>& position, int m, int dist){
        int cnt = 1;
        int last = position[0];

        for(int i : position){
            if(i - last >= dist){
                cnt++;
                last = i;
            }
        }

        return cnt >= m;
    }


    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        
        int l = 1;
        int r = position[position.size()-1] - position[0];

        while(l <= r){
            int mid = l + (r-l)/2;
            int t = possible(position, m, mid);

            if(t) l = mid + 1;
            else r = mid - 1;
        }

        return r;
    }
};