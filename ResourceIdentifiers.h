#ifndef RESOURCEIDENTIFIERS_H
#define RESOURCEIDENTIFIERS_H

namespace Textures
{
	enum class ID
	{
		Eagle,
		Raptor,
		Desert,
	};
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;


#endif // !RESOURCEIDENTIFIERS_H
