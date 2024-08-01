class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int result = 0;

        for(auto detail : details)
        {
            int temp1 = detail[11] - '0';
            int temp2 = detail[12] - '0';
            int age = (temp1 * 10) + temp2;

            if(age > 60)
                result++;
        }

        return result;
    }
};