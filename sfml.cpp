#include <iostream>
#include <SFML/Graphics.hpp>


using namespace sf;


int main()
{
	RenderWindow window(VideoMode(400, 400), "12");
	RectangleShape pr;
	pr.setSize(Vector2f(20, 30));
	pr.setFillColor(Color::Blue);
	pr.setPosition(0, 0);
	int i = 20;
	int j = 0;
	bool k = 1;
	while (window.isOpen())
	{
		Event even;
		while (window.pollEvent(even))
		{
			if (even.type == Event::Closed)
				window.close();
			if (even.type == Event::MouseButtonPressed) {
				j = 1;
			}
			else if (even.key.code == Mouse::Right)
				j = 0;
		}
		window.clear(Color::White);
		if (j == 1) {
			if (i == 200) k = 0;
			if (i == 20) k = 1;
			if (k == 1) i = i + 10;
			if (k == 0) i = i - 10;
			pr.setSize(Vector2f(20, i));
		}
		window.draw(pr);
		sleep(sf::milliseconds(50));
		window.display();
	}
	return 0;
}