#include "canvas.h"

#include <iostream>
#include <cmath>

#include "game.h"

canvas::canvas() :
selected_square(nullptr),
	width(600),
	height(600),
	x_(0),
	y_(0)
{
	this->init_squares();
}

canvas::canvas(float offset_x, float offset_y) :
selected_square(nullptr),
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

void canvas::select_square(float x, float y, bool click)
{
	const auto index = find_square(x - 200, y - 100);

	if (index != NULL) {
		if (click) {
			if (selected_square != nullptr) {
				selected_square->selected = false;
			}
			selected_square = this->squares_[index];
			selected_square->selected = true;
		}
		else {
			this->squares_[index]->highlight = true;
		}
	}
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

int canvas::find_square(float x_pos, float y_pos) const{
	int digit = floor(y_pos / 10);
	int tiental = floor(x_pos / 10) * 60;
	int index = tiental + digit;
	int return_index = NULL;

	if (x_pos >= 0 && x_pos <= 600 ) {
		if (y_pos >= 0 && y_pos <= 600) {
			return_index = index;
		}
	}

	return return_index;
}
