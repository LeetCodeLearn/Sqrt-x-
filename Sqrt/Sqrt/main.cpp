//
//  main.cpp
//  Sqrt
//
//  Created by 李佳 on 15/10/21.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 0)
            return 0;
        if (x == -0)
            return -0;
        
        int start = 0;
        int end = x / 2;
        int mid = std::max((start + end) / 2, 1);
        
        while(start < end && mid)
        {
            int minValue = x / mid;
            if (minValue == mid)
                return mid;
            if (minValue < mid)
            {
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
            mid = (start + end) / 2;
        }
        if (mid * mid > x) mid--;
        return mid;
        
        /* from discuss
        int low = 0,  high = x, mid;
        if(x<2) return x; // to avoid mid = 0
        while(low<high)
        {
            mid = (low + high)/2;
            if(x/mid >= mid) low = mid+1;
            else high = mid;
        }
        return high-1;
         */
    }
    
    
    /*
     
     long r = x;
     while (r * r > x)
     r = (r + x / r) / 2;
     return r;
     
     */
};


int main(int argc, char* argv[])
{
    Solution* pSol = new Solution;
    while (argc-- > 1)
    {
        int value = atoi(*++argv);
        printf("Sqrt(%d) = %d\n", value, pSol->mySqrt(value));
    }
    printf("pow(2, 31) = %f", pow(2, 31));
    printf("pow(2, 31) = %f", pow(2, 15.5));
    printf("Sqrt(%d) = %d\n", 100, pSol->mySqrt(2));
    printf("Sqrt(%d) = %d\n", 100, pSol->mySqrt(2147483647));
    
    delete pSol;
    return 0;
}