class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int result = 0;
        int lptr = 0;
        int rptr = people.size()-1;
        
        sort(people.begin(), people.end());

        while(lptr<=rptr)
        {
            int totalWeight = people[lptr] + people[rptr];
            if(totalWeight <= limit)
                lptr++;
            rptr--;
            result++;
        }

        return result;
    }
};