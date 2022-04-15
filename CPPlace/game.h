#pragma once
#include <SDL.h>
#include <string>
#include "canvas.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

enum class game_state {
	run_game,
	quit,
};

class game
{
public:
	/// Initializes variables
	game();
	/// Deallocation of memory 
	~game();

	/// @brief Starts the game
	void run();

private:
	sf::RenderWindow* window_;
	//SDL_Window* window_;
	//SDL_Renderer* renderer_;

	int screen_width_;
	int screen_height_;
	game_state current_gamestate_;

	float offset_x_;
	float offset_y_;

	canvas* canvas_;

	void loop();
	bool init();
	void close();
	void draw() const;
	void event_handler();
	void keyboard_input() const;
};
