class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> result(n , -1); 
        
        multiset<int> st; 
        for(int i =  0 ; i  < n; i++){
            st.insert(arr[i]);
            if(st.size() > k  ){
                st.erase(begin(st));
            }
            if(st.size() == k ){
                result[i] = *begin(st);
            }
        }
        return result; 
        
    }
};
