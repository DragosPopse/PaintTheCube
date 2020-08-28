#include "Main.h"
#include "scenes/Entry.h"


Game::Game()
{
	odin::AppInfo info;
	info.name = "Cube Painter";
	info.window.title = L"Cube Painter";
	info.window.style = odin::mask(odin::Window::Style::Overlapped);
	info.window.width = 800;
	info.window.height = 800;
	info.graphics.opengl.majorVersion = 3;
	info.graphics.opengl.minorVersion = 3;
	info.fixedTicksPerSecond = 60;
	create(info);
}


odin::Scene* Game::createEntryScene() 
{
	return new Entry();
}


namespace odin
{
	odin::App* createApp()
	{
		return new Game();
	}
}