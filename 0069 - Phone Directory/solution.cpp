#include <string>
using namespace std;
class PhoneDir {
public:
    static std::string removeShit(std::string lmao, std::string& name, std::string num) {
        for (long long i = 0, x = lmao.find(num), k = i; i < lmao.length(); ++i, x = lmao.find(num)) {
            char a = lmao[i];
            if (a == '_') lmao[i] = ' ';
            if (a == ';' || a == '!' || a == '?' || a == '|' || a == '/' || a == '+' || a == '*' || (lmao[i + 1] == ' ' && a == ' ') || a == '\n' || a == '$' || a == ',' || a == ':') { lmao.erase(lmao.begin() + i, lmao.begin() + i + 1); --i;}
            if (a == '<') {
                for (k = i++; lmao[k] != '>'; ++k);
                name = std::string(lmao.begin() + i, lmao.begin() + k);
                lmao.erase(lmao.begin() + i - 1, lmao.begin() + k + 1); --i;
            }
            if (i == x) { lmao.erase(lmao.begin() + x, lmao.begin() + x + num.length()); --i; }
        }
        for (int i = 0; i < lmao.length();) { if (lmao[i] != '\n' && lmao[i] != ' ' && lmao[i] != '/') break; lmao.erase(lmao.begin(), lmao.begin() + 1); }
        for (int i = lmao.length() - 1; i >= 0; --i) { if (lmao[i] != '\n' && lmao[i] != ' ' && lmao[i] != '/') break; lmao.erase(lmao.end() - 1, lmao.end()); }
        for (int i = 0; i < lmao.length() - 1; ++i) { if (lmao[i] == ' ' && lmao[i + 1] == ' ') { lmao.erase(lmao.begin() + i, lmao.begin() + i + 1); --i;} }
        return lmao;
    }

    static std::string phone(std::string orgdr, std::string num) {
        if (orgdr.find(num) == std::string::npos) return "Error => Not found: " + num;
        else if (orgdr.find(num) != orgdr.rfind(num)) return "Error => Too many people: " + num;
        orgdr = '\n' + orgdr;
        int lB = orgdr.find(num), uB = lB;
        while (orgdr[lB] != '\n') --lB;
        while (orgdr[uB] != '\n') ++uB;
        std::string name, thatLine = removeShit(std::string(orgdr.begin() + lB, orgdr.begin() + uB), name, num);
        return "Phone => " + num + ", Name => " + name + ", Address => " + thatLine;
    }
};