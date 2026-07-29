class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size()/2;
        vector<int> fre(26);

        for(int i = 0; i < n; i++){
            fre[s[i] - 'a']++;
        }

        string firstHalf = "";

        for(int i = 0; i < 26; i++){
            while(fre[i]){
                firstHalf.push_back(i + 'a');
                fre[i]--;
            }
        }
    	string extraMiddle = (s.size() % 2 == 1) ? string(1, s[n]) : "";

        string secondHalf = firstHalf;
        reverse(secondHalf.begin(), secondHalf.end());

        string res = firstHalf + extraMiddle + secondHalf;

        return res;
    }
};