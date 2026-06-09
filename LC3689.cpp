#include <bits/stdc++.h>
using namespace std;

//Solution development
// class Solution {
// public:
//     void maxTotalValue(vector<int>& nums, int k) {
//         vector<int> vals;
//         int maxi=nums[0],mini=nums[0];
//         int ans=0;
//         for(int i=1;i<nums.size();i++){
//             if(nums[i]<mini)
//                 mini=nums[i];
//             if(nums[i]>maxi)
//                 maxi=nums[i];
//             ans=max(ans,maxi-mini);
//             vals.push_back(ans);
//         }
//         for(int i=0;i<vals.size();i++)
//             cout<<vals[i]<<endl;
//         int best = *max_element(vals.begin(),vals.end());
//         cout<<"Answer is: "<<best*k<<endl;
//     }
// };


//Actual Solution
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        vector<long long> vals;
        int maxi=nums[0],mini=nums[0];
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<mini)
                mini=nums[i];
            if(nums[i]>maxi)
                maxi=nums[i];
            ans=max(ans,(long long)maxi-mini);
            vals.push_back(ans);
        }
        long long best = *max_element(vals.begin(),vals.end());
        return best*(long long)k;
    }
};

int main(){
    Solution s;
    vector<int> nums={4,2,5,1};
    long long ans = s.maxTotalValue(nums,3);
    cout<<"Answer is: "<<ans<<endl;
    return 0;
}