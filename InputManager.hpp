/*!

	\ingroup Engine

	\class InputManager
	\brief Handles input bindings

	The InputManager class handles mapping keys to specific
	actions in the game. It makes it simple to add custom 
	key bindings for actions in-game.

*/

#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP
#pragma once

#include <functional>
#include <unordered_map>
#include <utility>
#include <SFML/Window/Event.hpp>

class InputManager
{
public:
	/*!
		\fn InputManager()
		\brief Default constructor
	*/
	InputManager();

	/*!
		\fn ~InputManager()
		\brief Default destructor
	*/
	~InputManager();

	/*!
		\fn void bind(std::string name, sf::Keyboard::Key key, std::function<void(void)> action)
		\brief Binds a key to an action and is accessed by a given name
		\param name Specifier for the binding
		\param key Key to be bound
		\param action Callback function to be executed when bound key is pressed
	*/
	void bind(std::string name, sf::Keyboard::Key key, std::function<void(void)> action);
	
	/*!
		\fn bool unbind(std::string name)
		\brief Unbinds a certain action from its action
		\param name Binding name to be unbound
	*/
	bool unbind(std::string name);

	/*!
		\fn void processEvents()
		\brief Checks to see if any binding key has been pressed and performs the related action
	*/
	void processEvents();

private:
	/*!
		\var std::unordered_map<std::string, std::pair<sf::Keyboard::Key, std::function<void(void)>>> _bindings
		\brief Map of all action bindings
	*/
	std::unordered_map<std::string, std::pair<sf::Keyboard::Key, std::function<void(void)>>> _bindings;
};

#endif