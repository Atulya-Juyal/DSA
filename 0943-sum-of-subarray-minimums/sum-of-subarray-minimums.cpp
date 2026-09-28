class Solution {
public:
    vector<int> findNSE(vector<int>& arr){
        vector<int> nse(arr.size());
        stack<int> stk;

        for(int i = arr.size()-1; i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] >= arr[i]) stk.pop();

            if(stk.empty()) nse[i] = arr.size();
            else nse[i] = stk.top();

            stk.push(i);
        }

        return nse;
    }

    vector<int> findPSEE(vector<int>& arr){
        vector<int> psee(arr.size());
        stack<int> stk;

        for(int i = 0; i < arr.size(); i++){
            while(!stk.empty() && arr[stk.top()] > arr[i]) stk.pop();

            if(stk.empty()) psee[i] = -1;
            else psee[i] = stk.top();

            stk.push(i);
        }

        return psee;
    }

    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse = findNSE(arr);
        vector<int> psee = findPSEE(arr);

        long long mod = 1e9 + 7;
        long long res = 0;

        for(int i = 0; i < arr.size(); i++){
            long long l = i - psee[i];
            long long r = nse[i] - i;

            long long contri = ((l * r) % mod) * (arr[i] % mod);

            res =  (res + contri) % mod;
        }

        return res;
    }
};