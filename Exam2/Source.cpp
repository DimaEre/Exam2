#include<iostream>
#include<string>
#include<windows.h>
#include <vector>

using namespace std;

int main() 
{
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	vector<int> a;
	vector<vector<int>> b;
	vector<vector<int>> vec;
	int M = 0, N = 0, command1 = 0, command2 = 0;

	while (M <= 0 || N <= 0)
	{
		cout << "Введіть кількість рядків:	";
		cin >> M;
		cout << "Введіть кількість стовпців:	";
		cin >> N;
	}
	a.resize(N, 0);
	vec.resize(M, a);
	b.resize(M, a);

	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			vec[i][j] = rand() % 10;
		}
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
	while (command1 <= 0 || command1 > 4)
	{
		cout << "1 - вліво, 2 - вправо, 3 - вверх, 4 - вниз:	";
		cin >> command1;
	}
	while (command2 <= 0)
	{
		cout << "На скільки рядків/стовпців хочете зсунути:	";
		cin >> command2;
	}
	if (command1 == 1)
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (j + command2 < N)
				{
					b[i][j] = vec[i][j + command2];
				}
				else
				{
					b[i][j] = vec[i][command2 - (N - j)];
				}
			}
			
		}
		vec.clear();
		for (size_t j = 0; j < b.size(); j++)
		{
			vec.push_back(b[j]);
		}
	}
	else if (command1 == 2)
	{
		for (size_t i = 0; i < M; i++)
		{
			for (size_t j = 0; j < N; j++)
			{
				if (j + command2 < N)
				{
					b[i][j + command2] = vec[i][j];
				}
				else
				{
					b[i][command2 - (N - j)] = vec[i][j];
				}
			}
		}
		vec.clear();
		for (size_t j = 0; j < b.size(); j++)
		{
			vec.push_back(b[j]);
		}
	}
	else if (command1 == 3)
	{
		for (size_t i = 0; i < command2; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (j != M - 1)
				{
					b[j].swap(vec[j + 1]);
				}
				else
				{
					b[j].swap(vec[0]);
				}
			}
			vec.clear();
			for (size_t j = 0; j < b.size(); j++)
			{
				vec.push_back(b[j]);
			}

		}
	}
	else if (command1 == 4)
	{
		for (size_t i = 0; i < command2; i++)
		{
			for (size_t j = 0; j < M; j++)
			{
				if (j != 0)
				{
					b[j].swap(vec[j - 1]);
				}
				else
				{
					b[j].swap(vec[M - 1]);
				}
			}
			vec.clear();
			for (size_t j = 0; j < b.size(); j++)
			{
				vec.push_back(b[j]);
			}

		}
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cout << vec[i][j] << " ";
		}
		cout << endl;
	}
}