#pragma once
#include "stdafx.h"
#include "GravBody.h"
#include "IDrawable.h"
#include "SlotMap.h"
#include "ISlotItem.h"

class GameObject : public GravBody, public virtual IDrawable, public virtual ISlotItem {
public:

	GameObject(sf::Vector2f position, sf::Vector2f initialDelta, float mass, sf::Sprite& sprite);
	virtual void draw(sf::RenderWindow& rw);
	virtual void updateSprite();
	virtual bool impactBy(float damage, GameObject* other);
	virtual void increaseSize(GameObject* other);
	virtual float getDamage();
	void setId(SLOTMAP_ID id);
	void setMass(float mass);
	SLOTMAP_ID getId();
	float getMass();
	virtual float getRadius();
	sf::FloatRect getBound();
	void addTrailPoint();
	std::list<sf::Vector2f> * getTrail();

	static const unsigned TRAIL_LENGTH = 40; //must be even since there are 2 verties in a line
protected:
	sf::Sprite _sprite;
	SLOTMAP_ID _id;
	std::list<sf::Vector2f> _trail;

private:
	sf::Vector2f _lastTrailPoint;
	bool _addTrailLine;
};

/*
bullet->planet  bullet destroyed; spawn particle effects
bullet->bullet	bullet destroyed; spawn particle effects
bullet->ship	bullet destroyed; spawn particle effects

planet->bullet	if planet is small enough destory planet or break into peices
planet->planet	obsorb into larger planet
planet->ship	if planet is small enough destory planet or break into peices

ship->bullet	decrease health depending on bullet type
ship->planet	decrease health depending on mass
ship->ship		decrease health by fixed amound; more speed more damage?
*/


/*
if (colliding (object1, object2)){
	object1.impact(object2.getDamge(), object2);
	object2.impact(object1.getDamge(), object2);
}

Planet::implact(...) {
	if other.mass > this.mass
		send planet implact message to other object to:
			increase size
		destroy self (return true)

	else if  other.mass < this.mass
		change delta depending on mass and direction of other object

	else (other.mass == this.mass)
		return true for now
		

}

Ship::implact(...) {
	reduce health by damage amount
	change delta depending on mass and direction of other object
	
	if health is zero 
		game over
}

Bullet::implact(...) {
	spawn particles
	destroy self (return true)
}
*/