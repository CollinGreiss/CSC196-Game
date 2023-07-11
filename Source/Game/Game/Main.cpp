#include <iostream>

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include <thread>

using namespace std;

class Star {

public:

    Star(const kiko::Vector2& pos, const kiko::Vector2& vel) : m_pos{ pos }, m_vel{ vel } {}
    void Update(int width, int height) { 

        m_vel.y += kiko::randomf(-20, 20);

        m_pos += m_vel * kiko::g_time.GetDeltaTime();

        if (m_pos.x > width)
            m_pos.x = 0;
        if (m_pos.x < 0)
            m_pos.x = width;
        if (m_pos.y > height)
            m_pos.y = 0;
        if (m_pos.y < 0)
            m_pos.y = height;
    }

    void Draw(kiko::Renderer& renderer) {

        renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
        renderer.DrawPoint(m_pos);

    }

public:
    
    kiko::Vector2 m_pos;
    kiko::Vector2 m_vel;

};

int main(int argc, char* argv[]) {

    kiko::seedRandom((unsigned int)time(nullptr));
    kiko::setFilePath("assets");

    kiko::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("CSC195", 800, 600);

    kiko::InputSystem inputSystem;
    inputSystem.Initialize();

    kiko::vec2 position{400, 300};
    float speed =  150;

    vector<Star> stars;
    kiko::Model model;
    model.Load("ship.txt");

    bool quit = false;
    while (!quit) {

        kiko::g_time.Tick();

#pragma region Inputs

        inputSystem.Update();

        if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) quit = true;

        kiko::vec2 direction;
        if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) direction.y = -1;
        if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) direction.y = 1;
        if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) direction.x = -1;
        if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) direction.x = 1;

        position += direction * speed * kiko::g_time.GetDeltaTime();

        if (inputSystem.GetMouseButtonDown(0))
            stars.push_back(Star(inputSystem.GetMousePosition(), { kiko::randomf(100, 200), 0.0f }));

#pragma endregion

        renderer.SetColor(0, 0, 0, 0);
        renderer.BeginFrame();

        renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
        model.Draw(renderer, position, 1);

        for (auto& star : stars) {

            star.Update(renderer.GetWidth(), renderer.GetHeight());
            star.Draw(renderer);

        }

        renderer.EndFrame();

    }

    return 0;
}