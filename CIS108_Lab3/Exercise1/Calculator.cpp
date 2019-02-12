#include <math.h> 

double num_1 = 0;

double num_2 = 0;

double jump_result = 0;

double rem_key = 0;

int set_dec = 0;

int current_num = 1;

char busy_task = char(0);

int digit;

char char_key;


double doSomething(int pressed_key)

{
	char_key = char(pressed_key);

	switch (char_key)

	{

	case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':

		digit = pressed_key - 48;

		if (set_dec == 0)

		{
			if (current_num == 1)
			{
				num_1 *= 10;

				num_1 += digit;
			}

			if (current_num == 2)

			{
				num_2 *= 10;

				num_2 += digit;
			}

		}

		else

		{
			double decimal = digit / (pow(10, set_dec));

			if (current_num == 1)

				num_1 = num_1 + decimal;

			if (current_num == 2)

				num_2 = num_2 + decimal;

			set_dec += 1;
		}
		break;

	case '.':

		if (set_dec == 0)

			set_dec = 1;

		break;

	case '*': case '+': case '-': case '/': case '^':

		busy_task = char_key;

		current_num = 2;

		num_2 = 0;

		set_dec = 0;

		break;

		case char(13) :

			switch (busy_task)

			{
			case '*':

				jump_result = num_1 * num_2;

				break;

			case '+':

				jump_result = num_1 + num_2;

				break;

			case '-':

				jump_result = num_1 - num_2;

				break;

			case '/':

				jump_result = num_1 / num_2;

				break;

			case '^':

				jump_result = pow(num_1, num_2);

				break;
			}
					  num_1 = jump_result;

					  num_2 = 0;

					  set_dec = 0;

					  busy_task = 0;

					  break;

		case 'c': case 'C':

			jump_result = 0;

			num_1 = jump_result;

			current_num = 1;

			break;

		case 's': case 'S':

			rem_key = jump_result;

			break;

		case 'r': case 'R':

			jump_result = rem_key;

			num_1 = jump_result;

			current_num = 1;

			break;

		case 'm': case 'M':

			rem_key = 0;

			break;

		case 'i': case 'I':

			num_1 = 0 - jump_result;

			current_num = 1;

			break;

		default:

			jump_result = jump_result;

			break;
	}

	if (pressed_key != char(13))

	{
		if (current_num == 1)

			jump_result = num_1;

		else

			jump_result = num_2;
	}

	return jump_result;
}