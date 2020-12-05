static long findMissing(std::vector<long> list){ 
    // Look at the difference between the upper end (last two) and lower end (first two)
    long upperDiff = std::abs(list[list.size() - 2] - list.back());
    long lowerDiff = std::abs(list[0] - list[1]);
  
    // Finds corner case
    if (upperDiff != lowerDiff){
        if (upperDiff == 2 * lowerDiff)
          return (list.back() < 0) ? list.back() + lowerDiff : list.back() - lowerDiff;
        else
          return list[0] + upperDiff;
    }
  
    auto a = list.begin() + 1;
  
    // If not corner case - iterate through the array and find missing element
    // i.e. where the difference between two doesn't match the difference calculated above
    while (true){
      if (std::abs(*(a + 1) - *a) != lowerDiff)
        return (*(a + 1) < *a) ? *a - lowerDiff : *a + lowerDiff;
      ++a;
    }
}