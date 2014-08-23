#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

class GameObject {
public:
	GameObject() {}
	GameObject(sf::Texture &texture, sf::IntRect coords, bool collidable = true, sf::IntRect collisionRect = sf::IntRect(0, 0, 0, 0), float scale = 5.0f, bool loopTexture = false);
	virtual void load(sf::Texture &texture, sf::IntRect coords, bool collidable = true, sf::IntRect collisionRect = sf::IntRect(0, 0, 0, 0), float scale = 5.0f, bool loopTexture = false);
	virtual void draw();
	virtual void update() {}
	virtual void handleInput() {}
	sf::Sprite* getSprite() { return &m_sprite; }
	b2Body* getBody() { return m_pBody; }
	virtual ~GameObject();
protected:
	sf::Sprite m_sprite;
	b2BodyDef m_bodyDef;
	b2Body* m_pBody;
	float m_scale;
	bool m_bCollidable;
};

#endif // GAMEOBJECT_H