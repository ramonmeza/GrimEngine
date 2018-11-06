#include "InputManager.hpp"

InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::bind(std::string name, sf::Keyboard::Key key, std::function<void(void)> action)
{
	std::pair<sf::Keyboard::Key, std::function<void(void)>> value = std::make_pair(key, action);
	_bindings[name] = value;
}

bool InputManager::unbind(std::string name)
{
	if (_bindings.find(name) == _bindings.end())
		return false;

	_bindings.erase(name);
	return true;
}

void InputManager::processEvents()
{
	for (auto &itr : _bindings)
	{
		if (sf::Keyboard::isKeyPressed(itr.second.first))
			itr.second.second();
	}
}