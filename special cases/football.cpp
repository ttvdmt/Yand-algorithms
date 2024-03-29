#include <iostream>
#include <vector>
/*
Раунд плей-офф между двумя командами состоит из двух матчей.
Каждая команда проводит по одному матчу «дома» и «в гостях».
Выигрывает команда, забившая большее число мячей.
Если же число забитых мячей совпадает, выигрывает команда, забившая больше мячей «в гостях».
Если и это число мячей совпадает, матч переходит в дополнительный тайм или серию пенальти.
Вам дан счёт первого матча, а также счёт текущей игры (которая ещё не завершилась).

Помогите комментатору сообщить, сколько голов необходимо забить первой команде, чтобы победить, не переводя игру в дополнительное время.
*/
int main()
{
	std::vector<int> team1;
	std::vector<int> team2;

	for (int i = 0; i < 2; i++)
	{
		int goals1, goals2;
		scanf("%d:%d", &goals1, &goals2);

		team1.push_back(goals1);
		team2.push_back(goals2);
	}
	int home;
	std::cin >> home;

	if (home == 1) {
		int score1 = team1[0] * 100 + team1[1] * 101;
		int score2 = team2[0] * 101 + team2[1] * 100;

		std::cout << ((score2 - score1 + 101) / 101 > 0 ? (score2 - score1 + 101) / 101 : 0);
	}
	else {
		int score1 = team1[0] * 101 + team1[1] * 100;
		int score2 = team2[0] * 100 + team2[1] * 101;

		std::cout << ((score2 - score1 + 100) / 100 > 0 ? (score2 - score1 + 100) / 100 : 0);
	}
}