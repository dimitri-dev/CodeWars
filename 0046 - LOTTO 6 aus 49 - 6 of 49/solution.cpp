std::vector<int> numberGenerator(){
    std::vector<int> nums(7, 0);
  
    // #definitelyRNG
    nums[0] = rand()%8 + 1;
    nums[1] = rand()%8 + 8;
    nums[2] = rand()%8 + 16;
    nums[3] = rand()%8 + 24;
    nums[4] = rand()%8 + 32;
    nums[5] = rand()%10 + 40;
  
    nums[6] = rand()%10;
  
    return nums;
}

int checkForWinningCategory(std::vector<int> checkCombination, std::vector<int> winningCombination){ 
    int match = 0; bool superzahl = false;
  
    for (int i = 0; i < winningCombination.size() - 1; ++i)
      if(std::find(checkCombination.begin(), checkCombination.end(), winningCombination[i]) != checkCombination.end())
        ++match;
  
    if (winningCombination.back() == checkCombination.back()) superzahl = true;
    
    std::cout << match << " " << superzahl << std::endl;
  
    if (!superzahl && match < 3)
      return -1;
    
    if (match == 2) return 9;
    else if (match == 3) return (superzahl) ? 7 : 8;
    else if (match == 4) return (superzahl) ? 5 : 6;
    else if (match == 5) return (superzahl) ? 3 : 4;
    else if (match == 6) return (superzahl) ? 1 : 2;
    else return -1;
}