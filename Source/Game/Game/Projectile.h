#pragma once
#include "Framework/Actor.h"
#include "Audio/AudioSystem.h"

class Projectile : public kiko::Actor {

public:

	Projectile(float speed, const kiko::Transform& transform, std::shared_ptr<kiko::Model> model, std::string tag) :
		Actor{ transform, model, tag },
		m_speed{ speed }
	{ 
		m_lifespan = 2.0f;
		kiko::g_audioSystem.PlayOneShot("laser");
	};

	void Update(float dt) override;
	void OnCollision(Actor* actor) override;

private:

	float m_speed = 0;

};

