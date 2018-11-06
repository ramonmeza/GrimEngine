/*!

	\ingroup Engine

	\class StateManager
	\brief Acts as a wrapper to std::stack

	StateManager provides an interface to std::stack. It has a stack
	of State objects and is able to delete them safely on destruction.

*/

#ifndef STATEMANAGER_HPP
#define STATEMANAGER_HPP
#pragma once

#include <exception>
#include <iostream>
#include <stack>

#include "State.hpp"

class StateManager
{
public:
	/*!
		\fn StateManager()
		\brief Default constructor
	*/
	StateManager();

	/*!
		\fn ~StateManager()
		\brief Default destructor
	*/
	~StateManager();

	/*!
		\fn State* CurrentState()
		\brief Used to access the current state
		\returns A pointer to the current state
	*/
	State* CurrentState();

	/*!
		\fn void PushState(State* state)
		\brief Adds a State to the stack
		\param state Pointer to the State object to add to the stack
	*/
	void PushState(State* state);

	/*!
		\fn void PopState()
		\brief Removes the State at the top of the stack
	*/
	void PopState();

private:
	/*!
		\property std::stack<State*> _states
		\brief Stack used to keep track of the States
	*/
	std::stack<State*> _states;
};

#endif