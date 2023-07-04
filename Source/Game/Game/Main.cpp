#include <iostream>

#include "../../Engine/Core/Random.h"
#include "../../Engine/Core/FileIO.h"
#include "../../Engine/Core/Memory.h"
#include "../../Engine/Core/Time.h"
#include "../../Engine/Renderer/Renderer.h"

using namespace std;

using namespace std;

int main() {

    kiko::g_memoryTracker.DisplayInfo();

    int* p = new int;
    kiko::g_memoryTracker.DisplayInfo();

    delete p;
    kiko::g_memoryTracker.DisplayInfo();


    /*auto start = chrono::high_resolution_clock::now();
    
    for (int i = 0; i < 129831; i++) {}
    
    auto end = chrono::high_resolution_clock::now();

    cout << chrono::duration_cast<chrono::nanoseconds>(end - start).count();*/
    /*cout << kiko::getFilePath() << endl;
    kiko::setFilePath("../Assets");
    cout << kiko::getFilePath() << endl << endl;

    size_t size;
    kiko::getFileSize("game.txt", size);
    cout << "Game.txt size: " << size << endl << endl;

    std::string s;
    kiko::readFile("game.txt", s);
    cout << s << endl << endl;

    kiko::seedRandom( (unsigned int) time(nullptr) );
    for (int i = 0; i < 10; i++) {

        cout << kiko::random(5, 20) << endl;

    }*/

}