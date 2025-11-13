class Solution {
public:
    int maxOperations(string s) {
        int n = s.length(), ans = 0;
        for(int i = 0, cnt = 0; i < n; i++, cnt++){
            if(s[i] == '0'){
                ans += cnt;
                while(i < n && s[i] != '1') i++;
            }
        }
        return ans;
    }
};
