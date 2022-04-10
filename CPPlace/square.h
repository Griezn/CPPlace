#pragma once
#include <string>
#include <SDL.h>

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

class square
{
public:
	square();
	square(colors color, int x, int y);

	void render_square(SDL_Renderer* renderer);
	void update(colors color);

private:
	colors color_;
	const int x_;
	const int y_;
	const int width_;
	const int height_;

	SDL_Rect rect_;

};

