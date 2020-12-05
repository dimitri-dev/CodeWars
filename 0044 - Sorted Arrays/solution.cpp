#include <algorithm>

int nthSmallest(std::vector<std::vector<int>> arr, int n)
{
    std::vector<int> finalVec;
    for (auto x : arr)
      for (auto y : x)
        finalVec.push_back(y);
  
    sort(finalVec.begin(), finalVec.end());
    
    return finalVec[n - 1];
}