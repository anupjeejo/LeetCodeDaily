class Solution {
public:
    
    int NumSplitSum(int num)
    {
        int sum = 0;

        while(num != 0)
        {
            sum += num%10;
            num /= 10;
        }

        return sum;
    }

    int getLucky(string s, int k) 
    {
        int result = 0;

        for(auto ch : s)
        {
            int num = ch - 'a' + 1;
            result += num >= 10 ? 
                        NumSplitSum(num):
                        num;
        }

        while(k>1)
        {
            int temp = result;
            result = 0;
            result = NumSplitSum(temp);
            k--;
        }

        return result;
    }
};