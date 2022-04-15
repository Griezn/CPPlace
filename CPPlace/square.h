#pragma once
#include <SDL.h>
#include <SFML/Graphics.hpp>

enum class colors {
	white,
	light_gray,
	gray,
	black,
	pink,
	red,
	orange,
	brown,
	yellow,
	lime,
	green,
	appel_blauw,
	aqua,
	blue,
	magenta,
	purple
};

class square{
public:
	square();
	square(const colors color, const float x, const float y);

	void render_square(sf::RenderWindow* window);
	void update(const colors color);

private:
	colors color_;
	float x_;
	float y_;
	float width_;
	float height_;

	sf::RectangleShape rect_;

};

