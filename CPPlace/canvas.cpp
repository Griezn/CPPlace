#include "canvas.h"

#include <iostream>
#include <cmath>

#include "game.h"

canvas::canvas() :
	width(600),
	height(600),
	x_(0),
	y_(0)
{
	this->init_squares();
}

canvas::canvas(float offset_x, float offset_y) :
	width(600),
	height(600),
	x_(offset_x),
	y_(offset_y)
{
	this->init_squares();
}

canvas::~canvas(){
	this->delete_squares();
}

void canvas::render(sf::RenderWindow* window) const
{
	for (auto square : this->squares_) {
		square->render_square(window);
	}
	for (auto square : this->squares_) {
		square->highlight = false;
	}
}

void canvas::select_square(float x, float y)
{
	std::cout << x << " " << y << std::endl;
	square* square = nullptr;
	find_square(x - 200, y - 100, square);
}

void canvas::init_squares()
{
	//create all the rects for the screen
	for (int x = 0; x < width; x += width/60) {
		for (int y = 0; y < height; y += height/60) {
			squares_.push_back(new square(game::appel_blauw, x + x_, y + y_));
		}
	}
}

void canvas::delete_squares() const
{
	for (auto square : this->squares_) {
		delete square;
	}
}

void canvas::find_square(float x_pos, float y_pos, square* rect) const{
	int digit = floor(y_pos / 10);
	int tiental = floor(x_pos / 10) * 60;
	int index = tiental + digit;

	if (x_pos >= 0 && x_pos <= 600 ) {
		if (y_pos >= 0 && y_pos <= 600) {
			rect = squares_[index];
			rect->highlight = true;
		}
	}
	std::cout << index << std::endl;
}
