#include <iostream>
#include <fstream>
#include <string>

bool exists(std::string const& rstr, char ch)
{
	bool result(false);
	for (size_t i = 0; i < rstr.size(); i++)
	{
		if (rstr.at(i) == ch)
		{
			result = true;
		}
	}
	return result;
}

std::string intHexStr(int var)
{
	std::string str;

	int arr[20];

	int i = 0;
	while (var >= 16)
	{
		arr[i] = var % 16;
		var = var / 16;
		++i;
	}
	arr[i] = var;
	for (int j = i; j >= 0; --j)
	{
		switch (arr[j])
		{
		case 0: str.push_back('0'); break;
		case 1: str.push_back('1'); break;
		case 2: str.push_back('2'); break;
		case 3: str.push_back('3'); break;
		case 4: str.push_back('4'); break;
		case 5: str.push_back('5'); break;
		case 6: str.push_back('6'); break;
		case 7: str.push_back('7'); break;
		case 8: str.push_back('8'); break;
		case 9: str.push_back('9'); break;
		case 10: str.push_back('A'); break;
		case 11: str.push_back('B'); break;
		case 12: str.push_back('C'); break;
		case 13: str.push_back('D'); break;
		case 14: str.push_back('E'); break;
		case 15: str.push_back('F'); break;
		default: break;
		}
	}

	return str;
}

void f(void)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	std::string str;

	getline(in, str);
	int lines = std::stoi(str);
	//std::cout << lines << "\n";

	for (int line = 0; line != lines; ++line)
	{
		int cipher = 0;

		// get the line
		getline(in, str);
		//std::cout << str << "\n";

		// go on the line
		std::string unique;
		int i = 0;
		// check a symbol until 1st comma
		// check the uniqueness 
		while (str.at(i) != ',')
		{
			if (!exists(unique, str.at(i)))
			{
				unique.push_back(str.at(i));
			}
			++i;
		}
		++i;
		// check a symbol until 2st comma
		// check the uniqueness 
		while (str.at(i) != ',')
		{
			if (!exists(unique, str.at(i)))
			{
				unique.push_back(str.at(i));
			}
			++i;
		}
		++i;
		// check symbol until 3st comma
		// check the uniqueness 
		while (str.at(i) != ',')
		{
			if (!exists(unique, str.at(i)))
			{
				unique.push_back(str.at(i));
			}
			++i;
		}
		++i;
		// the set of unique symbols has been done
		// get the int number of unique symbols
		int unique_symbols = unique.size();
		unique.clear();

		// create the sum of digits of a day and mounth
		int sum_digits_d_m = 0;

		// get a digits before 4st comma
		while (str.at(i) != ',')
		{
			int var = str.at(i);
			var -= 48;
			sum_digits_d_m += var;
			++i;
		}
		++i;

		// get a string number before 5st comma
		while (str.at(i) != ',')
		{
			int var = str.at(i);
			var -= 48;
			sum_digits_d_m += var;
			++i;
		}
		++i;

		// get the 1st symbol code
		// 1st indexing = code - ascii code A + 1
		// ascii A 65
		int first_symbol = static_cast<int>(str.at(0)) - 65 + 1;

		//std::cout << unique_symbols << std::endl;
		//std::cout << sum_digits_d_m << std::endl;
		//std::cout << first_symbol << std::endl;

		cipher = unique_symbols + sum_digits_d_m * 64 + first_symbol * 256;
		//std::cout << cipher << std::endl;

		str = intHexStr(cipher);
		//std::cout << str << std::endl;

		for (int i = str.size() - 3; i != str.size(); ++i)
		{
			std::cout << str.at(i);
			out << str.at(i);
		}
		//std::cout << '\n';
		std::cout << ' ';
		out << ' ';
	}
}
int main(void)
{
	f();

	return 0;
}
