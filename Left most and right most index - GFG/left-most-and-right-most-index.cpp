//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int firstIdx(vector<long long>nums, long long target){
        int l = 0, h = nums.size() - 1, ans = -1;
        while(l <= h){
            int mid = l + (h-l)/2;
            if(nums[mid] < target){
                l = mid + 1;
            }else if(nums[mid] > target){
                h = mid - 1;
            }else{
                if(mid == 0 || nums[mid] != nums[mid -1]){
                    return mid;
                }else{
                    h = mid - 1;
                }
            }
        }
        return ans;
    }
    int lastIdx(vector<long long>nums, long long target){
        int l = 0, h = nums.size() - 1, ans = -1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            if(nums[mid] > target){
                h = mid - 1;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                if(mid == nums.size() - 1 || nums[mid] != nums[mid + 1]){
                    return mid;
                }else{
                    l = mid + 1;
                }
            }
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x)
    {
        // code here
        pair<long,long>p1;
        p1.first = firstIdx(v, x);
        if(p1.first == -1){
            p1.second = -1;
        }else{
            p1.second = lastIdx(v, x);    
        }
        return p1;
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends