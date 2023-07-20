#include "Projectile.h"
#include "Input/InputSystem.h"
#include <iostream>

void Projectile::Update(float dt) {

    Actor::Update(dt);

    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotation);
    m_transform.position += forward * m_speed * kiko::g_time.GetDeltaTime();
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_renderer.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_renderer.GetHeight());

}

void Projectile::OnCollision(Actor* other) {

    std::cout << other->m_tag << " - " << m_tag << std::endl;

    if (other->m_tag != m_tag)
        m_destroyed = true;

}
