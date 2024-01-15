class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> result;
        vector<int> unbeaten;
        vector<int> lostOnce;
        unordered_map<int, int> playerWin;
        int n = matches.size();

        for(int i=0; i<n; i++)
        {
            playerWin[matches[i][0]];
            playerWin[matches[i][1]]++;
        }

        for(auto player : playerWin)
        {
            if(player.second == 0)
                unbeaten.push_back(player.first);

            if(player.second == 1)
                lostOnce.push_back(player.first);
        }

        sort(unbeaten.begin(), unbeaten.end());
        sort(lostOnce.begin(), lostOnce.end());

        result.push_back(unbeaten);
        result.push_back(lostOnce);

        return result;
    }
};