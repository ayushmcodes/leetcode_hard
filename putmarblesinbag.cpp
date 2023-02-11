#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long putMarbles(vector<int>& weights, int k)
    {
        if(weights.size()==2)
        return 0;
        if(weights.size()==3)
        return abs(weights[0]-weights[2]);

        int npairs=k-1;
        vector<int>vec;

        for(int i=0;i<=weights.size()-2;i++)
        {
            int a=weights[i]+weights[i+1];
            vec.push_back(a);
            cout<<a<<" ";
        }

        cout<<endl;

        sort(vec.begin(),vec.end(),greater<int>());

        for(int i=0;i<vec.size();i++)
        cout<<vec[i]<<" ";
        cout<<endl;

        int maxsum=weights[0]+weights[weights.size()-1];
        int minsum=weights[0]+weights[weights.size()-1];

        for(int i=0;i<npairs;i++)
        {
            maxsum=maxsum+vec[i];
        }
        cout<<maxsum<<endl;

        int i=vec.size()-1;

        while(npairs--)
        {
            minsum=minsum+vec[i];
            i--;
        }

        cout<<minsum<<endl;

        return (maxsum-minsum);
    }
};

int main()
{
    Solution s;
    vector<int>w={1,3,5,1};
    int k=2;
    cout<<s.putMarbles(w,k);
}