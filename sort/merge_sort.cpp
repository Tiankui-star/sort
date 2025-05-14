#include "merge_sort.h"
#include<vector>
#include<iomanip>
#include<Windows.h>
void merge_sort::merge(int left,int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;
	std::vector<int>L(n1), R(n2); //修改为double生成double型随机数
	for (int i = 0; i < n1; i++)
		L[i] = a[i+left];
	for (int j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];
	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		a[k] = R[j];
		k++;
		j++;
	}
}
void merge_sort::algorithm_sort(int left, int right)
{
	if (left >= right) return;
	int mid = (left+right)/2;

	algorithm_sort(left, mid);
	algorithm_sort(mid + 1, right);
	merge(left, mid, right);
	int t_count = 0;
	std::cout << "this is the " << ++sort_count << " times quick sort" << std::endl;
	for (int i = 0; i < a.size(); i++)
	{
		std::cout  << std::fixed << std::setprecision(2) << std::setw(5) << a[i] << ' ';
		if (++t_count == 10)
		{
			std::cout << std::endl;
			t_count = 0;
		}
	}
	if (t_count != 0) std::cout << std::endl;
	std::cout << std::endl;
	Sleep(1000);
}