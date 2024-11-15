class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int p=0;
        for(int i=0; i<n-1; i++){
            if(arr[i] <= arr[i+1]){
                p++;
            }
            else break;
        }
        if(p==n-1)
            return 0;

        int q=n-1;
        for(int i=n-1; i>=0; i--){
            if(arr[i-1] <= arr[i]){
                q--;
            }
            else break;
        }    
        int ans=min(n-p-1,q);
        // int x=-1;
        // for(int i=0; i<=p; i++){
        //     if(arr[i] <= arr[q]){
        //         x++;
        //     }
        //     else break;
        // }
        // int y=n;
        // for(int i=n-1; i>=q; i--){
        //     if(arr[i] >= arr[p]){
        //         y--;
        //     }
        //     else break;
        // }
        // if(x != -1)
        //     ans = min(ans,q-x-1);
        // if(p>0 && q<n-1){
        //     if(arr[p-1]<=arr[q+1])
        //         ans=min(ans,q-p+1);
        // }    
        // if(y != n)
        //     ans = min(ans,y-p-1);  
        int i=0, j=q;
        while(i<=p && j<n){
            if(arr[i]<=arr[j]){
                ans=min(ans,j-i-1);
                i++;
            }
            else j++;
        }      

        // cout<<p<<' '<<q<<' '<<x<<' '<<y;
        return ans;
    }
};