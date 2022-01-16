#include "Component.h"
#include "Actor.h"

Component::Component(Actor* ownerP, int updateOrderP):
	owner(*ownerP),
	updateOrder(updateOrderP)
{
	owner.addComponent(this);	//add itself(component) to the actor during construction
}

Component::~Component()
{
	owner.removeComponent(this);	//remoe itself(component) to the actor during destruction
}

void Component::processInput(const Uint8* keyState)
{
}

void Component::update(float dt)
{

}