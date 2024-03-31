#include <iostream>
/*
На столе лежали две одинаковые верёвочки целой положительной длины.
Петя разрезал одну из верёвочек на N частей, каждая из которых имеет целую положительную длину, так что на столе стало N+1 верёвочек. 
Затем в комнату зашла Маша и взяла одну из лежащих на столе верёвочек. 

По длинам оставшихся на столе N верёвочек определите, какую наименьшую длину может иметь верёвочка, взятая Машей.
*/
int main()
{
	int num;
	std::cin >> num;

	int max = 0, sum = 0;

	int elem;
	for (int i = 0; i < num; i++)
	{
		std::cin >> elem;

		if (elem > max)
			max = elem;

		sum += elem;
	}
	std::cout << (2 * max > sum ? 2 * max - sum : sum);
}