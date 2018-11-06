/*!

	\ingroup Engine

	\class Engine
	\brief Base class for the game being developed.

	The Game Class is used as a base class for any game
	that you want to make. It controls the state machine,
	window, window events, and updating the current state.
	When you inherit from this class to make your game you
	must define void init().

*/

#ifndef ENGINE_HPP
#define ENGINE_HPP
#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "InputManager.hpp"
#include "StateManager.hpp"

class Engine
{
public:
	/*!
		\fn Engine(sf::Vector2i resolution = sf::Vector2i(800, 600), std::string windowName = "GrimEngine")
		\brief Creates the engine instance
		\param resolution Resolution of the game window
		\param windowName Name of the game window
	*/
	Engine(sf::Vector2i resolution = sf::Vector2i(800, 600), std::string windowName = "GrimEngine");

	/*!
		\fn ~Engine()
		\brief Virtual destructor
	*/
	virtual ~Engine();

	/*!
		\fn void init()
		\brief Used to load the initial state of the game
	*/
	virtual void init() = 0;

	/*!
		\fn void run(int minFPS)
		\brief Runs the game loop.
		\param minFPS Represents the minimum FPS the game should run at
	*/
	void run(int minFPS);

private:
	/*!
		\fn void processWindowEvents()
		\brief Handles window events, such at closing, minimizing, and maximizing
	*/
	void processWindowEvents();

	/*!
		\fn void processEvents()
		\brief Handles events from the current state
	*/
	void processEvents();

	/*!
		\fn void update(sf::Time deltaTime)
		\brief Updates the current state
		\param deltaTime Time since last update was called
	*/
	void update(sf::Time deltaTime);

	/*!
		\fn void render()
		\brief Renders the current state
	*/
	void render();

protected:
	/*!
		\property sf::RenderWindow window
		\brief Stores the main game window object
	*/
	sf::RenderWindow _window;

	/*!
		\property StateManager stateManager
		\brief Controls the state of the game
	*/
	StateManager _stateManager;
};

#endif