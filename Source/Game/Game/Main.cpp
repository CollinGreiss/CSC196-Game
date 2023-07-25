#include <iostream>

#include "Core/Core.h"

#include "Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Renderer/Font.h"
#include "Renderer/Text.h"

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

    shared_ptr<Font> font = make_shared<Font>("ka1.ttf", 24);

    unique_ptr<Text> text = make_unique<Text>(font);
    text->Create(g_renderer, "Health: ##########", Color{ 1, 1, 1, 1 });

    ////////Things

    Scene scene;

    scene.Add(make_unique<Player>( 100.0f, 150.0f, DegToRad(270.0f), Transform{ {400, 300}, 0, 3}, g_modelManager.Get("ship.txt"), "Player"));

    for (int i = 0; i < 1; i++)
        scene.Add(make_unique <Enemy>(
            20.0f,
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
        ));


    ////// Game Loop

    bool quit = false;
    while (!quit) {

        ///// Updates

        g_time.Tick();

        g_audioSystem.Update();

        g_inputSystem.Update();
        if (g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) quit = true;

        scene.Update(g_time.GetDeltaTime());

        Player* player = scene.GetActor<Player>();
        string health = "";
        for (int i = 0; i < 10 * (player->GetHealth() / 100); i++)
            health += "A";
        text->Create(g_renderer, "Health: " + health, Color{ 1, 1, 1, 1 });

        /////// Drawing

        g_renderer.SetColor(0, 0, 0, 0);
        g_renderer.BeginFrame();

        g_renderer.SetColor(255, 255, 255, 255);
        scene.Draw(g_renderer);

        text->Draw(kiko::g_renderer, 10, 10);

        g_renderer.EndFrame();

    }

    return 0;
}