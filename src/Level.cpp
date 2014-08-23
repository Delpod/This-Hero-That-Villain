#include "Level.h"
#include "Game.h"
#include "TextureManager.h"
#include <iostream>

Level::Level() {
	b2Vec2 gravity(0.0f, 10.0f);
	m_pWorld = new b2World(gravity);
}

void Level::create(int diff) {
	m_random.seed(time(0));
	
	float mult = (float)(10 + diff) / 10.0f;
	
	std::uniform_int_distribution<unsigned int> uint_dist_size((unsigned int)(15000 * mult), (unsigned int)(20000 * mult));
	unsigned int size = uint_dist_size(m_random);
	
	m_pGround = new GameObject(
		*TextureManager::Inst()->getTexture("ground"),
		sf::IntRect(size / 2.0f, Game::Inst()->getWindow()->getDefaultView().getSize().y - 40, size / 5.0f, 16),
		true,
		sf::IntRect(0, 0, 0, 0),
		5.0f,
		true);
		
	m_pBackground = new GameObject(
		*TextureManager::Inst()->getTexture("background"),
		sf::IntRect(512, 288, 1024, 576),
		false,
		sf::IntRect(0, 0, 0, 0),
		1.0f,
		false);
		
	std::uniform_int_distribution<unsigned int> uint_dist_index1(0, Game::Inst()->getPlayerIDs()->size() - 1);
	unsigned int index = uint_dist_index1(m_random); 
	
	m_pPlayer = new Player(index, sf::Vector2f(300, 536));
	
	std::uniform_int_distribution<unsigned int> uint_dist_index2(0, Game::Inst()->getEnemyIDs()->size() - 1);
	index = uint_dist_index2(m_random);
	
	m_pEnemy = new Enemy(index, sf::Vector2f(0, 536));
	
	generateObstacles(diff, size);
}

Level::~Level() {
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pGround;

	delete m_pBackground;
		
	for(unsigned int i = 0; i < m_foreground.size(); ++i) 
		delete m_foreground[i];

	m_foreground.clear();
	
	delete m_pWorld;
}


void Level::draw() {
	m_pBackground->draw();
	sf::Sprite* pSprite = m_pBackground->getSprite();
	pSprite->move(pSprite->getLocalBounds().width, 0.0f);
	m_pBackground->draw();
	pSprite->move(-pSprite->getLocalBounds().width, 0.0f);
		
	m_obstacles.front()->draw();
	m_pGround->draw();
	m_pPlayer->draw();
	m_pEnemy->draw();
	
	for(unsigned int i = 0; i < m_foreground.size(); ++i)
		m_foreground[i]->draw();
	
}
void Level::update() {
	m_pWorld->Step(1/60.0f, 6, 2);
	m_pBackground->update();
	sf::Sprite* pSprite = m_pBackground->getSprite();
	if(pSprite->getPosition().x + pSprite->getOrigin().x <= Game::Inst()->getWindow()->getView().getCenter().x - Game::Inst()->getWindow()->getView().getSize().x / 2.0f)
		pSprite->setPosition(pSprite->getPosition().x + pSprite->getLocalBounds().width, pSprite->getPosition().y);
		
	m_pGround->update();
	m_pPlayer->update();
	m_pEnemy->update();
	
	for(unsigned int i = 0; i < m_foreground.size(); ++i)
		m_foreground[i]->update();
}

void Level::generateObstacles(unsigned int diff, unsigned int size) {
	m_obstacles.push_back(new GameObject(
	*TextureManager::Inst()->getTexture("branch"),
	sf::IntRect(1000, 476, 8, 8),
	false,
	sf::IntRect(0, 0, 0, 0),
	5.0f,
	false));
}