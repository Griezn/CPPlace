#pragma once
#include <SDL.h>
#include <string>
#include "canvas.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "camera.h"
#include "hud.h"

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

	/// predefined colors
	static const sf::Color white;
	static const sf::Color light_gray;
	static const sf::Color gray;
	static const sf::Color black;
	static const sf::Color pink;
	static const sf::Color red;
	static const sf::Color orange;
	static const sf::Color brown;
	static const sf::Color yellow;
	static const sf::Color lime;
	static const sf::Color green;
	static const sf::Color appel_blauw;
	static const sf::Color aqua;
	static const sf::Color blue;
	static const sf::Color magenta;
	static const sf::Color purple;

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
	camera* camera_;
	hud* hud_;

	void loop();
	bool init();
	void close();
	void draw() const;
	void event_handler();
	void keyboard_input();
	void mouse_handler();
	void update_square();
};
