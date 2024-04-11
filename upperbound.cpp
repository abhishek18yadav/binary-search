#include<bits/stdc++.h>
using namespace std;
vector<int>a;
int up(int x){
    int lo=0;
    int hi= a.size()-1;
    int ans = 0;
    while(lo<=hi){
        int mid= lo + (hi-lo)/2;
        if(a[mid]<=x){
            lo=mid+1;
        }else{
            ans=mid;
            hi=mid-1;
        }
    }
    return ans;
}
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.
    if(arr[n-1]<=x)return n;
    else{
        a=arr;	
        return up(x);
    }
}
int main(){
    vector<int>arr{1,5,7,8,10};
    int x=7;
    int n = arr.size();
    cout<<upperBound(arr,x,n);
    return 0;
}