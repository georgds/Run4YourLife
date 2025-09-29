#pragma once

#include <iostream>
#include <vector>
#include "GameObject.h"
#include "configuration.h"
#include "Girl.h"
#include "Tile.h"
#include "Enemy.h"
#include "Gate.h"
#include "Heart.h"

using namespace std;

class GameState
{
private:

	vector< class GameObject* > myObjects;

public:

	int score;
	int lifes;
	Girl* myGirl;
	bool gameStarted;
	bool guideDisplayed;

	GameState()
	{
		// arxikes times gia score kai tin zwi
		score = 0;
		lifes = 3;
		gameStarted = false;
		guideDisplayed = false;

		

		// Vazei 25 plakes se kathe level
		for (int i = 0; i < 32; i++)
		{
			myObjects.push_back(new Tile(this, "Tile", i * 30, 200, 30, 30, 1));
			myObjects.push_back(new Tile(this, "Tile", i * 30, 300, 30, 30, 1));
			myObjects.push_back(new Tile(this, "Tile", i * 30, 400, 30, 30, 1));
			myObjects.push_back(new Tile(this, "Tile", i * 30, CanvasHeight - 15, 30, 30, 1));
		}

		// Vazei 5 kardies
		for (int i = 1; i <= 5; i++)
		{
			myObjects.push_back(new Heart(this, "Heart", 200+ i * 100, 150, 30, 30));
			myObjects.push_back(new Heart(this, "Heart", i * 90, 250, 30, 30));
			myObjects.push_back(new Heart(this, "Heart", 200+i * 110, 350, 30, 30));
			myObjects.push_back(new Heart(this, "Heart", i * 120, 450, 30, 30));
		}
		
		// Vazei 4 portes stis akres
		myObjects.push_back(new Gate(this, "Gate", 20, 160, 80, 50));
		myObjects.push_back(new Gate(this, "Gate", 20, 360, 80, 50));
		myObjects.push_back(new Gate(this, "Gate", CanvasWidth - 20, 260, 80, 50));
		myObjects.push_back(new Gate(this, "Gate", CanvasWidth - 20, 445, 80, 50));
		



		myObjects.push_back(new Enemy(this, "Enemy1", 300, CanvasHeight - 100, 50, 50));
		myObjects.push_back(new Enemy(this, "Enemy2", 600, CanvasHeight - 200, 50, 50));
		myObjects.push_back(new Enemy(this, "Enemy3", 400, CanvasHeight - 300, 50, 50));
		myObjects.push_back(new Enemy(this, "Enemy4", 200, CanvasHeight - 400, 50, 50));
		myObjects.push_back(new Enemy(this, "Enemy5", 500, CanvasHeight - 250, 50, 50));

		myGirl = new Girl(this, "Lilly", 10, CanvasHeight - 58, 60, 60);
		myObjects.push_back(myGirl);
	}

	void draw()						// Zwgrafizei ola ta antikeimena
	{
		// Zwgrafizei to background
		graphics::Brush br;
		br.fill_opacity = 0.7f;
		br.outline_opacity = 0.0f;
		br.texture = string(AssetsPath) + "background.png";
		graphics::drawRect(CanvasWidth / 2.0f, CanvasHeight / 2.0f, CanvasWidth, CanvasHeight, br);

		// oso exei akoma zwh ginetai draw
		if (lifes > 0)
		{
			// An nikisei to paixnidi
			if (score == 20) {
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;
				graphics::drawText(CanvasWidth / 2.0f - 130, CanvasHeight / 2.0f, 35, "You won", br);
				
				return;
			}


			// Emfanizei tin arxiki othoni
			if (!gameStarted && !guideDisplayed)
			{
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f, 35, "Press S to start", br);
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f + 50, 35, "Press H for help", br);
				return;
			}
			
			if (guideDisplayed) {
				br.fill_color[0] = 1.0f;
				br.fill_color[1] = 1.0f;
				br.fill_color[2] = 1.0f;
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f, 35, "Press S to start", br);
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f + 50, 35, "Press H for help", br);
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f + 100, 35, "Press Left arrow to move left", br);
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f + 150, 35, "Press Right arrow to move right", br);
				graphics::drawText(CanvasWidth / 2.0f - 180, CanvasHeight / 2.0f + 200, 35, "Press Space to use gate", br);
				return;
			}


			// kathe antikeimeno zwgrafizetai mono an einai energo
			for (auto current_object : myObjects)
			{
				if (current_object->isActive())
				{
					current_object->draw();
				}
			}
		}
		else
		{
			br.fill_color[0] = 1.0f;
			br.fill_color[1] = 1.0f;
			br.fill_color[2] = 1.0f;
			graphics::drawText(CanvasWidth / 2.0f - 130, CanvasHeight / 2.0f, 35, "Game Over", br);
			return;
		}


		// zografizei to score kai tis zwes
		drawScoreAndLifes();
	}

	void drawScoreAndLifes()				// Zwgrafizei to score
	{
		graphics::Brush br;
		br.fill_opacity = 1.0f;
		br.outline_opacity = 0.0f;
		br.fill_color[0] = 1.0f;
		br.fill_color[1] = 1.0f;
		br.fill_color[2] = 1.0f;

		// keimeno pou tha emfanistei
		string status = "Lifes " + to_string(lifes) + "      Score " + to_string(score);
		graphics::drawText(50, 50, 35, status, br);
	}

	void update(float t) {
		
		// An den exei xekinisei akoma probalei to start screen
		if (gameStarted != true) {
			if (graphics::getKeyState(graphics::SCANCODE_S)) {
				gameStarted = true;
				guideDisplayed = false;
				graphics::playMusic(string(AssetsPath) + "Run_To_The_Hills_classic.mp3", 0.5f, true, 3000);
			}
			if (graphics::getKeyState(graphics::SCANCODE_H)) {
				guideDisplayed = true;
			}

			return;
		}

		for (auto obj : myObjects)
		{
			if (obj->isActive())
			{
				obj->update(t);
			}
		}

		// KOitazei gia sigrouseis
		for (auto obj : myObjects)
		{

			// An akoumpisei exthro
			if (dynamic_cast<Enemy*>(obj) != nullptr && obj->isActive() && myGirl->intersect(*obj)) {

				lifes--;
				obj->setActive(false);
				graphics::playSound(string(AssetsPath) + "hit.wav", 0.5f, false);
				if (lifes == 0) {
					graphics::playMusic(string(AssetsPath) + "Run_To_The_Hills_end.mp3", 0.5f, true, 3000);
				}
			}

			// An akoumpisei se kardia
			if (dynamic_cast<Heart*>(obj) != nullptr && obj->isActive() && myGirl->intersect(*obj)) {
				score++;
				obj->setActive(false);
				graphics::playSound(string(AssetsPath) + "hit.wav", 0.5f, false);
				if (score == 20) {
					graphics::playMusic(string(AssetsPath) + "Run_To_The_Hills_end.mp3", 0.5f, true, 3000);
				}
			}

			// An akoumpisei se porta kai patisei Space metaferetai se mia alli porta tyxaia
			if (dynamic_cast<Gate*>(obj) != nullptr && obj->isActive() && myGirl->intersect(*obj) && graphics::getKeyState(graphics::SCANCODE_SPACE)) {
				
				// Psaxnei gia mia alli tyxaia porta
				bool found = false;

				// Oso den vrei tyxaia porta
				while (!found) {
					for (auto obj2 : myObjects)
					{
						if (dynamic_cast<Gate*>(obj2) != nullptr && obj2->isActive() && obj2 != obj) {
							if (rand() % 100 < 25) {
								myGirl->m_pos_x = obj2->m_pos_x;
								myGirl->m_pos_y = obj2->m_pos_y;
								found = true;
								return;
							}
						}
					}
				}
			}	

		}
	}


	~GameState() {

		// diagrafei ola ta antikeimena
		for (auto obj : myObjects)
		{
			delete obj;
		}
	}
};

