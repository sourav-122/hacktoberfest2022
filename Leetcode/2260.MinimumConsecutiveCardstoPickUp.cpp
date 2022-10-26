#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {

        vector<int> v(1000001);
        for (int i = 0; i < 1000001; i++)
        {
            v[i] = -1;
        }
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (v[cards[i]] == -1)
            {
                v[cards[i]] = i;
            }
            else
            {
                ans = min(ans, i - v[cards[i]] + 1);
                v[cards[i]] = i;
            }
        }
        return ans != INT_MAX ? ans : -1;
    }
};