#include <iostream>

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Player.h"
#include "Input/InputSystem.h"
#include <thread>

using namespace std;

int main(int argc, char* argv[]) {

    kiko::seedRandom((unsigned int)time(nullptr));
    kiko::setFilePath("assets");

    kiko::g_renderer.Initialize();
    kiko::g_renderer.CreateWindow("CSC195", 800, 600);

    kiko::g_inputSystem.Initialize();

    Player player{ 150, kiko::DegToRad(270.0f), { {400, 300}, 0, 3}, {"ship.txt"} };

    bool quit = false;
    while (!quit) {

        kiko::g_time.Tick();

        kiko::g_inputSystem.Update();
        if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) quit = true;

        player.Update(kiko::g_time.GetDeltaTime());

        ///////

        kiko::g_renderer.SetColor(0, 0, 0, 0);
        kiko::g_renderer.BeginFrame();

        kiko::g_renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
        player.Draw(kiko::g_renderer);

        kiko::g_renderer.EndFrame();

    }

    return 0;
}