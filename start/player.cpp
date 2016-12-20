/*
The following class defines the player(s). It adds a playable character on to the screen.
Functions of the player:
Moving (Left/ Right/ Jumping)
Picking up items
Shooting
Health (Damaging, healing, health)
*/

#include "player.h"

player::player() : Entity()
{
// ###############################################################
// Player variables
// ###############################################################
	//Movement variables
	playerSpeed = 255.0f;
	isJumping = false;
	grav = 0.0f;
	floorLocation = 550.0f;

	//Shooting variables
	playerHealth = 100.0f;

}

player::~player()
{

}
// ###############################################################
// Update function
// ###############################################################
void player::update(float deltaTime)
{
	/* Rotate
	this->rotation += HALF_PI * deltaTime; // 90 deg/sec
	if (this->rotation > TWO_PI) {
		this->rotation -= TWO_PI;
	}*/
}

void player::updateGravity() {

	this->position.y += grav;
	
	if (this->position.y < floorLocation)
	{
		gravUpdate = true;
	} 
	else {
		grav = 0;
		this->position.y = floorLocation;
		isJumping = false;
	}
}