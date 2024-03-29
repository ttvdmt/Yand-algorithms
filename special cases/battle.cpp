#include <iostream>
#include <vector>
#include <algorithm>
/*
Вы играете в интересную стратегию. У вашего соперника остались всего одна казарма — здание,
в котором постоянно появляются новые солдаты. Перед атакой у вас есть x солдат. 
За один раунд каждый солдат может убить одного из солдат противника или нанести 1 очко урона казарме (вычесть единицу здоровья у казармы).
Изначально у вашего оппонента нет солдат. Тем не менее, его казарма имеет y единиц здоровья и производит p солдат за раунд.

Ход одного раунда:

Каждый солдат из вашей армии либо убивает одного из солдат вашего противника, либо наносит 1 очко урона казарме.
Каждый солдат может выбрать своё действие. Когда казарма теряет все свои единицы здоровья, она разрушается.

Ваш противник атакует. Он убьет k ваших солдат, где k — количество оставшихся у противника солдат.
Если казармы еще не разрушены, ваш противник производит p новых солдат.

Ваша задача — разрушить казарму и убить всех солдат противника.
Если это возможно, посчитайте минимальное количество раундов, которое вам нужно для этого.
В противном случае выведите -1.
*/
void attack(int rounds, int army, int hp, int epr, int enemies, std::vector<int>& results)
{
    if (army == enemies) {
        results.push_back(1'000'000);
        return;
    }
    int apr = army;

    apr -= enemies;
    enemies = 0;
    hp -= apr;

    rounds++;

    if (rounds != 1)
        army -= enemies;
    if (hp > 0)
        enemies += epr;

    while (hp > 0 || enemies > 0)
    {
        int dapr = army;
        if (army <= 0) {
            rounds = 1'000'000;
            break;
        }
        
        if (hp > 0 && hp <= dapr) {
            attack(rounds, army, hp, epr, enemies, results);
            dapr -= hp;
            hp = 0;
            enemies -= dapr;
        }
        else if (hp <= 0)
            enemies -= dapr;

        rounds++;
        
        if (rounds != 1)
            army -= enemies;
        if (hp > 0)
            enemies += epr;
    }
    results.push_back(rounds);
}

int main() {
    int army, hp, epr;
    std::cin >> army >> hp >> epr;

    int rounds = 0;
    int enemies = 0;
    bool tower_alive = true;
    std::vector<int> results;
    
    while (tower_alive || enemies > 0)
    {
        if (army <= 0) {
            rounds = 1'000'000;
            break;
        }

        if (rounds == 0) {
            hp -= army;
            rounds++;
        }
        else {
            int apr = army;

            if (tower_alive && hp >= apr && enemies < apr) {
                apr -= enemies;
                enemies = 0;
                hp -= apr;
            }
            else if (tower_alive && hp <= apr) {
                attack(rounds, army, hp, epr, enemies, results);
                apr -= hp;
                hp = 0;
                enemies -= apr;
            }
            else if (!tower_alive)
                enemies -= apr;

            rounds++;
        }
       
        if (hp <= 0)
            tower_alive = false;
        if (rounds != 1)
            army -= enemies;
        if (tower_alive)
            enemies += epr;
    }
    results.push_back(rounds);
    if (*std::min_element(results.begin(), results.end()) == 1'000'000)
        std::cout << -1 << std::endl;
    else
        std::cout << *std::min_element(results.begin(), results.end()) << std::endl;
}