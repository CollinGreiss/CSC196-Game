#include <iostream>

#include "../../Engine/Core/Random.h"
#include "../../Engine/Core/FileIO.h"
#include "../../Engine/Core/Memory.h"
#include "../../Engine/Core/Time.h"
#include "../../Engine/Renderer/Renderer.h"

using namespace std;

using namespace std;

int main(int argc, char* argv[]) {

    kiko::Renderer renderer;
    renderer.Initialize();
    renderer.CreateWindow("CSC195", 800, 600);

    while (true) {

        renderer.SetColor(0, 0, 0, 0);
        renderer.BeginFrame();

        for (int i = 0; i < 1000; i++) {

            renderer.SetColor(kiko::random(256), kiko::random(256), kiko::random(256), 255);
            renderer.DrawPoint(kiko::random(renderer.GetWidth()), kiko::random(renderer.GetHeight()));

        }
        renderer.EndFrame();

    }

    return 0;
}