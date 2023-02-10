#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2)
    {
        unordered_map<int,int>m;
        for(int i=0;i<basket1.size();i++)
        {
            int k=basket1[i];
            m[k]++;
        }
        for(int i=0;i<basket2.size();i++)
        {
            int k=basket2[i];
            m[k]--;
        }
        for(auto it=m.begin();it!=m.end();it++)
        cout<<it->first<<" "<<it->second<<endl;
        vector<int>arr1,arr2;
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it->second==0)
            continue;
            if(abs(it->second)%2!=0)
            return -1;
            else
            {
                if(it->second>0)
                {
                    for(int j=0;j<abs(it->second)/2;j++)
                    arr1.push_back(it->first);
                }
                else
                {
                    for(int j=0;j<abs(it->second)/2;j++)
                    arr2.push_back(it->first);
                }
            }
        }
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end(),greater<int>());
        if(arr1.size()!=arr2.size())
        return -1;
        int c=0;
        for(int i=0;i<arr1.size();i++)
        {
            c=c+min(arr1[i],arr2[i]);
        }
        return c;
    }
};

int main()
{
    Solution s;
    vector<int> basket1={2,4,3,1},basket2={3,2,5,1};
    cout<<s.minCost(basket1,basket2)<<endl;
}