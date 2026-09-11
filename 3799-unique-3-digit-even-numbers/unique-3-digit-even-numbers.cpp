class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> fre(10, 0);
        for(int i : digits) fre[i]++;
        vector<int> temp = fre;

        int res = 0;

        for(int i = 100; i < 1000; i+=2){
            int n = i;
            bool flag = true;

            while(n){
                int j = n % 10;

                if(temp[j] != 0){
                    temp[j]--;
                }
                else{
                    flag = false;
                    break;
                }
                
                 n /= 10;
            }
            temp = fre;

            if(flag) res++;
        }

        return res;
    }
};