#include <iostream>
#define MAX_NUMBER 4000000

using namespace std;

void calculateSumOfFib(int, int, long *);

int main(int argc, char **argv)
{
	int firstFibonacci = 1, secondFibonacci = 1;
	long *result = new long(0);
	calculateSumOfFib(firstFibonacci, secondFibonacci, result);
	cout << "result is : " << *result;
}

void calculateSumOfFib(int firstFibonacci, int secondFibonacci, long *result)
{
	if (MAX_NUMBER < secondFibonacci)
	{
		return;
	}
	if (secondFibonacci % 2 == 0)
	{
		*result += secondFibonacci;
	}
	calculateSumOfFib(secondFibonacci, firstFibonacci + secondFibonacci, result);
}