#include <iostream>
#include <vector>
#include <cmath>

#include <numeric>
#include <algorithm>
#include <string>

using std::cin;
using std::cout;
using std::endl;

class RomanNumerals
{
public:
    std::string to_roman(int number)
    {
        std::string thousands[] = { "", "M", "MM", "MMM" };
        std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        std::string units[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

        std::string sol = "";
        std::vector<int> intVector;

        for (const auto digit : std::to_string(number))
            intVector.push_back(digit - '0');

        if (intVector.size() == 4)
        {
            sol += thousands[(int)intVector[0]];

            intVector.erase(intVector.begin());
            number = 0;
            for (auto d : intVector)
                number = number * 10 + d;
        }
        if (intVector.size() == 3)
        {
            sol += hundreds[(int)intVector[0]];

            intVector.erase(intVector.begin());
            number = 0;
            for (auto d : intVector)
                number = number * 10 + d;
        }
        if (intVector.size() == 2)
        {
            sol += tens[(int)intVector[0]];

            intVector.erase(intVector.begin());
            number = 0;
            for (auto d : intVector)
                number = number * 10 + d;
        }

        sol += units[(int)intVector[0]];

        return sol;
    }

	int from_roman(std::string number)
	{
		int thousandNum = 0, hundredNum = 0, tenNum = 0, unitNum = 0;

		std::string ss = " ";
		ss += number;
		number = ss;

		for (int i = 1; i < number.length(); ++i)
		{
			switch (number[i]) {
				// THOUSANDS
			case 'M':
				++thousandNum;
				if (number[i - 1] == 'C') {
					--thousandNum;
					hundredNum += 8;
				}
				break;

				// HUNDREDS
			case 'C':
				++hundredNum;
				if (number[i - 1] == 'X') {
					--hundredNum;
					tenNum += 8;
				}
				break;
			case 'D':
				hundredNum += 5;
				if (number[i - 1] == 'C')
					hundredNum -= 2;
				break;

				// TENS
			case 'X':
				++tenNum;
				if (number[i - 1] == 'I') {
					--tenNum;
					unitNum += 8;
				}
				break;
			case 'L':
				tenNum += 5;
				if (number[i - 1] == 'X')
					tenNum -= 2;
				break;

				// UNITS
			case 'I':
				++unitNum;
				break;
			case 'V':
				unitNum += 5;
				if (number[i - 1] == 'I')
					unitNum -= 2;
				break;
			default:
				break;
			}
		}

		return (thousandNum * 1000 + hundredNum * 100 + tenNum * 10 + unitNum);
	}
} RomanNumerals;

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cout << RomanNumerals.to_roman(1000) << endl;
    cout << RomanNumerals.from_roman("M") << endl;
}