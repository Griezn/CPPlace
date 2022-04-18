#pragma once
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
	void select_square(float x, float y);

	float width;
	float height;


private:
	float x_;
	float y_;

	std::vector<square*> squares_;

	void init_squares();
	void delete_squares() const;
	void find_square(float x_pos, float y_pos, square* rect) const;
};
