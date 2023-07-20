#include "Enemy.h"
#include "Player.h"
#include "Projectile.h"
#include "Framework/Scene.h"

void Enemy::Update(float dt) {

    Actor::Update(dt);
    Player* player = m_scene->GetActor<Player>();
    if (player) {

        kiko::vec2 direction = player->m_transform.position - m_transform.position;
        m_transform.rotation = direction.Angle() + kiko::HalfPi;

    }

    kiko::vec2 forward = kiko::vec2{ 0, -1 }.Rotate(m_transform.rotation);
    m_transform.position += forward * m_speed * kiko::g_time.GetDeltaTime();
    m_transform.position.x = kiko::Wrap(m_transform.position.x, kiko::g_renderer.GetWidth());
    m_transform.position.y = kiko::Wrap(m_transform.position.y, kiko::g_renderer.GetHeight());

    //m_firetimer -= dt;
    if (m_firetimer <= 0) {

        m_firetimer = m_firerate;
        std::unique_ptr<Projectile> projectile = std::make_unique<Projectile>(400.0f, kiko::Transform{ m_transform.position, m_transform.rotation, 1 }, m_model, "Enemy");
        m_scene->Add(std::move(projectile));

    }

}

void Enemy::OnCollision(Actor* other)
{
}
