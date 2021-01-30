#include <numeric>
#define vI std::vector<int>

int josephusSurvivor(int n, int k) {
  if (n == 1) return 1;
  vI v(n);
  std::iota(std::begin(v), std::end(v), 1);
  
  int pos = 0;
  while (v.size() > 1) {
      pos += k - 1;
      pos %= v.size();
      v.erase(v.begin() + pos);
  }
  
  return v[0];
}