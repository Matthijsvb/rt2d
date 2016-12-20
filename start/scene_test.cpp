/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>

#include "scene_test.h"
#include "player.h"

Scene_Test::Scene_Test() : Scene()
{
	// start the timer.
	t.start();
	
	//Create the level
	createLevel();
}

Scene_Test::~Scene_Test()
{
	// deconstruct and delete the Tree
	//this->removeChild(myentity);
	this->removeChild(player1);
	this->removeChild(player2);
	this->removeChild(scene_test_Background);

	// delete myentity from the heap (there was a 'new' in the constructor)
	//delete myentity;
	delete player1;
	delete player2;
	delete scene_test_Background;
}

void Scene_Test::createLevel() {

	//Create the players
	player1 = new player();
	player1->addSprite("assets/sprites/characters/character1.tga");
	player1->position.y = 200.0f;

	player2 = new player();
	player2->addSprite("assets/sprites/characters/character2.tga");
	player2->position.y = 250.0f;

	this->addChild(player1);
	this->addChild(player2);

	//Create the background
	scene_test_Background = new MyEntity();
	scene_test_Background->addSprite("assets/tiles/forrest/forrest_Background.tga");
	scene_test_Background->position.x = 683;
	scene_test_Background->position.y = 300;
	scene_test_Background->scale.x = 1.333;
	this->addChild(scene_test_Background);

	//Create the top platforms
	scene_test_platform_LT1 = new MyEntity();
	scene_test_platform_LT1->addSprite("assets/tiles/forrest/forrest_Platform_Top.tga");
	scene_test_platform_LT1->position.y = 1200;
	scene_test_platform_LT1->position.x = 1800;
	this->addChild(scene_test_platform_LT1);
}

void Scene_Test::update(float deltaTime)
{
	player1->updateGravity();
	player2->updateGravity();
	// ###############################################################
	// Escape key stops the Scene
	// ###############################################################
	if (input()->getKeyUp( GLFW_KEY_ESCAPE )) {
		this->stop();
	}
	// ###############################################################
	// Left key moves player1 up
	// ###############################################################
	if (input()->getKey(GLFW_KEY_W)/* && !playerTest->isJumping*/) {
		player1->position -= Point2(0, player1->playerSpeed) * deltaTime;
		//playerTest->isJumping = true;
	}
	// ###############################################################
	// Left key moves player2 up
	// ###############################################################
	if (input()->getKey(GLFW_KEY_UP)/* && !playerTest->isJumping*/) {
		player2->position -= Point2(0, player2->playerSpeed) * deltaTime;
		//playerTest->isJumping = true;
	}
	// ###############################################################
	// Right key moves player1 to the right
	// ###############################################################
	if (input()->getKey(GLFW_KEY_D)) {
		player1->position += Point2(player1->playerSpeed, 0) * deltaTime;
	}
	// ###############################################################
	// Right key moves player2 to the right
	// ###############################################################
	if (input()->getKey(GLFW_KEY_RIGHT)) {
		player2->position += Point2(player2->playerSpeed, 0) * deltaTime;
	}
	// ###############################################################
	// Spacebar moves player1 to the left
	// ###############################################################
	if (input()->getKey(GLFW_KEY_A)) {
		player1->position -= Point2(player1->playerSpeed, 0) * deltaTime;
	}
	// ###############################################################
	// Spacebar moves player2to the left
	// ###############################################################
	if (input()->getKey(GLFW_KEY_LEFT)) {
		player2->position -= Point2(player2->playerSpeed, 0) * deltaTime;
	}

	// ###############################################################
	// Spacebar moves player1 shoot
	// ###############################################################
	if (input()->getKey(GLFW_KEY_SPACE)) {
		//SHOOT
	}
	// ###############################################################
	// Spacebar moves player2 shoot
	// ###############################################################
	if (input()->getKey(GLFW_KEY_RIGHT_CONTROL)) {
		//SHOOT
	}

	if (player1->gravUpdate) {
		player1->grav += 1 * deltaTime;
	}
	if (player2->gravUpdate) {
		player2->grav += 1 * deltaTime;
	}

}
