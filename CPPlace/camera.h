#pragma once
#include <SDL.h>

class camera
{
	camera();

	void move(int x, int y);
	void set_position(int x, int y);


private:
	SDL_Rect camera_;
	const int width_;
	const int height_;
};

