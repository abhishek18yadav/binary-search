// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
    int[]n;
    public int ub(int target){
        int lo = 0;
        int hi = n.length-1;
        int ans=-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(n[mid]<=target){
                if(n[mid]==target)ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        return ans;
    }
    public int lb(int target){
        int lo = 0;
        int hi = n.length-1;
        int ans=-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(n[mid]<target){
                lo = mid+1;
            }else{
                if(n[mid]==target)ans= mid;
                hi=mid-1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        n=nums;
        int []res= new int[2];
        Arrays.fill(res,-1);
        res[0]= lb(target);
         res[1] = ub(target);
        return res;
    }
}