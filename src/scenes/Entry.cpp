#include "scenes/Entry.h"
#include <odin/graphics/Renderer.hpp>
#include <iostream>


bool Entry::onEvent(const odin::Event& ev) 
{
	switch (ev.type)
	{
	case odin::Event::Type::WindowClosed:
		requestClear();
		return false;
		
	case odin::Event::Type::KeyPressed:
		std::cout << 'x';
		return false;
	}
	return false;
}


bool Entry::update(odin::Time dt)
{

	return false;
}


bool Entry::draw()
{
	odin::Renderer::setClearColor({ 144, 255, 255, 255 });
	return false;
}