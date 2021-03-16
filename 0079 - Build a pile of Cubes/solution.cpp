#include <numeric>
class ASum
{
  public:
  static long long findNb(long long m) {
     long long s = 1, n = 2;
     while (s < m) {
       s += (n * n * n);
       ++n;
     }
     return (s == m) ? (n - 1) : -1;
  }
};