class Solution {
public:

int solve(int index,vector<string> &ans,vector<string> &arr)
    {
        if(index>=arr.size()) return 0;

        ans.push_back(arr[index]);
        unordered_map<char,int> m;
        for(int i=0;i<ans.size();i++)
        {
            for(int j=0;j<ans[i].size();j++) 
                m[ans[i][j]]++;
        }

        bool flag=1;
        for(auto &val:m)
        {
            if(val.second>1)
            {
                flag=0;
                break;
            }
        }
        
        int opt1=0,opt2=0;
        if(flag) opt1=arr[index].size()+solve(index+1,ans,arr);
        ans.pop_back();
        opt2=solve(index+1,ans,arr);

        return max(opt1,opt2);
    }

    int maxLength(vector<string>& arr) {
        vector<string> ans;
        return solve(0,ans,arr);
    }

    // int helper(string &fullStr, int currIdx, vector<int> &charCount)
    // {
    //     if(currIdx == 0)
    //     {
    //         charCount[fullStr[currIdx]-'a']++;
    //         if(charCount[fullStr[currIdx]-'a'] > 1)
    //         {
    //             charCount[fullStr[currIdx]-'a']--;
    //             return 0;
    //         }

    //         return 1;
    //     }

    //     bool isUnique = true;

    //     charCount[fullStr[currIdx]-'a']++;
    //     if(charCount[fullStr[currIdx]-'a'] > 1)
    //     {
    //         charCount[fullStr[currIdx]-'a']--;
    //         isUnique = false;
    //     }

    //     int ans1 = (isUnique ? 1 : 0) + helper(fullStr, currIdx-1, charCount);
    //     int ans2 = helper(fullStr, currIdx-1, charCount);

    //     return max(ans1, ans2);
    // }

    // int maxLength(vector<string>& arr) {
    //     string fullStr = "";
    //     int result = 0;
    //     int n = arr.size();

    //     if(arr.size() == 1)
    //     {
    //         vector<int> charCount(26, 0);
    //         return helper(arr[0], (arr[0].size())-1, charCount);
    //     }

    //     for(int i=0; i<n; i++)
    //     {
    //         for(int j=i+1; j<n; j++)
    //         {
    //             vector<int> charCount(26, 0);
    //             fullStr = arr[i] + arr[j];
    //             cout<<"fullStr: "<<fullStr<<endl;
    //             int len = fullStr.size();
    //             result = max(result, helper(fullStr, len-1, charCount));
    //         }
    //         fullStr = "";
    //     }

    //     return result;
    // }
};