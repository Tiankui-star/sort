#include"sort.h"
#include <SFML/Graphics.hpp>

#pragma once
class merge_sort : public sort<int> //ģ���Ϊdouble��
{
public:
	void algorithm_sort(int left,int right,sf::RenderWindow& window);
	void merge(int left,int mid, int right);
	void drawArray(sf::RenderWindow& window, const std::string& title);
};

