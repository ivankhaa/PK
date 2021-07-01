/**
* @file PK.срр
* @author Харченко И.Ю., гр. 515-В
* @date 03 июля 2021
* @brief Практична работа
*/
#include <stdio.h>
#include <locale.h>
/**
* @param xa, ya, xb, yb - координаты фигур
* @return 1 - если ферзь атакует фигуру. 0 - если ферзь НЕ атакует фигуру
*/
int check(int,int,int,int);
int main()
{
	setlocale(LC_ALL, "RUS");
	char a[3], b[3];
	printf("Введите координаты ферзя: ");
	fgets(a, 3, stdin);
	getchar();
	printf("Введите координаты фигуры: ");
	fgets(b, 3, stdin);
	a[0] = a[0] - 96;
	b[0] = b[0] - 96;
	if (a[0] < 0)
	{
		b[0] = b[0] + 32;
		a[0] = a[0] + 32;
	}
	int xa = a[0];
	int ya = a[1] - 48;
	int xb = b[0];
	int yb = b[1] - 48;

	if (check(xa, ya, xb, yb))
		printf("\nФерзь атакует фигуру\n");
	else
		printf("\nФерзь НЕ атакует фигуру\n");
}

int check(int xa, int ya, int xb, int yb)
{
	if (xa == xb || ya == yb)
	{
		return 1;
	}

	for (int x = xa, y = ya; x <= 8 && x > 0; y++,x++)
	{
		if (x == xb && y == yb) 
		{
				return 1;
		}
	}
	
	for (int x = xa, y = ya; x <= 8 && x > 0; y--, x--)
	{
		if (x == xb && y == yb)
		{
			return 1;
		}
	}
	
	for (int x = xa,  y = ya; x <= 8 && x > 0; y++, x--)
	{
		if (x == xb && y == yb)
		{
			return 1;
		}
	}
	
	for (int x = xa, y = ya; x <= 8 && x > 0; y--, x++)
	{
		if (x == xb && y == yb)
		{
			return 1;
		}
	}
	return 0;
}
