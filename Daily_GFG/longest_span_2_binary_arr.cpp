class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        int n=a1.size();
        map<int,int>mp;
        mp[0]=-1;
        int sum1=0,sum2=0,maxlen=INT_MIN;
        for(int i=0;i<n;i++){
            sum1+=a1[i],sum2+=a2[i];
            if(mp.find(sum1-sum2)!=mp.end()){
                maxlen=max(maxlen,i-mp[sum1-sum2]);
            } else {
                mp[sum1-sum2]=i;
            }
        }
        return maxlen==INT_MIN ? 0 : maxlen;
    }
};
