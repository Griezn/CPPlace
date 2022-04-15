#include "square.h"

square::square():
color_(colors::black),
x_(0.0f),
y_(0.0f),
width_(10.0f),
height_(10.0f),
rect_(sf::RectangleShape(sf::Vector2f(width_, height_))) {}

square::square(const colors color, const float x, const float y):
color_(color),
x_(x),
y_(y),
width_(10),
height_(10),
rect_(sf::RectangleShape(sf::Vector2f(width_, height_))){
	this->rect_.setPosition(x_, y_);
}

void square::render_square(sf::RenderWindow* window){
	switch (color_) {
	case colors::white: rect_.setFillColor(sf::Color( 0xFF, 0xFF, 0xFF, 0xFF)); break;
	case colors::light_gray: rect_.setFillColor(sf::Color( 0xE4, 0xE4, 0xE4, 0xFF)); break;
	case colors::gray: rect_.setFillColor(sf::Color( 0x88, 0x88, 0x88, 0xFF)); break;
	case colors::black:rect_.setFillColor(sf::Color( 0x22, 0x22, 0x22, 0xFF)); break;
	case colors::pink: rect_.setFillColor(sf::Color( 0xFF, 0xA7, 0xD1, 0xFF)); break;
	case colors::red: rect_.setFillColor(sf::Color( 0xE5, 0x00, 0x00, 0xFF)); break;
	case colors::orange: rect_.setFillColor(sf::Color( 0xE5, 0x95, 0x00, 0xFF)); break;
	case colors::brown:rect_.setFillColor(sf::Color( 0xA0, 0x6A, 0x42, 0xFF)); break;
	case colors::yellow: rect_.setFillColor(sf::Color( 0xE5, 0xD9, 0x00, 0xFF)); break;
	case colors::lime: rect_.setFillColor(sf::Color( 0x94, 0xE0, 0x44, 0xFF)); break;
	case colors::green: rect_.setFillColor(sf::Color( 0x02, 0xBE, 0x01, 0xFF)); break;
	case colors::appel_blauw: rect_.setFillColor(sf::Color( 0x00, 0xD3, 0xDD, 0xFF)); break;
	case colors::aqua: rect_.setFillColor(sf::Color( 0x00, 0x83, 0xC7, 0xFF)); break;
	case colors::blue: rect_.setFillColor(sf::Color( 0x00, 0x00, 0xEA, 0xFF)); break;
	case colors::magenta: rect_.setFillColor(sf::Color( 0xCF, 0x6E, 0xE4, 0xFF)); break;
	case colors::purple: rect_.setFillColor(sf::Color( 0x82, 0x00, 0x80, 0xFF)); break;
	}
	window->draw(rect_);
}

void square::update(const colors color){
	this->color_ = color;
}
