#include <iostream>

#include "Core/Core.h"

#include "Renderer/Renderer.h"
#include "Renderer/Model.h"

#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"

#include "Player.h"
#include "Enemy.h"

#include <thread>

using namespace std;

int main(int argc, char* argv[]) {

    kiko::seedRandom((unsigned int)time(nullptr));
    kiko::setFilePath("assets");

    kiko::g_renderer.Initialize();
    kiko::g_renderer.CreateWindow("CSC195", 800, 600);

    kiko::AudioSystem audioSystem;
    audioSystem.Initialize();

    audioSystem.AddAudio("laser", "laser.wav");

    kiko::g_inputSystem.Initialize();

    Player player{ 150, kiko::DegToRad(270.0f), { {400, 300}, 0, 3}, {"ship.txt"} };

    std::vector<Enemy> enemies;
    for (int i = 0; i < 1; i++)
        enemies.push_back ({
            150,
            kiko::DegToRad(270.0f),
            kiko::Transform { 
                { kiko::randomf(kiko::g_renderer.GetWidth()), kiko::randomf(kiko::g_renderer.GetHeight()) },
                kiko::randomf(kiko::TwoPi), 
                2 
            },
           { "ship.txt" }
        });

    bool quit = false;
    while (!quit) {

        kiko::g_time.Tick();

        audioSystem.Update();

        kiko::g_inputSystem.Update();
        if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) quit = true;

        if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE)) {

            audioSystem.PlayOneShot("laser");

        }

        player.Update(kiko::g_time.GetDeltaTime());
        for (auto& enemy : enemies)
            enemy.Update(kiko::g_time.GetDeltaTime());

        ///////

        kiko::g_renderer.SetColor(0, 0, 0, 0);
        kiko::g_renderer.BeginFrame();

        kiko::g_renderer.SetColor(255, 255, 255, 255);
        player.Draw(kiko::g_renderer);
        
        kiko::g_renderer.SetColor(255, 0, 0, 255);
        for (auto enemy : enemies)
            enemy.Draw(kiko::g_renderer);

        kiko::g_renderer.EndFrame();

    }

    return 0;
}