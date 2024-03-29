#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
/*
Как же Илье надоело учиться! Сначала школа, потом университет... 
Вот, наконец, наступил тот долгожданный день, когда Илье утром не надо ехать на учебу. 
Но, к несчастью для Ильи, оказалось, что после окончания университета начинается самое трудное — надо устраиваться на работу.

Во всемирно известной фирме «Goondex», в которую устроился Илья, принято очень много работать,
в частности, для сотрудников установлена шестидневная рабочая неделя. 
Но, в качестве бонуса, «Goondex» каждый год предлагает своим сотрудникам выбрать любой день недели в качестве выходного. 
В свою очередь, оставшиеся шесть дней недели будут рабочими.

Илья сообразил, что с учётом государственных праздников (которые всегда являются выходными) 
с помощью правильного выбора выходного дня недели можно варьировать количество рабочих дней в году. 
Теперь он хочет знать, какой день недели ему следует выбрать в качестве выходного, 
чтобы отдыхать как можно больше дней в году, или, наоборот, демонстрировать чудеса трудолюбия, работая по максимуму.
*/
void first_day_checker(std::string& day, std::vector<int>& days, bool year4)
{
	if (day == "Monday") {
		days[2]++;
		if (year4)
			days[3]++;
	}

	else if (day == "Tuesday") {
		days[3]++;
		if (year4)
			days[4]++;
	}

	else if (day == "Wednesday") {
		days[4]++;
		if (year4)
			days[5]++;
	}

	else if (day == "Thursday") {
		days[5]++;
		if (year4)
			days[6]++;
	}

	else if (day == "Friday") {
		days[6]++;
		if (year4)
			days[0]++;
	}

	else if (day == "Saturday") {
		days[0]++;
		if (year4)
			days[1]++;
	}

	else if (day == "Sunday") {
		days[1]++;
		if (year4)
			days[2]++;
	}
}

int code_month(std::string& month)
{
	if (month == "January" || month == "October")
		return 1;

	else if (month == "May")
		return 2;

	else if (month == "August")
		return 3;

	else if (month == "February" || month == "March" || month == "November")
		return 4;

	else if (month == "June")
		return 5;

	else if (month == "December" || month == "September")
		return 6;

	else
		return 0;
}

std::string to_day(std::vector<int>::iterator it, std::vector<int>::iterator begin)
{
	int dday = 0;
	while (it != begin)
	{
		it--;
		dday++;
	}

	if (dday == 2)
		return "Monday";

	else if (dday == 3)
		return "Tuesday";

	else if (dday == 4)
		return "Wednesday";

	else if (dday == 5)
		return "Thursday";

	else if (dday == 6)
		return "Friday";

	else if (dday == 0)
		return "Saturday";

	else
		return "Sunday";
}

int main()
{
	std::vector<int> days = {52, 52, 52, 52, 52, 52, 52};
	bool year4 = false;

	int num;
	std::cin >> num;

	int year;
	std::cin >> year;

	int code_vek = 6 - 2 * ((year / 100) % 4);
	int code_year = (code_vek + (year % 100) + (year % 100) / 4) % 7;

	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
		year4 = true;

	for (int i = 0; i < num; i++)
	{
		int date;
		std::string month;

		std::cin >> date >> month;
		
		int dx = 0;
		if (year4 && (month == "January" || month == "February"))
			dx--;

		int day = (date + dx + code_month(month) + code_year) % 7;

		days[day] -= 1;
	}

	std::string firstday;
	std::cin >> firstday;

	first_day_checker(firstday, days, year4);
	std::cout << to_day(std::max_element(days.begin(), days.end()), days.begin()) << ' ' << to_day(std::min_element(days.begin(), days.end()), days.begin()) << std::endl;
}