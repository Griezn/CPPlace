#include "game.h"

#include <iostream>

game::game() :
//squares_(0, 0),
window_(nullptr),
renderer_(nullptr),
texture_(nullptr),
rect_(nullptr),
screen_width_(1000),
screen_height_(800),
current_gamestate_(game_state::run_game){
	this->init_rect();
}

game::~game(){
	delete this->rect_;
}

void game::run(){
	if (!this->init()) {
		std::cout << "Failed to initialize" << '\n';
	}
	else {
		if (!this->load_media()) {
			std::cout << "Failed to load media!" << '\n';
		}
		else {
			this->loop();
		}
	}
	this->close();
}

void game::loop(){
	while (current_gamestate_ == game_state::run_game) {
		this->event_handler();
		this->draw();
	}
}

bool game::init(){
	bool succes = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		succes = false;
		std::cout << "Could not initialize SDL! SDL_Error: " << SDL_GetError() << '\n';
	}
	else {
		this->window_ = SDL_CreateWindow("CPPlace", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			this->screen_width_, this->screen_height_, SDL_WINDOW_SHOWN);
		if (this->window_ == nullptr) {
			std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << '\n';
			succes = false;
		}
		else {
			renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
			if (renderer_ == nullptr) {
				std::cout << "Renderer could not be created! SDL_Error: " << SDL_GetError() << '\n';
				succes = false;
			}
			else {
				SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);

				int img_flags = IMG_INIT_PNG;
				if (!(IMG_Init(img_flags) & img_flags)) {
					std::cout << "Could not initialize sdl image! SDL_Error: " << SDL_GetError() << '\n';
					succes = false;
				}
			}

		}
	}
	return succes;
}

bool game::load_media(){
	bool success = true;

	//this->texture_ = load_texture("rocekt.png");
	//if (texture_ == NULL)
	//{
	//	printf("Failed to load texture image!\n");
	//	success = false;
	//}

	return success;
}


void game::close(){
	SDL_DestroyTexture(this->texture_);
	texture_ = nullptr;

	SDL_DestroyRenderer(this->renderer_);
	SDL_DestroyWindow(window_);
	window_ = nullptr;
	renderer_ = nullptr;

	IMG_Quit();
	SDL_Quit();
}

void game::draw(){
	//clean screen, must change to white
	SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer_);

	//render to screen
	//SDL_RenderCopy(renderer_, texture_, nullptr, nullptr);
	rect_->render_square(renderer_);

	//update screen
	SDL_RenderPresent(renderer_);
}

void game::event_handler(){
	SDL_Event e;

	while (SDL_PollEvent(&e) != 0) {
		if (e.type == SDL_QUIT) {
			current_gamestate_ = game_state::quit;
		}
		else if (e.type == SDL_KEYDOWN) {
			switch (e.key.keysym.sym) {
			case SDLK_UP:
				std::cout << "up" << '\n';
			case SDLK_DOWN:
				std::cout << "down" << '\n';
			case SDLK_LEFT:
				std::cout << "left" << '\n';
			case SDLK_RIGHT:
				std::cout << "right" << '\n';
			}
		}
		//TODO: add mouse support
	}
}

void game::init_rect(){
	this->rect_ = new square;
}

SDL_Texture* game::load_texture(std::string path){
	//the texture to return
	SDL_Texture* new_texture = nullptr;

	SDL_Surface* loaded_surface = IMG_Load(path.c_str());
	if (loaded_surface == nullptr) {
		std::cout << "Unable to load image! SDL_Error: " << SDL_GetError() << '\n';

	}
	else {
		new_texture = SDL_CreateTextureFromSurface(renderer_, loaded_surface);
		if (new_texture == nullptr) {
			std::cout << "Unable to create texture from surface! SDL_Error: " << SDL_GetError() << '\n';
		}
		//get rid of the old one, not necessary anymore 
		SDL_FreeSurface(loaded_surface);
	}
	return new_texture;
}
