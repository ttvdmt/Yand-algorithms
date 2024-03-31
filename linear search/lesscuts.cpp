#include <iostream>
#include <vector>
#include <algorithm>
/*
Дан массив целых положительных чисел a длины n. Разбейте его на минимально возможное количество отрезков,
 чтобы каждое число было не меньше длины отрезка которому оно принадлежит. Длиной отрезка считается количество чисел в нем.

Разбиение массива на отрезки считается корректным, если каждый элемент принадлежит ровно одному отрезку.
*/
int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		int m;
		std::cin >> m;

		std::vector<int> nums;
		std::vector<int> cuts;
		int cut = 0;

		for (int j = 0; j < m; j++)
		{
			int elem;
			std::cin >> elem;
			nums.push_back(elem);
		}
		std::sort(nums.begin(), nums.end(), [](auto a, auto b){return a > b;});
		int k = 0;
		int cur_cut = nums[k];
		int size = 1;
		while (k < m)
		{
			if (nums[k] < cur_cut) {
				cuts.push_back(size);
				cur_cut = nums[k];
				size = 1;
			}
			else
				size++;
			k++;
		}
		std::cout << cuts.size() << std::endl;
		for (int l = cuts.size() - 1; l != 0; l--)
			std::cout << cuts[l] << ' ';
		std::cout << std::endl;
	}
}