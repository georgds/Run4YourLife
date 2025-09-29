#include <graphics.h>
#include "GameState.h"
#include "configuration.h"
#include <time.h>

void update(float ms)
{
    GameState* the_game = (GameState*)graphics::getUserData();
    the_game->update(ms);
}

void draw()
{
    GameState* the_game = (GameState*)graphics::getUserData();
    the_game->draw();
}


int main()
{
    // tyxaia genitria arithmwn
    srand(time(0));

    // Neo Game gia na to dwsoume stin SGG
    GameState* the_game = new GameState();

    // Platos/ypsos parathirou
    graphics::createWindow(WindowsWidth, WindowsHeight, "Run 4 Your Life");
    graphics::setUserData(the_game);

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    // Platos/ypsos kamba
    graphics::setCanvasSize(CanvasWidth, CanvasHeight);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::Brush br;
    br.fill_color[0] = 0.55f;
    br.fill_color[1] = 0.70f;
    br.fill_color[2] = 0.91f;
    graphics::setWindowBackground(br);

    graphics::playMusic(string(AssetsPath) + "Run_To_The_Hills_menu.mp3", 0.5f, true, 3000);
    graphics::setFont(string(AssetsPath)+"ShortBaby-Mg2w.ttf");

    graphics::startMessageLoop();

    return 0;
}
