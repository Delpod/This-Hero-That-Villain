#include "GameObject.h"
#include "Game.h"
#include <iostream>

GameObject::GameObject(sf::Texture &texture, sf::IntRect coords, bool collidable, sf::IntRect collisionRect, float scale, bool loopTexture) {
	load(texture, coords, collidable, collisionRect, scale, loopTexture);
}

void GameObject::load(sf::Texture &texture, sf::IntRect coords, bool collidable, sf::IntRect collisionRect, float scale, bool loopTexture) {
	m_scale = scale;
	m_bCollidable = collidable;
	m_pBody = nullptr;
	if(collisionRect == sf::IntRect(0, 0, 0, 0))
		collisionRect = sf::IntRect(0, 0, coords.width, coords.height);
		
	m_sprite.setTexture(texture);
	
	texture.setRepeated(loopTexture);
	
	m_sprite.setTextureRect(sf::IntRect(0, 0, coords.width, coords.height));
	
	if(m_bCollidable)
		m_sprite.setOrigin((float)collisionRect.left + (float)collisionRect.width / 2.0f, (float)collisionRect.top + (float)collisionRect.height / 2.0f);
	else
		m_sprite.setOrigin((float)coords.width / 2.0f, (float)coords.height / 2.0f);
		
	m_sprite.setScale(scale, scale);
	m_sprite.setPosition(coords.left, coords.top);
	
	if(m_bCollidable) {
		m_bodyDef.position = b2Vec2((float)coords.left / scale / 10.0f, (float)coords.top / scale / 10.0f);

		m_pBody = Game::Inst()->getWorld()->CreateBody(&m_bodyDef);
		
		b2PolygonShape box;
		box.SetAsBox((float)collisionRect.width / 20.0f, (float)collisionRect.height / 20.0f);
		m_pBody->CreateFixture(&box, 0.0f);
	}
}

void GameObject::draw() {
	Game::Inst()->getWindow()->draw(m_sprite);
}

 GameObject::~GameObject() {
	if(m_bCollidable) {
		Game::Inst()->getWorld()->DestroyBody(m_pBody);
		m_pBody = nullptr;
	}
}