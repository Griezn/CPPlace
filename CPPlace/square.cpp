#include "square.h"

#include "game.h"

square::square():
color_(game::black),
x_(0.0f),
y_(0.0f),
width_(10.0f),
height_(10.0f),
rect_(sf::RectangleShape(sf::Vector2f(width_, height_))) {}

square::square(const sf::Color color, const float x, const float y):
color_(color),
x_(x),
y_(y),
width_(10),
height_(10),
rect_(sf::RectangleShape(sf::Vector2f(width_, height_))){
	this->rect_.setPosition(x_, y_);
}

void square::render_square(sf::RenderWindow* window){
	rect_.setFillColor(color_);
	if (highlight == true) {
		rect_.setOutlineThickness(1.0f);
		rect_.setOutlineColor(game::red);
	}
	else {
		rect_.setOutlineThickness(0.0f);
		rect_.setOutlineColor(color_);
	}
	window->draw(rect_);
}

void square::update(const sf::Color color){
	this->color_ = color;
}
