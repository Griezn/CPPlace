#include "game.h"

#include <iostream>
#include <SDL_image.h>
#include <SFML/Window.hpp>

game::game() :
	//squares_(0, 0),
	window_(nullptr),
	screen_width_(1000),
	screen_height_(800),
	current_gamestate_(game_state::run_game),
	offset_x_(200),
	offset_y_(100),
	canvas_(new canvas(offset_x_, offset_y_))
{ }

game::~game(){
	delete this->canvas_;
}

void game::run(){
	if (!this->init()) {
		std::cout << "Failed to initialize" << '\n';
	}
	else {
		this->loop();
	}
	this->close();
}

void game::loop(){
	while (current_gamestate_ == game_state::run_game) {
		this->event_handler();
		this->keyboard_input();
		this->draw();
	}
}

bool game::init(){
	bool succes = true;
	this->window_ = new sf::RenderWindow(sf::VideoMode(screen_width_, screen_height_), "CPPlace");
	return succes;
}

void game::close(){
	delete this->window_;
}

void game::draw() const{
	this->window_->clear();

	this->canvas_->render(window_);

	this->window_->display();
}

void game::event_handler(){
	sf::Event event;
	while (this->window_->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			this->current_gamestate_ = game_state::quit;
			break;
		}
	}
}

void game::keyboard_input() const{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) {
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
	}
}
