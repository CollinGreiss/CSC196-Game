#pragma once
#include <cmath>
#include <sstream>

namespace kiko {

	class Vector2 {

	public:

		float x, y;

	public:

		Vector2() : x{ 0 }, y{ 0 } {}
		Vector2(float v) : x { v }, y{ v } {}
		Vector2(float x, float y) : x{ x }, y{ y } {}
		Vector2(int x, int y) : x{ (float) x }, y{ (float) y } {}

		Vector2 operator + (const Vector2& v) const { return Vector2(x + v.x, y + v.y); }
		Vector2 operator - (const Vector2& v) const { return Vector2(x - v.x, y - v.y); }
		Vector2 operator * (const Vector2& v) const { return Vector2(x * v.x, y * v.y); }
		Vector2 operator / (const Vector2& v) const { return Vector2(x / v.x, y / v.y); }

		Vector2 operator + (const float s) const { return Vector2(x + s, y + s); }
		Vector2 operator - (const float s) const { return Vector2(x - s, y - s); }
		Vector2 operator * (const float s) const { return Vector2(x * s, y * s); }
		Vector2 operator / (const float s) const { return Vector2(x / s, y / s); }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x += v.x; y += v.y; return *this; }

		Vector2& operator += (const float s) { x += s; y += s; return *this; }
		Vector2& operator -= (const float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (const float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (const float s) { x /= s; y /= s; return *this; }

		float LengthSqr() { return (x * x) + (y * y); }
		float Length() { return std::sqrt(LengthSqr()); }

		Vector2 Normalized() { return *this / Length(); }
		void Normalize() { *this /= Length(); }

	};

	inline std::istream& operator >> (std::istream& stream, Vector2& v) {

		std::string line;
		std::getline(stream, line);

		return stream;

	}

	using vec2 = Vector2;

}