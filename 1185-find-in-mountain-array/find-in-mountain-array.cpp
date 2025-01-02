/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int j=-1;
        int lo=0;
        int len=mountainArr.length();
        int hi=len-1;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            int el=mountainArr.get(mid);
            int left=mountainArr.get(mid-1);
            int right=mountainArr.get(mid+1);

            if(left<el && el>right){
                j=mid;
                break;
            }

            if(left<el && el<right){
                lo=mid;
            }
            else{
                hi=mid;
            }
        }
        cout<<j<<' ';
        int u=0,v=j;
        
        while(u<=v){
            int mid=(u+v)/2;
            int el=mountainArr.get(mid);

            if(el==target){
                return mid;
            }

            if(el>target){
                v=mid-1;
            }
            else{
                u=mid+1;
            }
        }

        int p=j,q=len-1;

        while(p<=q){
            int mid=(p+q)/2;

            int el=mountainArr.get(mid);

            if(el==target){
                return mid;
            }
            if(el>target){
                p=mid+1;
            }
            else{
                q=mid-1;
            }
        }

        return -1;

    }
};