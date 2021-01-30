#include <cmath>

unsigned long long solution ( unsigned long long n ) {
  if (n % 2) return 1;
  
  int x = log2(n);
  unsigned long long div;
  for (div = pow(2, x); (n % div != 0); div /= 2);
  return div;
}