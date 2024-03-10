class Solution {
public:

    void check(vector<int> &vis1, vector<int> &vis2, int target, vector<int> &result)
    {
        if(vis1[target] == 2)
            return;
        
        if(vis1[target] == 0)
            vis1[target] = 1;

        if(vis1[target] == 1 && vis2[target] == 1)
        {
            result.push_back(target);
            vis1[target] = 2;
            vis2[target] = 2;
        }
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> vis1(1001, 0);
        vector<int> vis2(1001, 0);
        vector<int> result;
        int n = nums1.size();
        int m = nums2.size();
        int ctr1 = 0;
        int ctr2 = 0;

        while(ctr1 < n || ctr2 < m)
        {
            if(ctr1 < n)
            {
                check(vis1, vis2, nums1[ctr1], result);
                ctr1++;
            }

            if(ctr2 < m)
            {
                check(vis2, vis1, nums2[ctr2], result);
                ctr2++;
            }
        }

        return result;
    }
};