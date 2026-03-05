class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        map<int,int> mp;
        int l =0;
        int r = 0;
        int n= s.size();
        int ans =-1;
        while(r < n) {
            mp[s[r]]++;
            if (mp.size() == k) ans = max(ans,r-l+1);
                
            else if (mp.size()>k) {
                mp[s[l]]--;
                if (!mp[s[l]]) mp.erase(s[l]);
                l++;
                mp[s[r]]--;
                r--;
            }
            r++;
        }
       
        return ans;
        // code here
        
    }
};
