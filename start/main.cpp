/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @brief Description of My Awesome Game.
 *
 * @file main.cpp
 *
 * @mainpage My Awesome Game
 *
 * @section intro Introduction
 *
 * Detailed description of My Awesome Game.
 *
 * There's even a second paragraph.
 */
#include <rt2d/core.h>

#include "scene_test.h"

/*
The code below is the default code, provided by RT2D
/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;

	// Scene01
	MyScene* myscene = new MyScene(); // create Scene on the heap
	while(myscene->isRunning()) { // check status of Scene every frame
		core.run(myscene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}

*/

int main(void)
{
	//Initiate core
	Core core;

	//Create a test scene,
	//In the near future more scenes should be created (Start, Character, Lobby, etc.)
	Scene_Test* testScene = new Scene_Test();

	while (testScene->isRunning()) { // check status of Scene every frame
		core.run(testScene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
	}

	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete testScene; // delete Scene and everything in it from the heap to make space for next Scene

	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.

	return 0;
}