#pragma once
#include <graphics.h>
#include "GameState.h"
#include "Box.h"
#include "configuration.h"

class Heart : public GameObject {

public:

	Heart(GameState* gs, const std::string& name, int x, int y, int width, int height)
		:GameObject(gs, name, x, y, width, height)
	{
		// arxikes times sta pedia toy GameObject
		this->m_active = true;
		br.outline_opacity = 0.0f;          // adiafaneia perigrammatos 0
		br.fill_opacity = 1.0f;             // adiafaneia xrwmatos 100
	}


	void draw()
	{
		br.texture = string(AssetsPath) + "heart.png";
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;

		graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, br);
	}
}; 
