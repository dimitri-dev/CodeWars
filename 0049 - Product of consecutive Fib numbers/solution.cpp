#include <vector>
typedef unsigned long long ull;

class ProdFib {
public:
  static std::vector<ull> productFib(ull prod) {
      ull t1 = 0, t2 = 1, nextTerm = t1 + t2;

      while(t1*t2 <= prod)  {
        if (t1 * t2 == prod) return {t1, t2, true};
        
        t1 = t2; t2 = nextTerm; nextTerm = t1 + t2;
      }
    
      if (t1 * t2 > prod) return {t1, t2, false};
  }
};