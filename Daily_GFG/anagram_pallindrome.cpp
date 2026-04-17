class Solution {
  public:
    bool canFormPalindrome(string &s) {
        // code here
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        int odd=0;
        for( auto &it : mp){
            if(it.second & 1) odd++;
        }
        return odd<=1;
    }
};
