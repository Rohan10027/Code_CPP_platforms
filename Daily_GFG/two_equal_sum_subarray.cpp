class Solution {
  public:
    bool canSplit(vector<int>& arr) {

       

        int n = arr.size();

        int l=0;

        int r = n-1;

        

        if(n<2) return false;

        

        int lsum =arr[l];

        int rsum = arr[r];

        while(l+1!=r){

            

            

            if(lsum<rsum){

                lsum += arr[++l];

            }

            else{

                rsum += arr[--r];

            }

            

        }

        

        return lsum==rsum;

    }
};
