#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
/*
Константин и Михаил играют в настольную игру «Ярость Эльфов». В игре есть n рас и m классов персонажей. 
Каждый персонаж характеризуется своими расой и классом. 
Для каждой расы и каждого класса существует ровно один персонаж такой расы и такого класса. 
Сила персонажа i-й расы и j-го класса равна ai j, и обоим игрокам это прекрасно известно.

Сейчас Константин будет выбирать себе персонажа. 
Перед этим Михаил может запретить одну расу и один класс, чтобы Константин не мог выбирать персонажей, 
у которых такая раса или такой класс. 
Конечно же, Михаил старается, чтобы Константину достался как можно более слабый персонаж, 
а Константин, напротив, выбирает персонажа посильнее. 

Какие расу и класс следует запретить Михаилу?
*/
std::pair<int, std::pair<int, int>> search_x(const std::vector<std::pair<int, std::pair<int, int>>>& elems)
{
	int x = elems[0].second.first;
	int y = 0;
	int max = 0;

	int i = 0;
	while (elems[i].second.first == x)
		i++;

	y = elems[i].second.second;
	while (elems[i].second.first == x || elems[i].second.second == y)
		i++;

	max = elems[i].first;
	return {max, {x, y}};
}

std::pair<int, std::pair<int, int>> search_y(const std::vector<std::pair<int, std::pair<int, int>>>& elems)
{
	int y = elems[0].second.second;
	int x = 0;
	int max = 0;;

	int i = 0;
	while (elems[i].second.second == y)
		i++;

	x = elems[i].second.first;
	while (elems[i].second.first == x || elems[i].second.second == y)
		i++;

	max = elems[i].first;
	return {max, {x, y}};
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::pair<int, std::pair<int, int>>> elems;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int elem;
			std::cin >> elem;

			elems.push_back({elem, {j, i}});
		}
	}

	std::sort(elems.begin(), elems.end(), [](auto a, auto b){return a.first > b.first;});

	int bc = 0, br = 0;
	auto res1 = search_x(elems);
	auto res2 = search_y(elems);

	if (res1.first > res2.first)
	{
		bc = res2.second.first;
		br = res2.second.second;
	}
	else
	{
		bc = res1.second.first;
		br = res1.second.second;
	}

	std::cout << br + 1 << ' ' << bc + 1 << std::endl;
}