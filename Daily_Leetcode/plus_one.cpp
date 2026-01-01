class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int n=arr.size(),c=0,ct=0;
        for(int i=0;i<n;i++){
            if(arr[i]==9)ct++;
        }
        if(ct==n) {
            vector<int> ac;
            ac.push_back(1);
            for(int i=0;i<n;i++){
                ac.push_back(0);
            }
            return ac;
        }
        int temp=0;
        for(int i=n-1;i>=0;i--){
            if(arr[i]==9){
                arr[i]=(1+arr[i])%10;
                c=1;
                temp=i;
            }
            else if(arr[i]!=9 and c==1){
                arr[i]+=1;
                break;
            }
            // else if(c==1){
            //     arr[i]+=1;
            //     break;
            // }
            else if(c==0){
                arr[i]+=1;
                break;
            }
        }
        // if(c==1 and temp!=0){
        //     arr[temp-1]+=1;

        // }
        return arr;
    }
};
