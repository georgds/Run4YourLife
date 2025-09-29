#pragma once
#include <graphics.h>
#include "GameState.h"
#include "Box.h"
#include "configuration.h"

class GameObject : public Box
{
	static int m_next_id;
protected:
	class GameState* m_state;
	std::string m_name;
	int m_id = 0;
	bool m_active = true;
	graphics::Brush br;


public:
	GameObject(GameState* gs, const std::string& name, int x, int y, int width, int height)
		:Box(x, y, width, height)
	{
		// arxikes times sta pedia toy GameObject
		this->m_active = true;
		br.outline_opacity = 0.0f;          // adiafaneia perigrammatos 0
		br.fill_opacity = 1.0f;             // adiafaneia xrwmatos 100
	}

	virtual void update(float dt) {}
	virtual void init() {}
	virtual void draw() {}
	virtual ~GameObject() {}
	bool isActive() { return m_active; }
	void setActive(bool a) { m_active = a; }
};

