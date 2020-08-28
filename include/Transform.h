#pragma once

#include <gmath/mat.hpp>
#include <gmath/vec.hpp>

class Transform
{
	gm::Mat4f m_transform = gm::Mat4f(1.f);

public:
	Transform() = default;


	void setPosition(const gm::Vec3f& position);
	void move(const gm::Vec3f& offset);
	

	void setRotation(float radians, const gm::Vec3f& axis);
	void rotate(float radians, const gm::Vec3f& axis);


	void setScale(const gm::Vec3f& s);
	void scale(const gm::Vec3f& s);
};