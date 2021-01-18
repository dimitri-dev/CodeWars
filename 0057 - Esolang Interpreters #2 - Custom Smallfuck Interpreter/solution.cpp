std::string interpreter(std::string code, std::string tape) {
    int32_t placement = 0, codeCounter = 0;
    std::vector<int> openBrackets, closedBrackets;

    for (; codeCounter < code.length(); ++codeCounter) {
      if (code[codeCounter] == '[') openBrackets.push_back(codeCounter);
      else if (code[codeCounter] == ']') closedBrackets.push_back(codeCounter);
    }
    codeCounter = 0;

    while (codeCounter < code.length()) {
        switch (code[codeCounter]){
            case '*':
                (tape[placement] == '0') ? tape[placement] = '1' : tape[placement] = '0';
                break;
            case '>':
                ++placement;
                break;
            case '<':
                --placement;
                break;
            case '[':
                if (tape[placement] == '0')
                    for (int _ = 0; _ < openBrackets.size(); ++_)
                        if (std::find(openBrackets.begin(), openBrackets.end(), codeCounter) != openBrackets.end())
                            codeCounter = closedBrackets[closedBrackets.size() - 1 - std::distance(openBrackets.begin(), std::find(openBrackets.begin(), openBrackets.end(), codeCounter))];
                break;
            case ']':
                if (tape[placement] == '1')
                    for (int _ = 0; _ < closedBrackets.size(); ++_)
                        if (std::find(closedBrackets.begin(), closedBrackets.end(), codeCounter) != closedBrackets.end())
                            codeCounter = openBrackets[openBrackets.size() - 1 - std::distance(closedBrackets.begin(), std::find(closedBrackets.begin(), closedBrackets.end(), codeCounter))];
                break;
        }

        if (placement >= tape.length()) return tape;
        ++codeCounter;
    }

    return tape;
}