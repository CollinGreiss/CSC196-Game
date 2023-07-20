#pragma once

#include "Core/Core.h"
#include "Renderer/Model.h"
#include <memory>

namespace kiko {

	class Actor {

	public:

		Actor() = default;
		Actor(const kiko::Transform& transform, std::shared_ptr<Model>& model, std::string tag) :
			m_transform{ transform },
			m_model{ model },
			m_tag{ tag }
		{}

		virtual void Update(float dt);
		virtual void Draw(kiko::Renderer& renderer);

		virtual void OnCollision(Actor* other) {};

		//float GetRadius() { return m_model.GetRadius() * m_transform.scale; }
		float GetRadius() { return m_model->GetRadius(); }

		class Scene* m_scene = nullptr;
		friend class Scene;

		kiko::Transform m_transform;
		std::string m_tag;

	protected:

		bool m_destroyed = false;
		float m_lifespan = -1.0f;

		std::shared_ptr<Model> m_model;

	};

}