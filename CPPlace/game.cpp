#include "game.h"

#include <iostream>
#include <SDL_image.h>
#include <SFML/Window.hpp>


const sf::Color game::white = sf::Color(0xFF, 0xFF, 0xFF, 0xFF);
const sf::Color game::light_gray = sf::Color(0xE4, 0xE4, 0xE4, 0xFF);
const sf::Color game::gray = sf::Color(0x88, 0x88, 0x88, 0xFF);
const sf::Color game::black = sf::Color(0x22, 0x22, 0x22, 0xFF);
const sf::Color game::pink = sf::Color(0xFF, 0xA7, 0xD1, 0xFF);
const sf::Color game::red = sf::Color(0xE5, 0x00, 0x00, 0xFF);
const sf::Color game::orange = sf::Color(0xE5, 0x95, 0x00, 0xFF);
const sf::Color game::brown = sf::Color(0xA0, 0x6A, 0x42, 0xFF);
const sf::Color game::yellow = sf::Color(0xE5, 0xD9, 0x00, 0xFF);
const sf::Color game::lime = sf::Color(0x94, 0xE0, 0x44, 0xFF);
const sf::Color game::green = sf::Color(0x02, 0xBE, 0x01, 0xFF);
const sf::Color game::appel_blauw = sf::Color(0x00, 0xD3, 0xDD, 0xFF);
const sf::Color game::aqua = sf::Color(0x00, 0x83, 0xC7, 0xFF);
const sf::Color game::blue = sf::Color(0x00, 0x00, 0xEA, 0xFF);
const sf::Color game::magenta = sf::Color(0xCF, 0x6E, 0xE4, 0xFF);
const sf::Color game::purple = sf::Color(0x82, 0x00, 0x80, 0xFF);

game::game() :
	//squares_(0, 0),
	window_(nullptr),
	screen_width_(1000),
	screen_height_(800),
	current_gamestate_(game_state::run_game),
	offset_x_(200),
	offset_y_(100),
	canvas_(new canvas(offset_x_, offset_y_)),
camera_(new camera),
hud_(new hud)
{ }

game::~game(){
	delete this->canvas_;
	delete this->camera_;
	delete this->hud_;
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
		this->mouse_handler();
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

void game::draw() const {
	this->window_->clear();

	this->window_->setView(camera_->view);
	this->canvas_->render(window_);

	this->window_->setView(window_->getDefaultView());
	this->hud_->render_hud(window_);

	this->window_->display();
}

void game::event_handler(){
	sf::Event event{};
	while (this->window_->pollEvent(event)) {
		switch (event.type) {
		case sf::Event::Closed:
			this->current_gamestate_ = game_state::quit;
			break;
		case sf::Event::MouseWheelScrolled:
			if (event.mouseWheelScroll.delta > 0) {
				this->camera_->zoom(true);
			}
			else {
				this->camera_->zoom(false);
			}
			break;
		}
	}
}

void game::keyboard_input() const{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		this->camera_->move(0, -1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		this->camera_->move(0, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		this->camera_->move(-1.0f, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		this->camera_->move(1.0f, 0);
	}
}

void game::mouse_handler() const
{
	sf::Vector2i pixelpos = sf::Mouse::getPosition(*window_);
	sf::Vector2f worldpos = this->window_->mapPixelToCoords(pixelpos);

	this->canvas_->select_square(worldpos.x, worldpos.y);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		this->hud_->hud_mouse_handler(pixelpos.x, pixelpos.y, true);
	}
	else {
		this->hud_->hud_mouse_handler(pixelpos.x, pixelpos.y);
	}
};