#pragma once
#include <SDL_stdinc.h>

class Actor;	// Actor.h will include Component.h

class Component
{
public :
	Component(Actor* ownerP, int updateOrderP = 100);  //Component in a specific actor
	Component() = delete;
	virtual ~Component();
	virtual void processInput(const Uint8* keyState);
	Component(const Component&) = delete;
	Component& operator = (const Component&) = delete;

	int getUpdateOrder() const { return updateOrder; }

	virtual void update(float dt);

protected :
	Actor& owner;
	int updateOrder;	//Order of the component in the actor's upadateComponent method
};