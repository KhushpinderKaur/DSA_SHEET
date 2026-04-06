#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int floorSqrt(int n)
    {

        // BRUTE FORCE
        /*
        int ans = 1;
        for(int i = 1; i <= n; i++){
            if(i * i <= n) ans = i;
            else break;
        }
        return ans;
        */

        // BINARY SEARCH
        int low = 1;
        int high = n / 2;
        int ans = 0;
        if (n == 0 || n == 1)   return n; 

        while (low <= high){
            int mid = low + (high - low) / 2;
       // Avoid overflow: use division instead of mid * mid
            if (mid <= n / mid){
                ans = mid;     
                low = mid + 1;
            }else
                high = mid - 1; 
        }
        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter number: ";
    cin >> n;

    Solution obj;
    int result = obj.floorSqrt(n);

    cout << "Floor square root of " << n << " is: " << result << endl;

    return 0;
}