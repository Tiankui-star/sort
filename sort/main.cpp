#include<iostream>
#include"quick_sort.h"
#include"merge_sort.h"
#include<Windows.h>
int main()
{
	std::cout << "choice 0: quick sort" << std::endl << "choice 1: merge sort" << std::endl;
	int choice;
	std::cin >> choice;
	if (!choice)
	{
		quick_sort quick;
		std::cout << "do you want random generate or input?" << std::endl << "0-random" << std::endl << "1-input" << std::endl;
		int t;
		std::cin >> t;
		if (!t)
		{
			quick.set();
			Sleep(3000);
			quick.algorithm_sort(0, quick.a.size() - 1);
		}
		else
		{
			quick.input();
			quick.algorithm_sort(0, quick.a.size() - 1);
		}
	}
	else
	{
		merge_sort merge;
		std::cout << "do you want random generate or input?" << std::endl << "0-random" << std::endl << "1-input" << std::endl;
		int t;
		std::cin >> t;
		if (!t)
		{
			merge.set();
			Sleep(3000);
			merge.algorithm_sort(0, merge.a.size() - 1);
		}
		else
		{
			merge.input();
			merge.algorithm_sort(0, merge.a.size() - 1);
		}
	}

	return 0;
}