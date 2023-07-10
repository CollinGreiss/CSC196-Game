#include <iostream>

#include "Core/Core.h"
#include "Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"

using namespace std;

class Star {

public:

    Star(const kiko::Vector2& pos, const kiko::Vector2& vel) : m_pos{ pos }, m_vel{ vel } {}
    void Update(int width, int height) { 
        m_pos += m_vel; 

        if (m_pos.x > width)
            m_pos.x = 0;
        if (m_pos.x < 0)
            m_pos.x = width;
        if (m_pos.y > height)
            m_pos.y = 0;
        if (m_pos.y < 0)
            m_pos.y = height;
    }

public:
    
    kiko::Vector2 m_pos;
    kiko::Vector2 m_vel;

};

int main(int argc, char* argv[]) {

    kiko::seedRandom((unsigned int)time(nullptr));

    kiko::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("CSC195", 800, 600);

    kiko::InputSystem inputSystem;
    inputSystem.Initialize();

    std::vector<kiko::vec2> points{};

    vector<Star> stars;
    kiko::Model model;

    bool clicked = false;
    bool draw = false;

    bool quit = false;
    while (!quit) {

        inputSystem.Update();
        if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) {

            quit = true;
            
        }
        if (inputSystem.GetKeyDown(SDL_SCANCODE_RETURN)) {

            if (!draw) {

                model = kiko::Model(points);
                draw = true;

            }

        }

        if (inputSystem.GetMouseButtonDown(0)) {

            if (!clicked) {

                points.push_back({ inputSystem.GetMousePosition().x, inputSystem.GetMousePosition().y });
                stars.push_back(Star({ inputSystem.GetMousePosition().x, inputSystem.GetMousePosition().y }, { 0, 0 }));

            }

            clicked = true;

        } else {
        
            clicked = false;
        
        }

        renderer.SetColor(0, 0, 0, 0);
        renderer.BeginFrame();

        if (draw) {
            renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
            model.Draw(renderer, { 0 , 0 }, 1);
        }

        kiko::Vector2 vel(1.0f, 0.3f);

        for (auto& star : stars) {

            star.Update(renderer.GetWidth(), renderer.GetHeight());

            renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
            renderer.DrawPoint(star.m_pos.x, star.m_pos.y);

        }

        renderer.EndFrame();

    }

    return 0;
}