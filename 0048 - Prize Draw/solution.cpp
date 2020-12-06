class Rank {
public:
    static std::string nthRank(std::string st, std::vector<int> &we, int n)
    {
        if (st == "")
          return "No participants";
      
        if (n > std::count(st.begin(), st.end(), ',') + 1)
          return "Not enough participants";
      
        std::vector<std::pair<std::string, long>> results;
        st += ',';
        
        int lastI = 0;
        for (int i = 0; i < st.length(); ++i){
          if (st[i] == ','){
            std::string name = st.substr(lastI, i - lastI);
            std::string name_cpy = name;
            lastI = i + 1;
            
            std::transform(name.begin(), name.end(), name.begin(), ::toupper);
            
            int sum = name.length();
            for (auto x : name)
              sum += (x - 'A' + 1);
            
            sum *= we[results.size()];
            
            results.push_back(make_pair(name_cpy, sum));
          }
        }
      
        std::sort(results.begin(), results.end(), [](auto&& a, auto&& b) { return (a.second == b.second) ? a.first < b.first : a.second > b.second; });
      
        for (auto x : results)
          std::cout << "x: " << x.first << " a:" << x.second << std::endl;
      
        return results[n - 1].first;
    }
};