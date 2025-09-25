#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isReachable(vector<int> path)
    {
        int max_reach = 0;
        int targetIndex = path.size() - 1;
        for (int i = 0; i < targetIndex; i++)
        {
            if (i > max_reach)
                return false;
            max_reach = max(max_reach, i + path[i]);
            if (max_reach >= targetIndex)
                return true;
        }
        return max_reach >= targetIndex;
    }
};

int main(void)
{

    Solution sol;
    vector<vector<int>> paths = {{2, 3, 1, 1, 4}, {3, 2, 1, 0, 4}, {2, 0, 0}, {0}, {1, 0, 0, 0}, {1, 2, 3}, {1, 0, 1, 0}};
    for (const auto &path : paths)
    {
        cout << "Path: ";
        for (int step : path)
        {
            cout << step << " ";
        }
        cout << "=> Reachable: " << sol.isReachable(path) << endl;
    }
}