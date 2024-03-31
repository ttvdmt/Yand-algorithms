#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
/*
Из шахматной доски по границам клеток выпилили связную (не распадающуюся на части) фигуру без дыр.

Требуется определить ее периметр.
*/
inline size_t key(int i,int j) {return (size_t) i << 32 | (unsigned int) j;}

int main()
{
	int num;
	std::cin >> num;

	std::unordered_map<size_t, std::pair<int, int>> cubes{};

	int x, y;
	for (int i = 0; i < num; i++)
	{
		std::cin >> x >> y;

		cubes[key(x, y)] = {x, y};
	}

	int per = 0;
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, 1, 0 , -1};

	for (const auto& [keys, coords] : cubes)
	{
		for (int i = 0; i < 4; i++)
		{
			if (cubes.find(key(coords.first + dx[i], coords.second + dy[i])) == cubes.end())
				per++;
		}
	}
	std::cout << cubes.size() << std::endl;
	std::cout << per << '\n';
}