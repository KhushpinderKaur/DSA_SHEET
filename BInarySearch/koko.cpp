#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool predicate(int k, int h, vector<int>& piles) {
        long long totalHours = 0; 
        for (int v : piles) {
            totalHours += ((long long)piles[v] + k - 1) / k; 
        }
        return totalHours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); 
        int ans = 0;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (predicate(mid, h, piles)) {
                ans = mid;      
                high = mid - 1;
            } else {
                low = mid + 1;   
            }
        }
        return ans;
    }
};

int main() {
    int n, h;

    cout << "Enter number of piles: ";
    cin >> n;

    vector<int> piles(n);
    cout << "Enter piles: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }

    cout << "Enter hours (h): ";
    cin >> h;

    Solution obj;
    int result = obj.minEatingSpeed(piles, h);

    cout << "Minimum eating speed: " << result << endl;

    return 0;
}