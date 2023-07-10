#include "Model.h"

namespace kiko{

	void Model::Draw(Renderer& renderer, const vec2& position, float scale) {

		vec2 p1;
		vec2 p2;

		for (int i = 0; i < m_points.size() - 1; i++) {

			p1 = m_points[i] * scale + position;
			p2 = m_points[i + 1] * scale + position;

			renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);

		}

		p1 = p2;
		p2 = m_points[0] * scale + position;
		renderer.DrawLine(p1.x, p1.y, p2.x, p2.y);

	}

}
