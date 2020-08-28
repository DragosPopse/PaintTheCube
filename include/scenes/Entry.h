#pragma once

#include <odin/core/Scene.hpp>

class Entry :
	public odin::Scene
{
public:
	Entry() = default;

	bool onEvent(const odin::Event& ev) override;
	bool update(odin::Time dt) override;
	bool draw() override;
};