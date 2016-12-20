/**
* Copyright 2016/2017 Mathijs van Bunnik <matthijsvanbunnik1997@gmail.com>
*
* @file player.h
*
* The following document defines code for the player(s) in Beat your friend
*/
#ifndef PLAYER_H
#define PLAYER_H

#include <rt2d/entity.h>

class player : public Entity
{
public:
	/// @brief Constructor
	player();
	/// @brief Destructor
	virtual ~player();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	float playerSpeed;
	float grav;
	float floorLocation;

	float playerHealth;

	bool isJumping;
	bool gravUpdate;

	void updateGravity();

private:
	/* add your private declarations */
	
};

#endif /* PLAYER_H */