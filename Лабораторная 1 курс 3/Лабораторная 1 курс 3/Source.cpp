#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool IsPolindriom_A(string str)
{
	for (int x = 0; x < str.length() / 2; x++)
	{
		if (str[x] != str[str.length() - 1 - x])
		{
			return(0);
		}
	}
	return(1);
}

bool IsPolindriom_B(string str)
{
	string new_str = str;
	reverse(str.begin(), str.end());
	if (str == new_str)
	{
		return(1);
	}
	return(0);
}

const int MAX_LENGHT = 100;
const int MAX_V_SIZE = 100;

vector<string> PalindromFilter(const vector<string>& words, int minLenght)
{
	vector<string>filtered;
	int already_filtered = 0;
	for (const string& word : words)
	{
		if (word.length() >= minLenght && word.length() <= MAX_LENGHT && IsPolindriom_A(word))
		{
			if (already_filtered == MAX_V_SIZE)
			{
				return (filtered);
			}
			already_filtered++;

			filtered.push_back(word);
		}
	}
	return (filtered);
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << IsPolindriom_A("0120");
	cout << endl << IsPolindriom_B("333");

	vector<string>input{ "123","321","111","11","","1","3333","f,f","adda","abrba" };
	input.push_back("Ù‚Ù‚");
	
	vector<string>result = PalindromFilter(input, 2);
	cout << endl << "–ÂÁÛÎ¸Ú‡Ú:";
	for (string word : result)
	{
		cout << endl << "[" << word << "]";
	}

	system("pause");
}