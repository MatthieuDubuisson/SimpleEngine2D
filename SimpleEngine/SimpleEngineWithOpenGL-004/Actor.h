#pragma once
#include <vector>
#include"Vector2.h"
#include <SDL_stdinc.h>
using std::vector;

class Game;		//Game.h will include Actor.h 
class Component;

class Actor
{
public:
	enum class ActorState {		//set different states for an Actor
		Active, Paused, Dead
	};

	Actor();
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator = (const Actor&) = delete;

	//Get and set postion, scale, rotaion of the actor (init)
	Game& getGame() const { return game; }
	const ActorState getState() const { return state; }
	const Vector2 getPosition()const { return position; }
	const float getScale() const { return scale; }
	const float getRotation() const { return rotation; }
	Vector2 getForward() const;

	void setState(ActorState stateP);
	void setPosition(Vector2 positionP);
	void setScale(float scaleP);
	void setRotation(float rotationP);

	// update actor and his components (void)
	void update(float dt);
	void updateComponents(float dt);
	virtual void updateActor(float dt);
	void addComponent(Component* component);
	void removeComponent(Component* component);

	// Input processing
	void processInput(const Uint8* keyState);
	virtual void actorInput(const Uint8* keyState);

private:
	Game& game;
	ActorState state;
	Vector2 position;
	float scale;
	float rotation;		//Rotation in radians

	vector<Component*> components;
};