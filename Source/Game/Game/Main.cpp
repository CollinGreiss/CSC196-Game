#include <iostream>

#include "Core/Core.h"
#include "Renderer/Renderer.h"

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

    vector<Star> stars;
    for (int i = 0; i < 1000; i++) {
        
        kiko::Vector2 pos(kiko::Vector2(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight())));
        kiko::Vector2 vel(kiko::randomf(1, 4), 0.0f);

        stars.push_back(Star(pos, vel));

    }

    while (true) {

        renderer.SetColor(0, 0, 0, 0);
        renderer.BeginFrame();

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