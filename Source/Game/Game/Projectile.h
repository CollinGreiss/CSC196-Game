#pragma once
#include "Framework/Actor.h"
#include "Audio/AudioSystem.h"

class Projectile : public kiko::Actor {

public:

	Projectile(float speed, const kiko::Transform& transform, const kiko::Model& model) :
		Actor{ transform, model },
		m_speed{ speed }
	{ kiko::g_audioSystem.PlayOneShot("laser"); };

	void Update(float dt) override;

private:

	float m_speed = 0;

};

