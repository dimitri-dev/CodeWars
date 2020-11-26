#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

const std::string thousands[] = { "", "M", "MM", "MMM" };
const std::string hundreds[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
const std::string tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
const std::string units[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

int solution(std::string number)
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
				if (number[i - 1] == 'X'){
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

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	cout << solution("MIX") << endl;
	cout << solution("MCMLIV") << endl;
}