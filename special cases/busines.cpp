#include <iostream>
#include <string>
/*
k друзей организовали стартап по производству укулеле для кошек.
На сегодняшний день прибыль составила n рублей.
Вы, как главный бухгалтер компании, хотите в каждый из ближайших d дней приписывать по одной цифре в конец числа, выражающего прибыль.
При этом в каждый из дней прибыль должна делиться на k.
*/
void money(int n, int k, int d)
{
	long long int x = n;
	std::string str = std::to_string(x);
	bool zero_flag = false;

	for (int i = 0; i < d; i++)
	{
		x = x * 10;

		if (x % k == 0 || zero_flag) {
			str += '0';
			zero_flag = true;
		}

		else if (k - (x % k) < 10) {
			str += std::to_string(k - (x % k));
			x += (k - (x % k));
		}

		else {
			str = std::to_string(-1);
			break;
		}
	}
	std::cout << str << std::endl;
}

int main()
{
	int n, k, d;
	std::cin >> n >> k >> d;

	money(n, k, d);
}