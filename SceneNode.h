#ifndef SCENE_NODE_H
#define SCENE_NODE_H

#include <memory>
#include <vector>

#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable 
{
public:
	typedef std::unique_ptr<SceneNode>	Ptr;

public:
										SceneNode();
	void								attachChild(Ptr child);
	Ptr									detachChild(const SceneNode& node);
	void								update(sf::Time dt);

private:
	virtual void						draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	virtual void						drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	void								drawChildren(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void						updateCurrent(sf::Time dt);
	void								updateChildren(sf::Time dt);

private:
	std::vector<Ptr>					mChildren;
	SceneNode*							mParent;
};

#endif // !SCENE_NODE_H
