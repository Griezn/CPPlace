#include "hud.h"

#include <iostream>

#include "game.h"

void hud::render_hud(sf::RenderWindow* window){
	if (hud_visible_) {
		//the bar
		hud_.setPosition(0, 700);
		hud_.setFillColor(sf::Color(255, 255, 255));
		window->draw(hud_);

		//the color squares
		for (auto color_squar : color_squars_) {
			window->draw(color_squar);
		}
		//the buttons
		hud_close_.setFillColor(sf::Color::White);
		hud_close_.setPosition(520, 760);
		hud_close_.setOutlineThickness(1.f);
		hud_close_.setOutlineColor(sf::Color::Black);
		window->draw(hud_close_);

		hud_confirm_.setFillColor(sf::Color::White);
		hud_confirm_.setPosition(380, 760);
		hud_confirm_.setOutlineThickness(1.f);
		hud_confirm_.setOutlineColor(sf::Color::Black);
		window->draw(hud_confirm_);

	}
	else {
		hud_button_.setPosition(450, 730);
		hud_button_.setOutlineThickness(1.f);
		hud_button_.setOutlineColor(sf::Color::Black);
		window->draw(hud_button_);
	}
}

void hud::hud_mouse_handler(int x, int y, bool click){
	if (click) {
		if (hud_button_.getGlobalBounds().contains(x, y)) {
			hud_visible_ = true;
		}
		if (hud_close_.getGlobalBounds().contains(x, y)) {
			hud_visible_ = false;
		}
	}
	if (hud_visible_) {
		for (int i = 0; i < 16; ++i) {
			if (color_squars_[i].getGlobalBounds().contains(x, y)) {
				color_squars_[i].setOutlineThickness(3.f);
			}
			else {
				color_squars_[i].setOutlineThickness(1.f);
			}
			
		}
	}
	if (hud_visible_ && click) {
		for (int i = 0; i < 16; ++i) {
			if (color_squars_[i].getGlobalBounds().contains(x, y)) {
				color_squars_[i].setOutlineThickness(3.f);
				color_squars_[i].setOutlineColor(sf::Color::Yellow);
				choose_color(color_squars_[i].getFillColor());
			}
			else {
				color_squars_[i].setOutlineThickness(1.f);
				color_squars_[i].setOutlineColor(sf::Color::Black);
			}

		}
	}
}

void hud::draw_clors(){
	for (int i = 0; i < 16; ++i) {
		color_squars_.push_back(sf::RectangleShape(sf::Vector2f(width, 20)));
	}

	color_squars_[0].setFillColor(game::white); 
	color_squars_[1].setFillColor(game::light_gray); 
	color_squars_[2].setFillColor(game::gray); 
	color_squars_[3].setFillColor(game::black); 
	color_squars_[4].setFillColor(game::pink); 
	color_squars_[5].setFillColor(game::red); 
	color_squars_[6].setFillColor(game::orange); 
	color_squars_[7].setFillColor(game::brown); 
	color_squars_[8].setFillColor(game::yellow); 
	color_squars_[9].setFillColor(game::lime); 
	color_squars_[10].setFillColor(game::green);
	color_squars_[11].setFillColor(game::appel_blauw); 
	color_squars_[12].setFillColor(game::aqua); 
	color_squars_[13].setFillColor(game::blue); 
	color_squars_[14].setFillColor(game::magenta); 
	color_squars_[15].setFillColor(game::purple);

	for (int i = 0; i < 16; ++i) {
		color_squars_[i].setPosition((i + 1) * offset + i * width, 722.5);
	}

	for (int i = 0; i < 16; ++i) {
		color_squars_[i].setOutlineThickness(1.f);
		color_squars_[i].setOutlineColor(sf::Color::Black);
	}
}

void hud::choose_color(sf::Color color)
{
	this->chosen_color = color;
}

hud::hud():
chosen_color(sf::Color::Black)
{
	draw_clors();
}
