#pragma once

#include "Core/Vector2.h"
#include "Renderer.h"
#include <vector>

namespace kiko {

	class Model {


	public:

		Model() = default;
		Model(std::vector<vec2>& points) : m_points{ points } {}

		void Draw(Renderer& renderer, const vec2& position, float scale);

	private:

		std::vector<vec2> m_points;

	};

}