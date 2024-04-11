// https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
#include<bits/stdc++.h>
using namespace std;

    bool ispresent(vector<int>& nums,int mid, int p){
    int count=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i+1]-nums[i]<=mid){
            count++;
            i++;
        }
    }
    return (count>=p);
}
int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi= abs(nums[0]-nums[nums.size()-1]);
        int ans =0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(ispresent(nums,mid,p)){
                ans=mid;
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        return ans;
}

int main(){
    vector<int>nums{4,2,1,2};
    int p=1;
    cout<<minimizeMax(nums,p);
    return 0;
}
