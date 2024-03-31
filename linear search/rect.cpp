#include <iostream>
/*
На клетчатой плоскости закрашено K клеток. 
Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки.
*/
void max_or_min(int x, int& x_max, int& x_min)
{
	x > x_max ? x_max = x : 0;
	x < x_min ? x_min = x : 0;
}

int main()
{
	int x_min = 1'000'000, x_max = 0, y_min = 1'000'000, y_max = 0;

	int num;
	std::cin >> num;

	for (int i = 0; i < num; i ++)
	{
		int x, y;
		std::cin >> x >> y;

		max_or_min(x, x_max, x_min);
		max_or_min(y, y_max, y_min);
	}
	std::cout << x_min << ' ' << y_min << ' ' << x_max << ' ' << y_max;
}