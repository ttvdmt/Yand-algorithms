#include <iostream>
#include <vector>
#include <algorithm>
/*
Вася решил заняться торговлей рыбой. С помощью методов машинного обучения он предсказал цены на рыбу на N дней вперёд. 
Он решил, что в один день он купит рыбу, а в один из следующих дней — продаст 
(то есть совершит или ровно одну покупку и продажу или вообще не совершит покупок и продаж, если это не принесёт ему прибыли). 
К сожалению, рыба — товар скоропортящийся и разница между номером дня продажи и номером дня покупки не должна превышать K.

Определите, какую максимальную прибыль получит Вася.
*/
void max_search(int num, int pos, int k, std::pair<int, int>& max1, std::pair<int, int>& max2)
{
	if (max2.second < pos - k) {
		max2 = {0, pos}; 
	}
	if (max1.second < pos - k) {
		max1 = max2;
		max2 = {0, pos}; 
	}

	if (num > max2.first) {
		if (num > max1.first) {
			max2 = max1;
			max1 = {num, pos};
		}
		else
			max2 = {num, pos};
	}
}

int max_search(int it1, std::vector<int>& nums)
{
	int max = 0;

	for (int i = it1; i < nums.size(); i++)
	{
		if (nums[i] > max)
			max = nums[i];
	}
	return max;
}

int main()
{
	int n, k;
	std::cin >> n >> k;

	std::pair<int, int> max1 = {0, 0};
	std::pair<int, int> max2 = {0, 0};

	std::vector<int> nums;
	int result = 0;

	for (int i = 0; i < n + k; i++)
	{
		if (i < n) {
			int elem;
			std::cin >> elem;
			nums.push_back(elem);

			max_search(elem, i, k, max1, max2);
			if (i >= k) {
				//std::cout << nums[i - k] << std::endl;
				if (max1.first - nums[i - k] > result)
					result = max1.first - nums[i - k];
			}
		}
		else {
			int max = max_search(i - k, nums);
			if (max - nums[i - k] > result)
				result = max - nums[i - k];
		}
	}
	std::cout << result << std::endl;
}