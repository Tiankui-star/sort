#include<vector>
#include<random>
#include<iostream>
#include<iomanip>
#pragma once
template<typename T>
class sort
{
public:
	virtual void algorithm_sort(int low, int high) = 0;
	T size, t;
	std::vector<T> a;
	int sort_count = 0;
	void set();
	void input();
};
template<typename T>
void sort<T>::set()
{
	std::random_device rd;
	int count = 0;
	std::mt19937 ged(rd());
	std::uniform_int_distribution<> dis1(1, 100);
	std::uniform_int_distribution<> dis2(1, 100); //生成int/double型随机数 uniform_int_distribution<> int/ uniform_real_distribution<> double
	size = dis1(ged);
	std::cout << "generate " << size << " digitals and they are" << std::endl;
	for (int i = 0; i < size; i++)
	{
		t = dis2(ged);
		std::cout << std::fixed << std::setprecision(2) << std::setw(5) << t << ' ';
		count++;
		if (count == 10)
		{
			std::cout << std::endl;
			count = 0;
		}
		a.push_back(t);
	}
	if (count != 0) std::cout << std::endl;
	std::cout << std::endl;
}
template<typename T>
void sort<T>::input()
{
	std::cout << "Do you want random generate a size?" << std::endl << "0-NO" << std::endl << "1-YES" << std::endl;
	int choice;
	std::cin >> choice;
	if (choice)
	{
		std::random_device rd;
		std::mt19937 ged(rd());
		std::uniform_int_distribution<> dis(1, 20);
		size = dis(ged);
		std::cout << "the number of digital you need to input is: " << size << std::endl;
		for (int i = 0; i < size; i++)
		{
			std::cin >> t;
			a.push_back(t);
		}
	}
	else
	{
		std::cout << "input the size of the sequence that you want to sort" << std::endl;
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			std::cin >> t;
			a.push_back(t);
		}
	}
}
