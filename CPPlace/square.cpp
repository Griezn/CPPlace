#include "square.h"

#include <iostream>
#include <utility>

square::square():
color_(colors::black),
x_(0.0f),
y_(0.0f),
width_(10.0f),
height_(10.0f),
rect_(SDL_FRect{x_, y_, width_, height_}){}

square::square(const colors color, const float x, const float y):
color_(color),
x_(x),
y_(y),
width_(10),
height_(10),
rect_(SDL_FRect{ x_, y_, width_, height_ }) {}

void square::render_square(SDL_Renderer* renderer) const{
	switch (color_) {
	case colors::white: SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); break;
	case colors::light_gray: SDL_SetRenderDrawColor(renderer, 0xE4, 0xE4, 0xE4, 0xFF); break;
	case colors::gray: SDL_SetRenderDrawColor(renderer, 0x88, 0x88, 0x88, 0xFF); break;
	case colors::black:SDL_SetRenderDrawColor(renderer, 0x22, 0x22, 0x22, 0xFF); break;
	case colors::pink: SDL_SetRenderDrawColor(renderer, 0xFF, 0xA7, 0xD1, 0xFF); break;
	case colors::red: SDL_SetRenderDrawColor(renderer, 0xE5, 0x00, 0x00, 0xFF); break;
	case colors::orange: SDL_SetRenderDrawColor(renderer, 0xE5, 0x95, 0x00, 0xFF); break;
	case colors::brown:SDL_SetRenderDrawColor(renderer, 0xA0, 0x6A, 0x42, 0xFF); break;
	case colors::yellow: SDL_SetRenderDrawColor(renderer, 0xE5, 0xD9, 0x00, 0xFF); break;
	case colors::lime: SDL_SetRenderDrawColor(renderer, 0x94, 0xE0, 0x44, 0xFF); break;
	case colors::green: SDL_SetRenderDrawColor(renderer, 0x02, 0xBE, 0x01, 0xFF); break;
	case colors::appel_blauw: SDL_SetRenderDrawColor(renderer, 0x00, 0xD3, 0xDD, 0xFF); break;
	case colors::aqua: SDL_SetRenderDrawColor(renderer, 0x00, 0x83, 0xC7, 0xFF); break;
	case colors::blue: SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xEA, 0xFF); break;
	case colors::magenta: SDL_SetRenderDrawColor(renderer, 0xCF, 0x6E, 0xE4, 0xFF); break;
	case colors::purple: SDL_SetRenderDrawColor(renderer, 0x82, 0x00, 0x80, 0xFF); break;
	}
	SDL_RenderFillRectF(renderer, &rect_);
}

void square::update(const colors color){
	this->color_ = color;
}
