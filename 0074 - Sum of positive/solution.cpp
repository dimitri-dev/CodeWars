#include <vector>
#include <numeric>

int positive_sum (const std::vector<int> arr){
  return (int)accumulate(arr.begin(), arr.end(), 0, [&](int x, int y){ if (y > 0) x+=y; return x;});
}