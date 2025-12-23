class Solution {
    public:
    int countLessEqual(vector<int>& arr, int x) {
        // code here
        int res=0;
        for(auto i : arr){
            if(i<=x){
                res+=1;
            }
        }
        return res;
    }
};
