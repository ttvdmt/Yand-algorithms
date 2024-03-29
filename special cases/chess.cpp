#include <iostream>
/*
На шахматной доске стоят слоны и ладьи, необходимо посчитать, сколько клеток не бьется ни одной из фигур.

Шахматная доска имеет размеры 8 на 8.
Ладья бьет все клетки горизонтали и вертикали, проходящих через клетку, где она стоит, до первой встретившейся фигуры.
Слон бьет все клетки обеих диагоналей, проходящих через клетку, где он стоит, до первой встретившейся фигуры.
*/
void ladya(char (&table)[8][8], int y, int x, int& count)
{
	bool stop1 = true, stop2 = true, stop3 = true, stop4 = true;

	for (int i = 1; i < 8; i++)
	{
		if (x + i < 8 && stop1 && table[y][x + i] != 'R' && table[y][x + i] != 'B') {
			if (table[y][x + i] == '*') {
            	table[y][x + i] = 'x';
            	count++;
			}
		}
        else
        	stop1 = false;

        if (x - i >= 0 && stop2 && table[y][x - i] != 'R' && table[y][x - i] != 'B') {
            if (table[y][x - i] == '*') {
            	table[y][x - i] = 'x';
            	count++;
            }
        }
        else
        	stop2 = false;

        if (y + i < 8 && stop3 && table[y + i][x] != 'R' && table[y + i][x] != 'B') {
            if (table[y + i][x] == '*') {
            	table[y + i][x] = 'x';
            	count++;
            }
        }
        else
        	stop3 = false;

        if (y - i >= 0 && stop4 && table[y - i][x] != 'R' && table[y - i][x] != 'B') {
            if (table[y - i][x] == '*') {
            	table[y - i][x] = 'x';
            	count++;
            }
        }
        else
        	stop4 = false;
    }
    count++;
}

void slon(char (&table)[8][8], int y, int x, int& count)
{
	int stop1 = 1, stop2 = 1, stop3 = 1, stop4 = 1;

	for (int i = 1; i < 8; i++)
	{
		if (x + i < 8 && y + i < 8 && stop1 == 1 && table[y + i][x + i] != 'R' && table[y + i][x + i] != 'B') {
            if (table[y + i][x + i] == '*') {
            	table[y + i][x + i] = 'x';
            	count++;
			}
		}
        else
        	stop1 = 0;

        if (x - i >= 0 && y + i < 8 && stop2 == 1 && table[y + i][x - i] != 'R' && table[y + i][x - i] != 'B') {
            if (table[y + i][x - i] == '*') {
            	table[y + i][x - i] = 'x';
            	count++;
			}
        }
        else
        	stop2 = 0;

        if (x + i < 8 && y - i >= 0 && stop3 == 1 && table[y - i][x + i] != 'R' && table[y - i][x + i] != 'B') {
            if (table[y - i][x + i] == '*') {
            	table[y - i][x + i] = 'x';
            	count++;
			}
		}
        else
        	stop3 = 0;

        if (x - i >= 0 && y - i >= 0 && stop4 == 1 && table[y - i][x - i] != 'R' && table[y - i][x - i] != 'B') {
            if (table[y - i][x - i] == '*') {
            	table[y - i][x - i] = 'x';
            	count++;
			}
        }
        else
        	stop4 = 0;
    }
    count++;	
}

int main()
{
	char table[8][8];
	int count = 0;

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
			std::cin >> table[y][x];
	}

	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			if (table[y][x] == 'R')
				ladya(table, y, x, count);

			else if (table[y][x] == 'B')
				slon(table, y, x, count);
		}
	}
	std::cout << 64 - count << std::endl;
}