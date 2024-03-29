#include <iostream>
/*
Миша сидел на занятиях математики в Высшей школе экономики и решал следующую задачу:
дано n целых чисел и нужно расставить между ними знаки + и × так, 
чтобы результат полученного арифметического выражения был нечётным (например, между числами 5, 7, 2, 
можно расставить арифметические знаки следующим образом: 5×7+2=37).
 
Так как примеры становились все больше и больше, а Миша срочно убегает в гости,
 от вас требуется написать программу решающую данную задачу.
*/
void sum_or_multi_even(int& sum, int num, std::string& str)
{
	if (abs(num) % 2 == 0) {
		sum += num;
		str += '+';
	}
	else {
		sum += num;
		str += '+';
	}
}

void sum_or_multi_uneven(int& sum, int num, std::string& str)
{
	if (abs(num) % 2 == 0) {
		sum += num;
		str += '+';
	}
	else {
		sum *= num;
		str += 'x';
	}
}

int main()
{
	int n;
	std::cin >> n;

	std::string result;

	int sum;
	std::cin >> sum;

	for (int i = 1; i < n; i++)
	{
		int num;
		std::cin >> num;

		if (abs(sum) % 2 == 0)
			sum_or_multi_even(sum, num, result);

		else 
			sum_or_multi_uneven(sum, num, result);
	}
	std::cout << result;
}