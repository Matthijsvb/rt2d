/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef SCENE_TEST_H
#define SCENE_TEST_H

#include <rt2d/scene.h>
#include "myentity.h"
#include "player.h"

/// @brief The MyScene class is the Scene implementation.
class Scene_Test : public Scene
{
public:
	/// @brief Constructor
	Scene_Test();
	/// @brief Destructor
	virtual ~Scene_Test();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the rotating square in the middle of the screen
	MyEntity* myentity;
	player* player1;
	player* player2;
	MyEntity* scene_test_Background;
	/// @brief a Timer to rotate the color every n seconds
	Timer t;

	void createLevel();

	//Platforms -Top
	MyEntity* scene_test_platform_TL;
	MyEntity* scene_test_platform_TR;

	//Platforms -Left
	MyEntity* scene_test_platform_LT;
	MyEntity* scene_test_platform_LB;

	//Platforms -Right
	MyEntity* scene_test_platform_RT;
	MyEntity* scene_test_platform_RB;

	//Platforms -Mid



};

#endif /* SCENE00_H */
