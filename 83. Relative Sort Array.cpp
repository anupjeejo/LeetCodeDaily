class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> mp(1001, 0);
        int n = arr1.size();
        int m = arr2.size();
        
        for(int i=0; i<n; i++)
            mp[arr1[i]]++;

        int ctr1 = 0;
        for(int i=0; i<m; i++)
        {
            while(mp[arr2[i]] > 0)
            {
                arr1[ctr1++] = arr2[i];
                mp[arr2[i]]--;
            }
        }

        int ctr2 = 0;
        while(ctr2<1001)
        {
            while(mp[ctr2] > 0)
            {
                arr1[ctr1++] = ctr2;
                mp[ctr2]--;
            }
            ctr2++;
        }

        return arr1;
    }
};