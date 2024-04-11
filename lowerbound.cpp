#include<bits/stdc++.h>
using namespace std;


vector<int>a;
int lb(int x){
	int lo = 0;
	int hi = a.size()-1;
	int ans=0;
	while(lo<=hi){
		int mid = lo + (hi-lo)/2;
		if(a[mid]<x){
			lo=mid+1;
		}else{
			ans = mid;
			hi=mid-1;
		}
	}
	return ans;
}
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	a=arr;
	int ans= lb(x);
	return ans;
}

int main(){
    vector<int>arr{1,2,2,3,3,5};
    int n = arr.size();
    int x=2;
    cout<<lowerBound(arr,n,x);
    return 0;
}