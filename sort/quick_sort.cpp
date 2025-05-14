#include "quick_sort.h"
#include<algorithm>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<Windows.h>
void quick_sort::algorithm_sort(int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = part(low, high);
		int t_count = 0;
		std::cout << "this is the " << ++sort_count << " times quick sort" << std::endl;
		for (int i = 0; i < a.size(); i++)
		{
			std::cout << std::fixed << std::setprecision(2) << std::setw(5) << a[i] << ' ';
			if (++t_count == 10)
			{
				std::cout << std::endl;
				t_count = 0;
			}
		}
		if (t_count != 0) std::cout << std::endl;
		std::cout << std::endl;
		Sleep(1000);
		algorithm_sort(low, mid - 1);
		algorithm_sort(mid + 1, high);	
	}
}
int quick_sort::part(int low, int high)
{
	//int point = a[low] + a[high] + a[(low + high) / 2] - std::min(std::min(a[low], a[(high + low) / 2]), a[high]) - std::max(std::max(a[low], a[(low + high) / 2]), a[high]);
	int i = low - 1, j;
	int point = a[high];
	for (j = low; j < high; j++)
	{
		if (a[j] <= point)
		{
			i++;
			std::swap(a[i], a[j]);
		}
	}
	std::swap(a[i + 1], a[high]);

	return i + 1;
}