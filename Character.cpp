#include "Character.hpp"

Character::Character(std::string texturePath)
{
	try
	{
		_texture.loadFromFile(texturePath);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: Character::Character(): " << e.what() << std::endl;
	}

	_sprite.setTexture(_texture);
}

Character::~Character()
{

}

const sf::Vector2f& Character::getPosition() const
{
	return _sprite.getPosition();
}

void Character::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(_sprite, states);
}