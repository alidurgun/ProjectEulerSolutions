#include <iostream>
#include <future>
#include <thread>
#define MAX_NUMBER 999
#define MIN_NUMBER 0

int calculateSum(int maxNumber, int minNumber, int divider);
void calculateSumProm(int maxNumber, int minNumber, int divider, std::promise<int> prom);

using namespace std;

int main()
{
	int result, resultThree, resultFive;
	std::promise<int> prms;
	std::future<int> ftr3 = prms.get_future();

	std::thread t1(calculateSumProm, MAX_NUMBER, MIN_NUMBER, 3, std::move(prms));
	std::future<int> ftr5 = std::async(&calculateSum, MAX_NUMBER, MIN_NUMBER, 5);
	resultFive = ftr5.get();

	ftr5 = std::async(&calculateSum, MAX_NUMBER, MIN_NUMBER, 15);
	result = ftr5.get();

	t1.detach();
	resultThree = ftr3.get();


	result = resultThree + resultFive - result;
	std::cout << "Result is : " << result << std::endl;
}

int calculateSum(int maxNumber, int minNumber, int divider)
{
	int dividerCount;

	dividerCount = (maxNumber - minNumber) / divider;

	return (divider * dividerCount * (dividerCount + 1)) / (2 + (dividerCount * minNumber));
}

void calculateSumProm(int maxNumber, int minNumber, int divider, std::promise<int> prom)
{
	int dividerCount, result;

	dividerCount = (maxNumber - minNumber) / divider;

	result = (divider * dividerCount * (dividerCount + 1)) / (2 + (dividerCount * minNumber));

	prom.set_value(result);
}


// deneme automatically pull