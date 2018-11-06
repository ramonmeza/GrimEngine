#include "StateManager.hpp"

StateManager::StateManager()
{

}

StateManager::~StateManager()
{
	// Safely pop and destroy left over states
	while (!_states.empty())
	{
		PopState();
	}
}

State* StateManager::CurrentState()
{
	return _states.top();
}

void StateManager::PushState(State* state)
{
	try
	{
		// Push a new state
		_states.push(state);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: StateManager::PushState(): " << e.what() << std::endl;
	}
}

void StateManager::PopState()
{
	if (!_states.empty())
	{
		try
		{
			// Remove top element and delete it safely
			State* temp = _states.top();
			_states.pop();
			delete temp;
			temp = nullptr;
		}
		catch (std::exception& e)
		{
			std::cout << "Exception: StateManager::PopState(): " << e.what() << std::endl;
		}
	}
}