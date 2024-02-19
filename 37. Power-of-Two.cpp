class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;

        // while(n != 0)
        // {
        //     if(n == 1) return true;
        //     if(n%2 == 1) return false;
        //     n = n/2;
        // }

        // return true;

        // if(n<=0) return false;
        // return ( (n&(n-1)) == 0);

        int setBit = 0;

        for(int i=0; i<31; i++)
        {
            if(n & 1) setBit++;
            n>>=1;
        }

        return setBit == 1;
    }
};