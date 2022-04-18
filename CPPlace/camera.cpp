#include "camera.h"

#include <iostream>

camera::camera()
{
	this->view = sf::View(view_rect_);
}

void camera::move(float x, float y)
{
	this->view.move(x, y);
}

void camera::zoom(bool in)
{
	if (in) {
		if (scale_factor_ > 0.5f) {
			scale_factor_ *= 0.95f;
			this->view.zoom(0.95f);
		}
	}
	else {
		if (scale_factor_ <= 1.0f) {
			scale_factor_ *= 1.05f;
			this->view.zoom(1.05f);
		}
	}
}


