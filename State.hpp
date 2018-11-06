/*!

	\ingroup Engine

	\class State
	\brief Base class for any screen in the game, including levels

	State is a base class for any screen that has input, is updatable,
	or displayed to the player. You must inherit from this class and 
	add it to the StateManager in your Game derived class in order to
	access it.

*/

#ifndef STATE_HPP
#define STATE_HPP
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

class State : public sf::Drawable
{
public:
	/*!
		\fn State()
		\brief Default constructor
	*/
	State() {}

	/*!
		\fn ~State()
		\brief Virtual destructor
	*/
	virtual ~State() {};
	
	/*!
		\fn void processEvents()
		\brief Process input events for this specific state
	*/
	virtual void processEvents() = 0;
	
	/*!
		\fn void update(sf::Time deltaTime)
		\brief Updates the logic for this specific state
		\param deltaTime Time since last update was called
	*/
	virtual void update(sf::Time deltaTime) = 0;

protected:
	/*!
		\fn void draw(sf::RenderTarget& target, sf::RenderStates states) const
		\brief Overrides draw function to draw the current state to the target
		\param target Render target to draw to
		\param states Current render states
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

#endif