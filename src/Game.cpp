#include "Game.h"
#include "TextureManager.h"

Game* Game::s_pInstance = nullptr;

void Game::init(sf::VideoMode vm, std::string title, int style) {
	m_pWindow = new sf::RenderWindow(vm, title, style);
	m_pWindow->setVerticalSyncEnabled(true);
	loadTextures();
	m_pLevel = new Level();
	m_pLevel->create(2);
	m_bRunning = true;
}

void Game::loadTextures() {
	TextureManager::Inst()->load("data/gfx/ground.png", "ground");
	TextureManager::Inst()->load("data/gfx/background.png", "background");
	
	TextureManager::Inst()->load("data/gfx/branch.png", "branch");
	TextureManager::Inst()->load("data/gfx/rock.png", "rock");
	
	m_obstaclesIDs.push_back("branch");
	m_obstaclesIDs.push_back("rock");
	
	m_obstacleSizes["branch"] = sf::Vector2i(8, 8);
	m_obstacleSizes["rock"] = sf::Vector2i(10, 6);
	
	m_playerIDs.push_back("white");
	m_playerIDs.push_back("littlered");
	m_playerIDs.push_back("meatguy");
	m_playerIDs.push_back("tim");
	
	m_enemyIDs.push_back("witch");
	m_enemyIDs.push_back("queen");
	m_enemyIDs.push_back("fetus");
	
	m_playerNames["white"] = std::string("White");
	m_playerNames["littlered"] = std::string("Little Red");
	m_playerNames["meatguy"] = std::string("Meat Guy");
	m_playerNames["tim"] = std::string("Tim");
	
	m_enemyNames["witch"] = std::string("Witch");
	m_enemyNames["queen"] = std::string("Evil Queen");
	m_enemyNames["fetus"] = std::string("Fetus");
	
	m_playerCollisionRects["white"] = sf::IntRect(4, 4, 10, 28);
	m_playerCollisionRects["littlered"] = sf::IntRect(0, 0, 10, 26);
	m_playerCollisionRects["meatguy"] = sf::IntRect(0, 0, 20, 18);
	m_playerCollisionRects["tim"] = sf::IntRect(2, 4, 12, 26);
	
	m_enemyCollisionRects["witch"] = sf::IntRect(0, 0, 14, 32);
	m_enemyCollisionRects["queen"] = sf::IntRect(0, 4, 14, 36);
	m_enemyCollisionRects["fetus"] = sf::IntRect(0, 6, 18, 20);
	
	for(unsigned int i = 0; i < m_playerIDs.size(); ++i) {
		std::string path = "data/gfx/";
		path += m_playerIDs[i];
		path += ".png";
		TextureManager::Inst()->load(path, m_playerIDs[i]);
	}
	
	for(unsigned int i = 0; i < m_enemyIDs.size(); ++i) {
		std::string path = "data/gfx/";
		path += m_enemyIDs[i];
		path += ".png";
		TextureManager::Inst()->load(path, m_enemyIDs[i]);
	}
}

void Game::handleEvents() {
	sf::Event event;
	while(m_pWindow->pollEvent(event)) {
		if(event.type == sf::Event::Closed)
			m_bRunning = false;
		else if(event.type == sf::Event::KeyPressed && (event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::W)) {
			if(m_pLevel->getPlayer()->isRunning()) {
				m_pLevel->getPlayer()->jump();
			} else {
				m_pLevel->getPlayer()->run();
				m_pLevel->getEnemy()->run();
			}
		}
	}
}

void Game::update() {
	if(m_bRunning)
		m_pLevel->update();
}

void Game::draw() {
	if(m_bRunning) {
		m_pWindow->clear(sf::Color(0, 0, 0));
		m_pLevel->draw();
		m_pWindow->display();
	}
}

void Game::clean() {
	m_playerIDs.clear();
	m_enemyIDs.clear();
	m_playerNames.clear();
	m_enemyNames.clear();
	m_playerCollisionRects.clear();
	m_enemyCollisionRects.clear();
	
	m_pWindow->close();
	
	delete m_pWindow;
	delete m_pLevel;
	
	m_pWindow = nullptr;
	m_pLevel = nullptr;
}