#pragma once
#include <SDL.h>
#include <vector>
#include "square.h"
#include <SFML/Graphics.hpp>

class canvas
{
public:
	canvas();
	canvas(float offset_x, float offset_y);
	~canvas();

	void render(sf::RenderWindow* window) const;

	float width;
	float height;


private:
	float x_;
	float y_;
	int screen_width_{ 1000 };
	int screen_height_{ 800 };

	std::vector<square*> squares_;

	void init_squares();
	void delete_squares() const;
	void find_square(float x_pos, float y_pos, square* rect) const;
};
