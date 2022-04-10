#pragma once
#include "square.h"
#include <SDL.h>
#include <SDL_image.h>

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
	//[]square squares_;
	SDL_Window* window_;
	SDL_Renderer* renderer_;
	SDL_Texture* texture_;
	square* rect_;

	int screen_width_;
	int screen_height_;
	game_state current_gamestate_;

	/// @brief The main loop keeps running until the cross is pressed
	void loop();
	/// @brief Initializes the functions of SDL
	/// @return True if success, false if an error occurred 
	bool init();
	/// @brief Loads the textures with the load_texture function
	/// @return True if success, false if an error occurred
	bool load_media();
	/// @brief Frees up memory and closes the SDL functions
	void close();
	/// @brief Render the objects to the screen
	void draw();
	/// @brief Looks for keyboard and mouse input
	void event_handler();
	/// @brief Creates a new rectangle
	void init_rect();
	/// @brief Loads a PNG texture
	/// @param path Path to the texture
	/// @return A pointer to the PNG texture
	SDL_Texture* load_texture(std::string path);
};

