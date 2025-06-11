#include<iostream>
#include"quick_sort.h"
#include"merge_sort.h"
#include<Windows.h>
#include<filesystem>
int main()
{
	//std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
	std::cout << "choice 0: quick sort" << std::endl << "choice 1: merge sort" << std::endl;
	int choice;
	std::cin >> choice;
	if (!choice)
	{
		sf::RenderWindow window(sf::VideoMode(800, 600), "Quick Sort Visualization");
		quick_sort quick;
		std::cout << "do you want random generate or input?" << std::endl << "0-random" << std::endl << "1-input" << std::endl;
		int t;
		std::cin >> t;
		if (!t)
		{
			quick.set();
			Sleep(3000);
			//quick.algorithm_sort(0, quick.a.size() - 1,window);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				quick.algorithm_sort(0, quick.a.size() - 1, window);
				window.clear(sf::Color::White);
				quick.drawArray(window, "Sorting Complete");
				window.display();

				// 等待关闭窗口
				sf::sleep(sf::seconds(5));
				window.close();
			}
		}
		else
		{
			quick.input();
			//quick.algorithm_sort(0, quick.a.size() - 1,window);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				quick.algorithm_sort(0, quick.a.size() - 1, window);
				window.clear(sf::Color::White);
				quick.drawArray(window, "Sorting Complete");
				window.display();

				// 等待关闭窗口
				sf::sleep(sf::seconds(5));
				window.close();
			}
		}
	}
	else
	{
		merge_sort merge;
		sf::RenderWindow window(sf::VideoMode(800, 600), "Merge Sort Visualization");
		std::cout << "do you want random generate or input?" << std::endl << "0-random" << std::endl << "1-input" << std::endl;
		int t;
		std::cin >> t;
		if (!t)
		{
			merge.set();
			Sleep(3000);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				merge.algorithm_sort(0, merge.a.size() - 1, window);
				window.clear(sf::Color::White);
				merge.drawArray(window, "Sorting Complete");
				window.display();

				// 等待关闭窗口
				sf::sleep(sf::seconds(5));
				window.close();
			}
			//merge.algorithm_sort(0, merge.a.size() - 1);
		}
		else
		{
			merge.input();
			//merge.algorithm_sort(0, merge.a.size() - 1,window);
			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}
				merge.algorithm_sort(0, merge.a.size() - 1, window);
				window.clear(sf::Color::White);
				merge.drawArray(window, "Sorting Complete");
				window.display();

				// 等待关闭窗口
				sf::sleep(sf::seconds(5));
				window.close();
			}
		}
	}

	return 0;
}