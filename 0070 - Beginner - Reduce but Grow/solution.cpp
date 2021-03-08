#include <vector>
#include <numeric>
int grow(std::vector<int> v) {
  return std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
}