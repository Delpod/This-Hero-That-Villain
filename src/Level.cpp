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
		
	for(std::list<GameObject*>::iterator it = m_obstacles.begin(); it != m_obstacles.end(); ++it)
		(*it)->draw();
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
	m_random.seed(time(0));
	
	float mult = 2.0f / (float)diff;
	
	std::uniform_int_distribution<unsigned int> uint_dist_first((unsigned int)(500 + 400 * mult), (unsigned int)(500 + 600 * mult));
	unsigned int first = uint_dist_first(m_random);
	
	std::uniform_int_distribution<unsigned int> uint_dist_obstacleIndex(0, Game::Inst()->getObstaclesIDs()->size() - 1);
	unsigned int obstacleIndex = uint_dist_obstacleIndex(m_random);
	
	sf::Vector2i obstacleSize = (*Game::Inst()->getObstacleSizes())[(*Game::Inst()->getObstaclesIDs())[obstacleIndex]];
	
	m_obstacles.push_back(new GameObject(
	*TextureManager::Inst()->getTexture((*Game::Inst()->getObstaclesIDs())[obstacleIndex]),
	sf::IntRect(first, 476 + (8 - obstacleSize.y) * 5, obstacleSize.x, obstacleSize.y),
	false,
	sf::IntRect(0, 0, 0, 0),
	5.0f,
	false));
	
	unsigned int last = first;
	
	std::uniform_int_distribution<unsigned int> uint_dist_from_last((unsigned int)(250 + 200 * mult), (unsigned int)(250 + 550 * mult));
	unsigned int from_last = uint_dist_from_last(m_random);
	
	while((last + from_last) < (size - 1000)) {
		
		obstacleIndex = uint_dist_obstacleIndex(m_random);
		obstacleSize = (*Game::Inst()->getObstacleSizes())[(*Game::Inst()->getObstaclesIDs())[obstacleIndex]];
		last += from_last;
		
		m_obstacles.push_back(new GameObject(
		*TextureManager::Inst()->getTexture((*Game::Inst()->getObstaclesIDs())[obstacleIndex]),
		sf::IntRect(last, 476 + (8 - obstacleSize.y) * 5, obstacleSize.x, obstacleSize.y),
		false,
		sf::IntRect(0, 0, 0, 0),
		5.0f,
		false));
		
		from_last = uint_dist_from_last(m_random);
	}
	
}