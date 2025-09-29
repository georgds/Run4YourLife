#pragma once
#include <graphics.h>
#include "GameState.h"
#include "Box.h"
#include "configuration.h"

class Enemy : public GameObject {

	string path;
	float r,u;
	float oldTime = 0;

public:

	Enemy(GameState* gs, const std::string& name, int x, int y, int width, int height)
		:GameObject(gs, name, x, y, width, height)
	{
		// arxikes times sta pedia toy GameObject
		this->m_active = true;
		br.outline_opacity = 0.0f;          // adiafaneia perigrammatos 0
		br.fill_opacity = 1.0f;             // adiafaneia xrwmatos 100

		// Tyxaio eikonidio
		int random = rand() % 3;
		if (random == 0)
		{
			path = string(AssetsPath) + "enemy1.png";
		}
		else if (random == 1)
		{
			path = string(AssetsPath) + "enemy2.png";
		}
		else
		{
			path = string(AssetsPath) + "enemy3.png";
		}

		// Tyxaia gwnia gia tin kinisi
		r = rand() % 360 + 200;
		u = rand() % 360 + 200;
	}


	void draw()
	{
		br.texture = path;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;

		graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, br);
	}

	void update(float ms) {

		// Dimiourgei kathisterisi
		if (graphics::getGlobalTime() - oldTime < 15)
			return;
		oldTime = graphics::getGlobalTime();

		// Kanei kykliki kinisi
		m_pos_x += 3 * sinf(graphics::getGlobalTime() / r);
		m_pos_y += 3 * cosf(graphics::getGlobalTime() / u);
	}
};