#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>
/*
Домашний питомец мальчика Васи — улитка Петя. Петя обитает на бесконечном в обе стороны вертикальном столбе, 
который для удобства можно представить как числовую прямую. Изначально Петя находится в точке 0.
Вася кормит Петю ягодами. У него есть n ягод, каждая в единственном экземпляре. 
Вася знает, что если утром он даст Пете ягоду с номером i, то поев и набравшись сил, 
за остаток дня Петя поднимется на ai единиц вверх по столбу, но при этом за ночь, потяжелев, съедет на bi единиц вниз. 
Параметры различных ягод могут совпадать.
Пете стало интересно, а как оно там, наверху, и Вася взялся ему в этом помочь. 
Ближайшие n дней он будет кормить Петю ягодами из своего запаса таким образом,
 чтобы максимальная высота, на которой побывал Петя за эти n дней была максимальной.
 К сожалению, Вася не умеет программировать, поэтому он попросил вас о помощи. 

Найдите, максимальную высоту, на которой Петя сможет побывать за эти n дней и в каком порядке Вася должен давать Пете ягоды,
 чтобы Петя смог её достичь!
*/
bool comp(const std::pair<uint64_t, std::pair<uint64_t, uint64_t>>& a, const std::pair<uint64_t, std::pair<uint64_t, uint64_t>>& b)
{
	if (a.second.second > b.second.second)
		return true;
	else
		return false;
}

int main()
{
	std::vector<uint64_t> steps;
	std::vector<uint64_t> neutral_steps;
	std::vector<uint64_t> minuses_steps;
	std::vector<uint64_t> max;

	uint64_t n;
	std::cin >> n;

	std::pair<uint64_t, std::pair<uint64_t, uint64_t>> worst_plus = {0, {0, 0}};
	std::pair<uint64_t, std::pair<uint64_t, uint64_t>> best_neutral = {0, {0, 0}};
	std::pair<uint64_t, std::pair<uint64_t, uint64_t>> best_minus = {0, {0, 0}};

	uint64_t result = 0;
	for (uint64_t i = 0; i < n; i++)
	{
		uint64_t a, b;
		std::cin >> a >> b;

		if (a == b) {
			if (best_neutral.second.first < a && best_neutral.first != 0) {
				neutral_steps.push_back(best_neutral.first);
				best_neutral = {i + 1, {a, b}};
			}
			else if (best_neutral.first == 0)
				best_neutral = {i + 1, {a, b}};
			else 
				neutral_steps.push_back(i + 1);
		}
		else if (a > b) {
			max.push_back(a);
			if (comp({i + 1, {a, b}}, worst_plus) && worst_plus.first != 0) {
				result += (worst_plus.second.first - worst_plus.second.second);
				steps.push_back(worst_plus.first);
				worst_plus = {i + 1, {a, b}};
			}
			else if (worst_plus.first == 0)
				worst_plus = {i + 1, {a, b}};
			else {
				result += (a - b);
				steps.push_back(i + 1);
			}
		}	
		else {
			if (best_minus.second.first < a && best_minus.first != 0) {
				minuses_steps.push_back(best_minus.first);
				best_minus = {i + 1, {a, b}};
			}
			else if (best_minus.first == 0)
				best_minus = {i + 1, {a, b}};
			else 
				minuses_steps.push_back(i + 1);
		}
	}
	std::vector<uint64_t> maxes;
	maxes.push_back(result);
	maxes.push_back(result + worst_plus.second.first);
	steps.push_back(worst_plus.first);
	maxes.push_back(result + worst_plus.second.first - worst_plus.second.second + best_neutral.second.first);
	maxes.push_back(result + worst_plus.second.first - worst_plus.second.second + best_minus.second.first);

	std::cout << *std::max_element(maxes.begin(), maxes.end()) << std::endl;

	if (worst_plus.first != 0) {
		for (auto elem : steps)
		std::cout << elem << ' ';
	}

	if (best_neutral.first != 0) {
		std::cout << best_neutral.first << ' ';
		for (auto elem : neutral_steps)
		std::cout << elem << ' ';
	}

	if (best_minus.first != 0) {
		std::cout << best_minus.first << ' ';
		for (auto elem : minuses_steps)
		std::cout << elem << ' ';
	}
}