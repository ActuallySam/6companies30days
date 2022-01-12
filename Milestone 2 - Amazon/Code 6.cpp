// Maximum of all subarrays of size k

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        vector<int> v;
       multiset<int,greater<int>> s;
       for(int i=0;i<n;i++){
           s.insert(arr[i]);
           if(s.size()>k){
               s.erase(s.find(arr[i-k]));
           }
           if(s.size()==k){
               v.push_back(*s.begin());
           }
       }
       return v;
    }
};