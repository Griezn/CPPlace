#pragma once
#include <SDL.h>
#include <SFML/Graphics.hpp>

class square{
public:
	square();
	square(const sf::Color color, const float x, const float y);

	void render_square(sf::RenderWindow* window);
	void update(const sf::Color color);

	bool highlight = false;
	bool selected = false;

private:
	sf::Color color_;
	float x_;
	float y_;
	float width_;
	float height_;

	sf::RectangleShape rect_;

};

