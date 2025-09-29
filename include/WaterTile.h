#pragma once
#include <graphics.h>
#include "GameState.h"
#include "Tile.h"
#include "configuration.h"
#include <string>

// Write class named WaterTile that inherits from Tile and overrides draw function
class WaterTile : public Tile {

	public:

		WaterTile(GameState* gs, const std::string& name, int x, int y, int width, int height, int l)
			:Tile(gs, name, x, y, width, height, l)
		{
		}

		void draw()
		{
			br.texture = string(AssetsPath) + "Tile_10.png";
			br.fill_opacity = 1.0f;
			br.outline_opacity = 0.0f;

			// To ena tile meta to allo
			for (int i = 0; i < length; i++)
			{
				graphics::drawRect(m_pos_x + i * m_width, m_pos_y, m_width, m_height, br);
			}
		}
};