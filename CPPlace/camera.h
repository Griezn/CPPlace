#pragma once
#include <SFML/Graphics.hpp>

class camera
{
public:
	camera();

	void move(float x, float y);
	void zoom(bool in);

	sf::View view;


private:
	sf::FloatRect view_rect_ = sf::FloatRect(0, 0, 1000, 800);

	float scale_factor_ = 1;

};

