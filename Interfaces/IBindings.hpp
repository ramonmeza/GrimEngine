/*!

	\ingroup Engine

	\class IBindings
	\brief Interface to the InputManager class

	This acts as an interface to the InputManager class. 
	Instead of including an InputManager object into each 
	class you want bindings for, simply inherit from this
	class and call the necessary functions to bind your 
	actions to the desired key. Your derived class MUST
	have a processEvents() function and must call 
	IBindings::processEvents() in it to work. You
	must also implement SetDefaultBindings().

*/

#ifndef IBINDINGS_HPP
#define IBINDINGS_HPP
#pragma once

#include "../InputManager.hpp"

class IBindings
{
public:
	/*!
		\fn void SetDefaultBindings()
		\brief Defines the default key bindings
	*/
	virtual void SetDefaultBindings() = 0;

	/*!
		\fn void processEvents()
		\brief Checks to see if any binding key has been pressed and performs the related action
	*/
	virtual void processEvents()
	{
		_bindings.processEvents();
	}

	/*!
		\fn void bind(std::string name, sf::Keyboard::Key key, std::function<void(void)> action)
		\brief Binds a key to an action and is accessed by a given name
		\param name Specifier for the binding
		\param key Key to be bound
		\param action Callback function to be executed when bound key is pressed
	*/
	void bind(std::string name, sf::Keyboard::Key key, std::function<void(void)> action)
	{
		_bindings.bind(name, key, action);
	}

	/*!
		\fn bool unbind(std::string name)
		\brief Unbinds a certain action from its action
		\param name Binding name to be unbound
	*/
	bool unbind(std::string name)
	{
		_bindings.unbind(name);
	}

private:
	/*!
		\property InputManager _inputManager
		\brief Keeps track of key bindings
	*/
	InputManager _bindings;
};

#endif