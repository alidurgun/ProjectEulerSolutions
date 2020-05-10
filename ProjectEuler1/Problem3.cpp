#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char **argv)
{
	long long number = 600851475143;
	const int offset = 2;
	int finalValue = 1, currentValue = 2, maxValue;

	while ((number % 2) == 0)
	{
		finalValue = 2;
		number /= currentValue;
	}
	currentValue = 3;
	maxValue = sqrt(number);

	while (number > 1 && currentValue <= maxValue)
	{
		if ((number % currentValue) == 0)
		{
			number /= currentValue;
			finalValue = currentValue;
			while ((number % currentValue) == 0)
			{
				number /= currentValue;
			}
			maxValue = sqrt(number);
		}
		currentValue += offset;
	}

	if (number == 1)
		cout << "largest prime is : " << finalValue << endl;
	else
		cout << "largest prime is : " << number << endl;

	getchar();
	return 0;
}