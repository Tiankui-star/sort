#include"sort.h"
#pragma once
class quick_sort : public sort<int> //ģ������int/double�������������
{
public:
	void algorithm_sort(int left, int right, sf::RenderWindow& window);
	int part(int low, int high);
	void drawArray(sf::RenderWindow& window, const std::string& title);
};

