#include <iostream>

#include "Core/Core.h"

#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"

#include "Audio/AudioSystem.h"
#include "Input/InputSystem.h"

#include "Framework/Scene.h"
#include "Player.h"
#include "Enemy.h"

#include <thread>

using namespace std;
using namespace kiko;

int main(int argc, char* argv[]) {

    MemoryTracker::Initialize();

    /////Setup

    seedRandom((unsigned int)time(nullptr));
    setFilePath("assets");

    g_renderer.Initialize();
    g_renderer.CreateWindow("CSC195", 800, 600);

    g_audioSystem.Initialize();
    g_audioSystem.AddAudio("laser", "laser.wav");

    g_inputSystem.Initialize();

    ////////Things

    Scene scene;

    //scene.Add(make_unique<Player>( 150.0f, DegToRad(270.0f), Transform{ {400, 300}, 0, 3}, g_modelManager.Get("ship.txt"), "Player"));

    /*for (int i = 0; i < 1; i++)
        scene.Add(make_unique <Enemy>(
            randomf(75, 150),
            DegToRad(270.0f),
            Transform{
                {randomf(g_renderer.GetWidth()), randomf(g_renderer.GetHeight()) },
                randomf(kiko::TwoPi),
                2
            },
            g_modelManager.Get("enemy.txt"),
            randomf(1, 2),
            "Enemy"
        ));*/


    ////// Game Loop

    bool quit = false;
    while (!quit) {

        ///// Updates

        g_time.Tick();

        g_audioSystem.Update();

        g_inputSystem.Update();
        if (g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) quit = true;

        scene.Update(g_time.GetDeltaTime());

        /////// Drawing

        g_renderer.SetColor(0, 0, 0, 0);
        g_renderer.BeginFrame();

        g_renderer.SetColor(255, 255, 255, 255);
        scene.Draw(g_renderer);

        g_renderer.EndFrame();

    }

    return 0;
}