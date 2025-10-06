#include<bits/stdc++.h>
using namespace std;
#include<vector>

class Solution {
  public:
    void find(vector<int> &arr,int index,vector<vector<int>> &ans){
        if(index>=arr.size()){
           ans.push_back(arr);
           return ;
        }
        int i = index; 
        for(int i = index;i<arr.size();i++){
           bool shouldSwap = true;
        for(int j = index;j<i;j++){
            if(arr[j] == arr[i]){
                shouldSwap = false;
                break;
            }
        }
          if(shouldSwap){
              swap(arr[i],arr[index]);
              find(arr,index+1,ans);
              //backtracking
              swap(arr[i],arr[index]);
          }
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        sort(arr.begin(),arr.end());
         vector<vector<int>> ans;
         int index = 0;
         find(arr,index,ans);
         sort(ans.begin(),ans.end());
         return ans;
    }
};
