#include "Player.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

Player::Player(int index, sf::Vector2f position, float scale) {
	sf::Vector2u size = TextureManager::Inst()->getTexture((*Game::Inst()->getPlayerIDs())[index])->getSize();
	load(*TextureManager::Inst()->getTexture((*Game::Inst()->getPlayerIDs())[index]),
	sf::IntRect(position.x, position.y, size.x, size.y),
	false,
	sf::IntRect(0, 0, 0, 0),
	scale);
	
	sf::IntRect collisionRect = (*Game::Inst()->getPlayerCollisionRects())[(*Game::Inst()->getPlayerIDs())[index]];
	
	m_sprite.setScale(1.0f, 1.0f);
	
	m_sprite.setOrigin((float)collisionRect.left + (float)collisionRect.width / 2.0f, (float)collisionRect.top + (float)collisionRect.height / 2.0f);
	m_sprite.setScale(scale, scale);
	
	m_sprite.setPosition(position.x, position.y);

	m_bodyDef.position = b2Vec2(position.x / scale / 10.0f, position.y / scale / 10.0f);
	m_bodyDef.type = b2_dynamicBody;
	m_bodyDef.fixedRotation = true;
	
	m_pBody = Game::Inst()->getWorld()->CreateBody(&m_bodyDef);
	
	b2PolygonShape box;
	box.SetAsBox((float)collisionRect.width / 20.0f, (float)collisionRect.height / 20.0f);
	
	b2FixtureDef fixtureDef;
	
	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.00f;
	
	m_pBody->CreateFixture(&fixtureDef);
	m_bCollidable = true;
	m_bJumping = m_bRunning = false;
}

void Player::update() {
	m_sprite.setPosition(m_pBody->GetPosition().x * m_scale * 10.0f, m_pBody->GetPosition().y * m_scale * 10.0f);
	if(m_bRunning) {
		Game::Inst()->getWindow()->setView(sf::View(sf::FloatRect(m_sprite.getPosition().x - 300.0f, 0.0f, 1024.0f, 576.0f)));
	}
}

void Player::jump() {
	if(!m_bJumping)
		m_pBody->SetLinearVelocity(b2Vec2(m_pBody->GetLinearVelocity().x, -5.0f));
}

void Player::scale(float relativeScale) {
	m_relativeScale *= relativeScale;
	m_sprite.setScale(m_scale, m_scale * m_relativeScale);
}