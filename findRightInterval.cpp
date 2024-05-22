#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-right-interval/
//  is is valid for +ve testcases , with little modification it will be perfect , right now batery is going to dead

#define pp pair<int,int>

    bool cmp(pp x , pp y){
        return (x.first < y.first);
    }
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n= intervals.size();
        unordered_map<int,pp>mp;
        for(int i=0; i<n; i++){        //  {{3,4},{2,3},{1,2}};
            mp[intervals[i][0]]={intervals[i][1], i};
        }
        vector<pp>v(n);
        for(int i=0; i<intervals.size(); i++){
            v.push_back({intervals[i][0],i});
        }
        sort(v.begin(),v.end(),cmp);
        
        vector<int>res(n);

        int idx= INT_MAX;
        for( auto ele : mp){
            idx= INT_MAX;
            int target = ele.second.first;
            int left = 0;
            int right = v.size()-1;                            // {{3,4},{2,3},{1,2
            while(left<= right){                               // v 123
                int mid=left+(right-left)/2;
                cout<<mid;
                if(v[mid].first < target){
                    cout<<"n";
                    left = mid+1;
                }
                else{
                    idx= min(idx , v[mid].second);
                    right = mid-1;
                }
                cout<<"loopend"<<" ";
            }
            if(idx==INT_MAX){
                res[ele.second.second]=-1;
            }else{
                res[ele.second.second]=idx;
            }
        }
        return res;
    }


int main(){                        
    vector<vector<int>>intervals{{-100,-98},{-99,-97},{-98,-96}};
    vector<int>res=findRightInterval(intervals);
    // for(int i=0; i<res.size(); i++){
    //     cout<<res[i]<<" ";
    // }
    return 0;
}