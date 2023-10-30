#pragma once
#include "Drawable.h"
#include "Point.h"
#include "player.h"

constexpr float bulletSpeed = 100;

class Bullet : public Drawable
{
	FPoint velocity;
	FPoint worldpoints[2];
	
public:
	Bullet(FPoint velocity,FPoint front,FPoint back) : Drawable((int)std::size(worldpoints), offsetof(Bullet, worldpoints)),
		velocity(velocity),worldpoints{front,back}
	{}

	Bullet(const Player& p):
		Drawable((int)std::size(worldpoints), offsetof(Bullet, worldpoints)),
		velocity(FromAngle(p.rotationAngle,bulletSpeed)+p.velocity),
		worldpoints{p.pos ,p.pos}
	{}

	void Update(float deltatime)
	{
		worldpoints[1] = worldpoints[0];
		worldpoints[0] += velocity * deltatime;
	}
};

