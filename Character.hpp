/*!

	\ingroup Engine

	\class Character
	\brief Class for generic characters.

	The Character class is a simple class used to add a character to your
	game. It contains fundamental functions for controlling the character
	and displaying them.

*/

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#pragma once

#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include <SFML/Graphics.hpp>

class Character : public sf::Drawable
{
public:
	/*!
		\fn Character(std::string texturePath)
		\brief Construct a character with the given texture path
		\param texturePath Path to the texture
	*/
	Character(std::string texturePath);

	/*!
		\fn ~Character()
		\brief Virtual destructor
	*/
	virtual ~Character();

	// This will target move(float, float) and move(sf::Vector2f)
	/*!
		\fn void setPosition(Args&& ... args)
		\brief Move the object by a given offset
		\param args X, Y offset as two floats or an sf::Vector2f
	*/
	template<typename ... Args>
	void move(Args&& ... args)
	{
		_sprite.move(std::forward<Args>(args)...);
	}

	// This will target setPosition(float, float) and setPosition(sf::Vector2f)
	/*!
		\fn void setPosition(Args&& ... args)
		\brief Set the position of the object
		\param args X, Y coordinates as two floats or an sf::Vector2f
	*/
	template<typename ... Args>
	void setPosition(Args&& ... args)
	{
		_sprite.setPosition(std::forward<Args>(args)...);
	}

	/*!
		\fn const sf::Vector2f& getPosition() const
		\brief Get the position of the object
		\returns Current position
	*/
	const sf::Vector2f& getPosition() const;

	void MoveUp()
	{
		_sprite.move(0, -1);
	}

	void MoveDown()
	{
		_sprite.move(0, 1);
	}

	void MoveLeft()
	{
		_sprite.move(-1, 0);
	}
	void MoveRight()
	{
		_sprite.move(1, 0);
	}

protected:
	/*!
		\fn void draw(sf::RenderTarget& target, sf::RenderStates states) const
		\brief Overrides draw function to draw the current state to the target
		\param target Render target to draw to
		\param states Current render states
	*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
	/*!
		\var sf::Texture texture
		\brief Holds the texture for the character
	*/
	sf::Texture _texture;

	/*!
		\var sf::Sprite sprite
		\brief Sprite for the character
	*/
	sf::Sprite _sprite;
};

#endif