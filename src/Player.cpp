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
	
	m_colWidth = collisionRect.width / 2.0f;
	
	m_sprite.setScale(1.0f, 1.0f);
	
	m_sprite.setOrigin((float)collisionRect.left + (float)collisionRect.width / 2.0f, (float)collisionRect.top + (float)collisionRect.height / 2.0f);
	m_sprite.setScale(scale, scale);
	
	m_sprite.setPosition(position.x, position.y);

	m_bodyDef.position = b2Vec2(position.x / scale / 10.0f, position.y / scale / 10.0f - collisionRect.height / 20.0f - 0.8f);
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
	
	if(!b2TestOverlap(m_pBody->GetFixtureList()->GetAABB(0), Game::Inst()->getLevel()->getGround()->getBody()->GetFixtureList()->GetAABB(0)))
		m_bJumping = true;
	else
		m_bJumping = false;
		
	if(m_bInvulnerable) {
		if(m_invClock.getElapsedTime().asSeconds() >= 2.5f) {
			m_sprite.setColor(sf::Color::White);
			m_bInvulnerable = false;
			m_pBody->SetLinearVelocity(b2Vec2(5.0f, m_pBody->GetLinearVelocity().y));
		} else {
			int a = m_invClock.getElapsedTime().asSeconds() / 2.5f * 255;
			a = a < 64 ? 64 : a;
			m_sprite.setColor(sf::Color(255, 255, 255, a));
		}
	}
	
	
	if(!m_bInvulnerable) {
		
		if(b2TestOverlap(m_pBody->GetFixtureList()->GetAABB(0), Game::Inst()->getLevel()->getEnemy()->getBody()->GetFixtureList()->GetAABB(0))) {
			std::cout << "DIE!";
		}

		std::list<GameObject*> *obstacles = Game::Inst()->getLevel()->getObstacles();
		if(!obstacles->empty()) {
			std::list<GameObject*>::iterator it = obstacles->begin();
			sf::FloatRect player = m_sprite.getGlobalBounds();
			int c = 6 > obstacles->size() ? obstacles->size() : 6;
			for(int i = 0; i < c; ++i, ++it) {
				sf::FloatRect obstacle = (*it)->getSprite()->getGlobalBounds();
				if(player.intersects(obstacle)) {
					m_bInvulnerable = true;
					m_pBody->SetLinearVelocity(b2Vec2(4.33f, m_pBody->GetLinearVelocity().y));
					m_invClock.restart();
					break;
				}
			}
		}
	}
}

void Player::jump() {
	if(!m_bJumping) {
		m_pBody->SetLinearVelocity(b2Vec2(m_pBody->GetLinearVelocity().x, -5.0f - ((m_colWidth - 4.0f) / 10.0f)));
		m_bJumping = true;
	}
}

void Player::scale(float relativeScale) {
	m_relativeScale = relativeScale;
	m_sprite.setScale(m_scale, m_scale * m_relativeScale);
}