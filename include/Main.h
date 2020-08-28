#pragma once

#include <odin/core/App.hpp>



class Game :
	public odin::App
{

public:
	Game();

	odin::Scene* createEntryScene() final;
};