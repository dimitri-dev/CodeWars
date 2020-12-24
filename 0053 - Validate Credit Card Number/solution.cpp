#include <cmath>

class Kata {
  public:
  static bool validate(long long int n) {
    long long int sum = 0;
    while (n > 0) {
      int a = n % 10;
      n = floor(n / 10);
      
      int b = (n % 10) * 2;
      n = floor(n / 10);
      if (b > 9) b -= 9;
      
      sum += a + b;
    }
    return sum % 10 == 0;
  }
};