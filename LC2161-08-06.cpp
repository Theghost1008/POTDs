#include <bits/stdc++.h>
using namespace std;

/*Thinking - 
Initally thought of using two vectors, first for all the values less than "pivot"
and second for all the values greater than "pivot". The solution was simple - 
to iterate over "nums" and check for values less than "pivot"->equal to pivot->
greater than "pivot" and add the elements to the answer array.Then merge
the elements equal to "pivot" at the end of 'less than array' and merge
the 'greater than' array at the end of 'less than + equal' array using stl functions
 Then thought of space optimization to decrease one array and using only single array to do the above
operation using three loops on the same ans array.
*/

//Initial solution
// class Solution {
// public:
//     vector<int> pivotArray(vector<int>& nums, int pivot) {
//         vector<int> ans,great;
//         int cnt=0;
//         int n=nums.size();
//         for(int i=0;i<n;i++){
//             if(nums[i]<pivot)
//                 ans.push_back(nums[i]);
//             else if(nums[i]>pivot)
//                 great.push_back(nums[i]);
//             else 
//                 cnt++;
//         }
//         for(int i=0;i<cnt;i++)
//             ans.push_back(pivot);
//         ans.insert(ans.end(),great.begin(),great.end());
//         return ans;
//     }
// };

//Final solution
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<pivot)
                ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]==pivot)
                ans.push_back(nums[i]);
        }
        for(int i=0;i<n;i++){
            if(nums[i]>pivot)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> ans;
    vector<int> nums={-3,4,3,2};
    ans=s.pivotArray(nums,2);
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<endl;
    return 0;
}