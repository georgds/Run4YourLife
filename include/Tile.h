#pragma once
#include <graphics.h>
#include "GameState.h"
#include "Box.h"
#include "configuration.h"

class Tile : public GameObject {

	protected:
	int length;

public:

	Tile(GameState* gs, const std::string& name, int x, int y, int width, int height, int l)
		:GameObject(gs, name, x, y, width, height)
	{
		// arxikes times sta pedia toy GameObject
		this->m_active = true;
		br.outline_opacity = 0.0f;          // adiafaneia perigrammatos 0
		br.fill_opacity = 1.0f;             // adiafaneia xrwmatos 100
		length = l;
	}


	void draw()
	{
		br.texture = string(AssetsPath) + "Tile_02.png";
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;

		// To ena tile meta to allo
		for (int i = 0; i < length; i++)
		{
			graphics::drawRect(m_pos_x + i * m_width, m_pos_y, m_width, m_height, br);
		}
	}
};