#include "Engine.hpp"

Engine::Engine(sf::Vector2i resolution, std::string windowName) :
	_window(sf::VideoMode(resolution.x, resolution.y), windowName)
{

}

Engine::~Engine()
{

}

void Engine::run(int minFPS)
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate;
	sf::Time timePerFrame = sf::seconds(1.0f / minFPS);

	while (_window.isOpen())
	{
		processWindowEvents();
		processEvents();

		timeSinceLastUpdate = clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			update(timePerFrame);
		}

		update(timeSinceLastUpdate);
		render();
	}
}

void Engine::processWindowEvents()
{
	sf::Event event;
	while (_window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape))
		{
			_window.close();
		}
	}
}

void Engine::processEvents()
{
	if (_stateManager.CurrentState())
	{
		_stateManager.CurrentState()->processEvents();
	}
}

void Engine::update(sf::Time deltaTime)
{
	if (_stateManager.CurrentState())
	{
		_stateManager.CurrentState()->update(deltaTime);
	}
}

void Engine::render()
{
	_window.clear();
	if (_stateManager.CurrentState())
	{
		_window.draw(*_stateManager.CurrentState());
	}
	_window.display();
}