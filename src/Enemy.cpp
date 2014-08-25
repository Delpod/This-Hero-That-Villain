#include "Enemy.h"
#include "Game.h"
#include "TextureManager.h"

Enemy::Enemy(int index, sf::Vector2f position, float scale) {
	sf::Vector2u size = TextureManager::Inst()->getTexture((*Game::Inst()->getEnemyIDs())[index])->getSize();
	load(*TextureManager::Inst()->getTexture((*Game::Inst()->getEnemyIDs())[index]),
	sf::IntRect(position.x, position.y, size.x, size.y),
	false,
	sf::IntRect(0, 0, 0, 0),
	scale);
	
	sf::IntRect collisionRect = (*Game::Inst()->getEnemyCollisionRects())[(*Game::Inst()->getEnemyIDs())[index]];
	
	m_sprite.setScale(1.0f, 1.0f);
	
	m_sprite.setOrigin((float)collisionRect.left + (float)collisionRect.width / 2.0f, (float)collisionRect.top + (float)collisionRect.height / 2.0f);
	m_sprite.setScale(scale, scale);
	
	m_sprite.setPosition(position.x, position.y);
	m_bodyDef.position = b2Vec2(position.x / scale / 10.0f, position.y / scale / 10.0f - collisionRect.height / 20.0f - 0.8f);
	
	m_bodyDef.type = b2_kinematicBody;
	m_bodyDef.fixedRotation = true;
	
	m_pBody = Game::Inst()->getWorld()->CreateBody(&m_bodyDef);
	
	b2PolygonShape box;
	box.SetAsBox((float)collisionRect.width / 20.0f, (float)collisionRect.height / 20.0f);
	
	b2FixtureDef fixtureDef;

	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.05f;
	
	m_pBody->CreateFixture(&fixtureDef);
	m_bCollidable = true;
	m_rSide = -1;
}

void Enemy::update() {
	if(Game::Inst()->getLevel()->getPlayer()->isRunning()) {
		sf::Vector2f origin = m_sprite.getOrigin();
		m_sprite.setOrigin(m_sprite.getLocalBounds().width / 2.0f, m_sprite.getLocalBounds().height);
		m_sprite.rotate(0.5f * m_rSide);
		if((m_rSide == 1 && m_sprite.getRotation() >= m_rSide * 5.0f && m_sprite.getRotation() < 180.0f) || (m_rSide == -1 && m_sprite.getRotation() <= 360.0f + (m_rSide * 5.0f) && m_sprite.getRotation() > 180.0f))
			m_rSide *= -1;
		m_sprite.setOrigin(origin);
	}
	m_sprite.setPosition(m_pBody->GetPosition().x * m_scale * 10.0f, m_pBody->GetPosition().y * m_scale * 10.0f);	
}

void Enemy::run() {
		m_pBody->SetLinearVelocity(b2Vec2(5.0f, m_pBody->GetLinearVelocity().y));
}