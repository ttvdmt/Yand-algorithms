#include <iostream>
#include <vector>
#include <algorithm>
/*
Стадион представляет собой окружность длиной L метров, на которой отмечена точка старта. 
По стадиону бегают Кирилл и Антон. 
У каждого мальчика есть своя точка старта (она представляет собой расстояние в метрах от старта, отсчитанное по часовой стрелке)
и своя скорость в метрах в секунду
(положительная скорость означает, что мальчик бежит по часовой стрелке, отрицательная — что бежит против часовой, а нулевая — что он стоит на месте).

Вам нужно сказать, через какое минимальное время мальчики окажутся на одинаковом расстоянии от точки старта.
Обратите внимание, что в этот момент они могли находиться в разных точках. 
Расстоянием от точки A до точки B называется минимальное из расстояний,
которое нужно пробежать из точки A по или против часовой стрелки, чтобы оказаться в B.
*/
double more_zero(double a, double b)
{
    return a > 0 ? a : b;
}

int main() 
{
    double L, x1, v1, x2, v2;
    std::cin >> L >> x1 >> v1 >> x2 >> v2;

    std::cout << std::fixed << std::setprecision(10);

    double time1 = 0;
    double time2 = 0;

    if (L - x1 - x2 == 0 || x1 == x2) {
        std::cout << "yes" << std::endl;
        std::cout << 0. << std::endl;
    }
    else if (v1 == v2) {
        if (v1 == 0) {
            std::cout << "no" << std::endl;
        }
        else {
            double T = fabs(L / (v1 + v2));
            time2 = ((0 - x2 - x1) / (v1 + v2));

            while (time2 < 0) {
                time2 += T;
            }

            std::cout << "yes" << std::endl;
            std::cout << time2 << std::endl;
        }
    }
    else if (v1 + v2 == 0) {
        double T = fabs(L / (v1 - v2));
        time1 = ((x2 - x1) / (v1 - v2));

        while (time1 < 0) {
                time1 += T;
            }

        std::cout << "yes" << std::endl;
        std::cout << time1 << std::endl;
    }
    else {
        std::vector<double> times = {((x2 - x1) / (v1 - v2)), ((0 - x2 - x1) / (v1 + v2))};
        std::vector<double> periods = {fabs(L / (v1 - v2)), fabs(L / (v1 + v2))};

        if (v1 == 0 || v2 == 0)
        {
            double T = periods[0];
            std::cout << times[0] << ' ' << times[1] << std::endl;
            std::cout << T << std::endl;
            if (more_zero(times[0], times[1]) < 0) {
                double tmp = *std::max_element(times.begin(), times.end());

                while (tmp < 0)
                    tmp += T;

                std::cout << "yes" << std::endl;
                std::cout << tmp << std::endl;
            }
            else {
                if (times[0] > 0 && times[1] > 0) {
                    for (auto& n : times)
                    {
                        while (n > 0)
                            n -= T;

                        n += T;
                    }
                    std::cout << "yes" << std::endl;
                    std::cout << *std::min_element(times.begin(), times.end());
                }
                else {
                    for (auto& n : times)
                    {
                        while (n < 0)
                            n += T;
                    }
                    std::cout << "yes" << std::endl;
                    std::cout << *std::min_element(times.begin(), times.end());
                }
            }
        }

        else {
            double T = *std::min_element(periods.begin(), periods.end());

            if (more_zero(times[0], times[1]) < 0) {
                double tmp = *std::max_element(times.begin(), times.end());

                while (tmp < 0)
                    tmp += T;

                std::cout << "yes" << std::endl;
                std::cout << tmp << std::endl;
            }
            else {
                if (times[0] > 0 && times[1] > 0) {
                    for (auto& n : times)
                    {
                        while (n > 0)
                            n -= T;

                        n += T;
                    }
                    std::cout << "yes" << std::endl;
                    std::cout << *std::min_element(times.begin(), times.end());
                }
                else {
                    std::cout << "yes" << std::endl;
                    std::cout << *std::max_element(times.begin(), times.end());
                }
            }
        }
    }
}
