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

/* Thinking - 
At the first i thought of using sliding window for subarrays but it didnt make sense
so i dropped the idea. Then the problem statement said - "max(nums[l..r])-min(nums[l..r])";
that clicked the thinking of using "maxi" and "mini" variables to track maximum and minimum
values in a subarray. I initialized maxi = nums[0] and mini = nums[0] (first element of
the array), then i iterated the array index by index comparing current element with "maxi"
and "mini" and repalcing them with each successfull comapring(if "nums[i]" {current elemt}
 is found greater than "maxi" then replace "maxi" with "nums[i]" and do the similar for
 "mini". Then store the "value" - "maxi"-"mini" to be pushed in a "ans" vector that contains
 the "value" of the subarrays already sorted in ascending order. The as said we can repeat
 a subarray to we chose the maximum element from the "ans" array and then multiply it by
 "k" to get the final answer)
*/
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