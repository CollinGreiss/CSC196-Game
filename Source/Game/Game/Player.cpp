#include "Player.h"
#include "Input/InputSystem.h"

void Player::Update(float dt) {

    bool sprint = kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_LSHIFT);

    float rotate = 0;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) rotate = -1;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) rotate = 1;
    m_transform.rotation += rotate * m_turnRate * kiko::g_time.GetDeltaTime();

    float thrust = 0;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) thrust = 1;
    if (kiko::g_inputSystem.GetKeyDown(SDL_SCANCODE_S)) thrust = -1;

    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotation);
    m_transform.position += forward * m_speed * thrust * kiko::g_time.GetDeltaTime() * ((sprint) ? 2 : 1);
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_renderer.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_renderer.GetHeight());

}
