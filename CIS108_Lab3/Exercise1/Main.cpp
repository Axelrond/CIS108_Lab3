#include <iostream>
#include <iomanip>
#include "conio.h"
#include "Calculator.h"
#include <string>

using namespace std;

string jump_layer(double int_or_double_number)

{
	string go_back;

	if (int_or_double_number == 0)

		go_back = "";

	else
	{
		if (int_or_double_number == static_cast<int>(int_or_double_number))

			go_back = to_string(static_cast<int>(int_or_double_number));
		else

		{
			go_back = to_string(int_or_double_number);

			int i = go_back.length();

			while (go_back[i - 1] == '0')

			{
				go_back.erase(i - 1, 1);

				i = go_back.length();

			}
		}
	}

	return go_back;
}

int main()

{
	int find_key;

	string key_cycle;

	double calc_react = 0;

	bool task_cycle = false;

	string last_cycle = "";

	string print_cycle = "";

	char sprite;

	cout << "\rHi, I'm a calculator! Enter some numbers! \n";

	do {

		find_key = _getch();

		sprite = char(find_key);

		if (sprite != 'i' && sprite != 'I' && sprite != 'c' && sprite != 'C' && sprite != 'r' && sprite != 'R' && sprite != 's' && sprite != 'S')

			key_cycle += sprite;

		if (sprite == '+' || sprite == '-' || sprite == '*' || sprite == '/' || sprite == '^')

		{
			last_cycle = key_cycle;

			task_cycle = true;
		}

		calc_react = doSomething(find_key);

		if (find_key == 13 || sprite == 'c' || sprite == 'C' || sprite == 'r' || sprite == 'R')

		{
			task_cycle = false;

			key_cycle = jump_layer(calc_react);

			cout << "\r                              ";

			cout << "\r  " << print_cycle << "\n" << key_cycle << "\n";

			last_cycle = "";

			key_cycle = "";
		}
		if (calc_react != 0 && task_cycle)

			print_cycle = last_cycle + jump_layer(calc_react);
		else
			print_cycle = key_cycle;
		cout << "\r " << print_cycle;
	} while (sprite != 'x' && sprite != 'x');

	return 0;
}
