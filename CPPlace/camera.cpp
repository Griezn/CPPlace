#include "camera.h"
camera::camera():
camera_(SDL_Rect{0, 0, 1000, 800}),
width_(1000),
height_(800)
{}

void camera::move(int x, int y){}

void camera::set_position(int x, int y){
	this->camera_.x = x;
	this->camera_.y = y;
}
