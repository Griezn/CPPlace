#include "hud.h"

#include <iostream>

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
	color_squars_[2].setFillColor(sf::Color(0x88, 0x88, 0x88, 0xFF)); 
	color_squars_[3].setFillColor(sf::Color(0x22, 0x22, 0x22, 0xFF)); 
	color_squars_[4].setFillColor(sf::Color(0xFF, 0xA7, 0xD1, 0xFF)); 
	color_squars_[5].setFillColor(sf::Color(0xE5, 0x00, 0x00, 0xFF)); 
	color_squars_[6].setFillColor(sf::Color(0xE5, 0x95, 0x00, 0xFF)); 
	color_squars_[7].setFillColor(sf::Color(0xA0, 0x6A, 0x42, 0xFF)); 
	color_squars_[8].setFillColor(sf::Color(0xE5, 0xD9, 0x00, 0xFF)); 
	color_squars_[9].setFillColor(sf::Color(0x94, 0xE0, 0x44, 0xFF)); 
	color_squars_[10].setFillColor(sf::Color(0x02, 0xBE, 0x01, 0xFF)); 
	color_squars_[11].setFillColor(sf::Color(0x00, 0xD3, 0xDD, 0xFF)); 
	color_squars_[12].setFillColor(sf::Color(0x00, 0x83, 0xC7, 0xFF)); 
	color_squars_[13].setFillColor(sf::Color(0x00, 0x00, 0xEA, 0xFF)); 
	color_squars_[14].setFillColor(sf::Color(0xCF, 0x6E, 0xE4, 0xFF)); 
	color_squars_[15].setFillColor(sf::Color(0x82, 0x00, 0x80, 0xFF));

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
