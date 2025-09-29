#pragma once

#include <graphics.h>
#include "GameState.h"
#include "Box.h"
#include "configuration.h"
#include <string>

using namespace std;

// Write class named Girl that inherits from GameObject and overrides draw and update functions
class Girl : public GameObject
{
private:
	int direction;
	int gravity;
	int jump;
	int speed;
	int min_y;
	

	public:
		Girl(GameState* gs, const std::string& name, int x, int y, int width, int height)
			:GameObject(gs, name, x, y, width, height)
		{
			// arxikes times sta pedia toy GameObject
			this->m_active = true;
			br.outline_opacity = 0.0f;          // adiafaneia perigrammatos 0
			br.fill_opacity = 1.0f;             // adiafaneia xrwmatos 100
			direction = 0;
			min_y = CanvasHeight - 58;
		}	

		void update(float dt)
		{
			// an o xaraktiras paei aristera
			if (graphics::getKeyState(graphics::SCANCODE_LEFT))
			{
				// an o xaraktiras den einai sto aristero akro
				if (m_pos_x > 0)
				{
					// metakinhsh tou xaraktira aristera
					m_pos_x -= 4;
					direction = 0;
				}
			}
			// an o xaraktiras paei deksia
			if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
			{
				// an o xaraktiras den einai sto deksi akro
				if (m_pos_x < CanvasWidth)
				{
					// metakinhsh tou xaraktira deksia
					m_pos_x += 4;
					direction = 1;
				}
			}

		}

		void draw()
		{
			br.fill_opacity = 1.0f;
			br.outline_opacity = 0.0f;
			
			// Epilogh eikonas analoga me tin kateuthinsi tou xaraktira
			if (direction == 1)
			{
				br.texture = string(AssetsPath) + "playerL.png";
			}
			else
			{
				br.texture = string(AssetsPath) + "playerR.png";
			}

			graphics::drawRect(m_pos_x, m_pos_y, m_width, m_height, br);
		}

		// setter gia to min_y
		void setMinY(int y)
		{
			min_y = y;
		}

		void setGravity(int g)
		{
			gravity = g;
		}
};

