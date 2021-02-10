#include <set>

class TwoToOne
{
public:
    static std::string longest(const std::string &s1, const std::string &s2) {
        std::set<char> se;
        se.insert(s1.begin(),s1.end());
        se.insert(s2.begin(),s2.end());
        
        return std::string(se.begin(),se.end());
    }
};