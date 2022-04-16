#pragma once
#include "canvas.h"

class hud
{
public:
	hud();

	void render_hud(sf::RenderWindow* window);
	void hud_mouse_handler(int x, int y, bool click = false);

	sf::Color chosen_color;

private:

	std::vector<sf::RectangleShape> color_squars_;
	bool hud_visible_{false};
	sf::RectangleShape hud_{sf::Vector2f(1000, 100)};
	sf::RectangleShape hud_button_{ sf::Vector2f(100, 30) };
	sf::RectangleShape hud_close_{ sf::Vector2f(100, 20) };
	sf::RectangleShape hud_confirm_{ sf::Vector2f(100, 20) };

	float offset{25.9f};
	float width{ 35 };

	void draw_clors();
	void choose_color(sf::Color color);
};

