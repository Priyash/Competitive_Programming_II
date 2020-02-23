#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    Solution(){}    
    vector<int> sortByBits(vector<int> &arr);
};

vector<int> Solution::sortByBits(vector<int>& arr)
{
    sort(arr.begin(), arr.end(), [](const int &a, const int &b) {
        int countA = __builtin_popcount(a);
        int countB = __builtin_popcount(b);
        return countA == countB ? a < b : countA < countB;
    });

    return arr;
}


int main()
{
    Solution* sol = new Solution();
    vector<int> in = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> result = sol->sortByBits(in);

    return 0;
}
