class Solution {
public:
    int maxArea(vector<int>& a) {
        int n=a.size(),mx=-1;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         mx=max(mx,min(a[i],a[j])*(j-i));
        //     }
        // }
        
        int low=0, high=n-1;
        while(low<=high){
            mx=max(mx,(min(a[low],a[high]))*(high-low));
            if(a[low]<a[high]){
                low++;
            }
            else high--;
        }
        return mx;
    }
};
