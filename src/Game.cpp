#include "Game.h"
#include "TextureManager.h"

Game* Game::s_pInstance = nullptr;

void Game::init(sf::VideoMode vm, std::string title, int style) {
	m_pWindow = new sf::RenderWindow(vm, title, style);
	m_pWindow->setVerticalSyncEnabled(true);
	sf::Image icon;
	icon.loadFromFile("data/gfx/tvth.png");
	m_pWindow->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	loadTextures();
	m_whiteScreen.setFillColor(sf::Color(255, 255, 255, 160));
	m_whiteScreen.setSize(sf::Vector2f(vm.width, vm.height));
	m_whiteScreen.setOrigin(vm.width / 2.0f, vm.height / 2.0f);
	m_pLevel = nullptr;
	m_diff = 2;
	m_music.openFromFile("data/music/bc.ogg");
	m_music.setLoop(true);
	initMainMenu();
	m_music.play();
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
	m_playerIDs.push_back("plumber");
	m_playerIDs.push_back("isaac");
	m_playerIDs.push_back("octopus");
	m_playerIDs.push_back("steve");
	m_playerIDs.push_back("tom");
	m_playerIDs.push_back("v");

	m_enemyIDs.push_back("witch");
	m_enemyIDs.push_back("queen");
	m_enemyIDs.push_back("doctor");
	m_enemyIDs.push_back("evilplumber");
	m_enemyIDs.push_back("icequeen");
	m_enemyIDs.push_back("jester");

	m_playerNames["white"] = std::string("White");
	m_playerNames["littlered"] = std::string("Little Red");
	m_playerNames["meatguy"] = std::string("Meat Guy");
	m_playerNames["tim"] = std::string("Tim");
	m_playerNames["plumber"] = std::string("Japanese Plumber");
	m_playerNames["isaac"] = std::string("Isaac");
	m_playerNames["octopus"] = std::string("Mr. Octopus");
	m_playerNames["steve"] = std::string("Steve");
	m_playerNames["tom"] = std::string("Tom");
	m_playerNames["v"] = std::string("V6X");
	
	m_enemyNames["witch"] = std::string("Witch");
	m_enemyNames["queen"] = std::string("Evil Queen");
	m_enemyNames["doctor"] = std::string("Dr.");
	m_enemyNames["evilplumber"] = std::string("Evil Japanese Plumber");
	m_enemyNames["icequeen"] = std::string("Queen of Ice");
	m_enemyNames["jester"] = std::string("Jester");
	
	m_playerCollisionRects["white"] = sf::IntRect(4, 4, 10, 28);
	m_playerCollisionRects["littlered"] = sf::IntRect(0, 0, 10, 26);
	m_playerCollisionRects["meatguy"] = sf::IntRect(0, 0, 20, 18);
	m_playerCollisionRects["tim"] = sf::IntRect(2, 4, 12, 26);
	m_playerCollisionRects["plumber"] = sf::IntRect(0, 0, 12, 28);
	m_playerCollisionRects["isaac"] = sf::IntRect(0, 0, 12, 26);
	m_playerCollisionRects["octopus"] = sf::IntRect(0, 0, 10, 32);
	m_playerCollisionRects["steve"] = sf::IntRect(0, 0, 10, 32);
	m_playerCollisionRects["tom"] = sf::IntRect(0, 0, 16, 28);
	m_playerCollisionRects["v"] = sf::IntRect(0, 0, 14, 30);
	
	m_enemyCollisionRects["witch"] = sf::IntRect(0, 0, 14, 32);
	m_enemyCollisionRects["queen"] = sf::IntRect(0, 4, 14, 36);
	m_enemyCollisionRects["doctor"] = sf::IntRect(0, 6, 18, 20);
	m_enemyCollisionRects["evilplumber"] = sf::IntRect(0, 0, 14, 28);
	m_enemyCollisionRects["icequeen"] = sf::IntRect(4, 2, 14, 34);
	m_enemyCollisionRects["jester"] = sf::IntRect(2, 2, 12, 34);
	
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
		if(state == MENU || state == PAUSE || state == NEXTLEVEL || state == LOSE) {
			if(event.type == sf::Event::MouseMoved) {
				sf::Vector2i mousePos = sf::Mouse::getPosition(*m_pWindow);
				for(unsigned int i = 0; i < m_menuButtons.size(); ++i) {
					if(mousePos.x > m_menuButtons[i]->getBounds().left &&
						mousePos.x < m_menuButtons[i]->getBounds().left + m_menuButtons[i]->getBounds().width &&
						mousePos.y > m_menuButtons[i]->getBounds().top &&
						mousePos.y < m_menuButtons[i]->getBounds().top + m_menuButtons[i]->getBounds().height)
							m_menuButtons[i]->big();
					else 
							m_menuButtons[i]->small();
				}
			} else if(event.type == sf::Event::MouseButtonReleased) {
				for(unsigned int i = 0; i < m_menuButtons.size(); ++i) {
					if(m_menuButtons[i]->isBig()) {
						switch(m_menuButtons[i]->getCallback()) {
						case 1:
							initGame();
							break;
						case 2:
							m_bRunning = false;
							break;
						case 3:
							m_music.setVolume(70.0f);
							state = GAME;
							break;
						case 4:
							initMainMenu();
							break;
						case 5:
							increaseDiff();
							delete m_pLevel;
							initGame();
							break;
						case 6:
							delete m_pLevel;
							initGame();
							break;
						default:
							break;
						}
						break;
					}
				}
			}
		} else if(state == GAME) {
			if(event.type == sf::Event::KeyPressed) {
				if(event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::W) {
					if(m_pLevel->getPlayer()->isRunning()) {
						m_pLevel->getPlayer()->jump();
					} else {
						m_pLevel->getPlayer()->run();
						m_pLevel->getEnemy()->run();
					}
				} else if(event.key.code == sf::Keyboard::Escape) {
					initPause();
				}
			}
		}
	}
}

void Game::update() {
	if(m_bRunning) {
		if(state == GAME) {
			m_pLevel->update();
		}
	}
}

void Game::draw() {
	if(m_bRunning) {
		m_pWindow->clear(sf::Color(0, 0, 0));
		if(state == GAME || state == PAUSE || state == NEXTLEVEL || state == LOSE) {
			m_pLevel->draw();
			if(state == PAUSE || state == NEXTLEVEL || state == LOSE) {
				sf::View view = m_pWindow->getView();
				m_pWindow->setView(m_pWindow->getDefaultView());
				m_pWindow->draw(m_whiteScreen);
				for(unsigned int i = 0; i < m_menuButtons.size(); ++i)
					m_pWindow->draw(*m_menuButtons[i]->getText());
				m_pWindow->setView(view);
			}
		} else if(state == MENU) {
			for(unsigned int i = 0; i < m_menuDrawables.size(); ++i)
				m_pWindow->draw(*m_menuDrawables[i]);
			m_pWindow->draw(m_whiteScreen);
			m_pWindow->draw(m_logoText);
			for(unsigned int i = 0; i < m_menuButtons.size(); ++i)
				m_pWindow->draw(*m_menuButtons[i]->getText());
		}
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

void Game::initMainMenu() {
	if(m_pLevel != nullptr) {
		delete m_pLevel;
		m_pLevel = nullptr;
	}
	m_music.setVolume(50.0f);
	m_menuButtons.clear();
	
	m_pWindow->setView(m_pWindow->getDefaultView());
	
	m_whiteScreen.setPosition(m_pWindow->getView().getCenter());
	
	sf::Sprite* pSprite = new sf::Sprite(*TextureManager::Inst()->getTexture("background"));
	pSprite->setOrigin(pSprite->getLocalBounds().width / 2.0f, pSprite->getLocalBounds().height / 2.0f);
	
	pSprite->setPosition(m_pWindow->getView().getCenter());
	
	m_menuDrawables.push_back(pSprite);
	
	m_logoFont.loadFromFile("data/fonts/Chalk_Line_Outline.ttf");
	m_logoText.setColor(sf::Color::Black);
	m_logoText.setFont(m_logoFont);
	m_logoText.setCharacterSize(150);
	m_logoText.setString("This Hero,\nThat Villain.");
	m_logoText.setStyle(sf::Text::Bold);
	
	sf::FloatRect textRect = m_logoText.getLocalBounds();
	
	m_logoText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	m_logoText.setScale(0.5f, 0.5f);
	m_logoText.setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y - m_pWindow->getView().getSize().y / 4.0f);
	
	m_font.loadFromFile("data/fonts/FORCED_SQUARE.ttf");
	
	m_menuButtons.push_back(new MenuButton(m_font, "Start", 1));
	m_menuButtons[0]->getText()->setPosition(m_pWindow->getView().getCenter());
	
	m_menuButtons.push_back(new MenuButton(m_font, "Exit", 2));
	m_menuButtons[1]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y + m_pWindow->getView().getSize().y / 4.0f);
	state = MENU;
}

void Game::initGame() {
	m_music.setVolume(70.0f);
	m_pLevel = new Level();
	m_pLevel->create(m_diff);
	state = GAME;
}

void Game::initPause() {
	m_music.setVolume(50.0f);
	sf::View view = m_pWindow->getView();
	m_menuButtons.clear();
	m_pWindow->setView(m_pWindow->getDefaultView());
	m_whiteScreen.setPosition(m_pWindow->getView().getCenter());

	m_font.loadFromFile("data/fonts/FORCED_SQUARE.ttf");
	
	m_menuButtons.push_back(new MenuButton(m_font, "Return", 3));
	m_menuButtons[0]->getText()->setPosition(m_pWindow->getView().getCenter());
	
	m_menuButtons.push_back(new MenuButton(m_font, "Main Menu", 4));
	m_menuButtons[1]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y + m_pWindow->getView().getSize().y / 4.0f);
	m_pWindow->setView(view);
	state = PAUSE;
}

void Game::initNextLevel() {
	m_music.setVolume(50.0f);
	sf::View view = m_pWindow->getView();
	m_menuButtons.clear();
	m_pWindow->setView(m_pWindow->getDefaultView());
	m_whiteScreen.setPosition(m_pWindow->getView().getCenter());

	m_font.loadFromFile("data/fonts/FORCED_SQUARE.ttf");
	
	m_menuButtons.push_back(new MenuButton(m_font, "Level Complete", 0));
	m_menuButtons[0]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y - m_pWindow->getView().getSize().y / 4.0f);
	
	m_menuButtons.push_back(new MenuButton(m_font, "Next Level", 5));
	m_menuButtons[1]->getText()->setPosition(m_pWindow->getView().getCenter());
	
	m_menuButtons.push_back(new MenuButton(m_font, "Main Menu", 4));
	m_menuButtons[2]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y + m_pWindow->getView().getSize().y / 4.0f);
	m_pWindow->setView(view);
	state = NEXTLEVEL;
}

void Game::initLose() {
	m_music.setVolume(50.0f);
	sf::View view = m_pWindow->getView();
	m_menuButtons.clear();
	m_pWindow->setView(m_pWindow->getDefaultView());
	m_whiteScreen.setPosition(m_pWindow->getView().getCenter());

	m_font.loadFromFile("data/fonts/FORCED_SQUARE.ttf");
	
	m_menuButtons.push_back(new MenuButton(m_font, "You Lose", 0));
	m_menuButtons[0]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y - m_pWindow->getView().getSize().y / 4.0f);
	
	m_menuButtons.push_back(new MenuButton(m_font, "Retry", 6));
	m_menuButtons[1]->getText()->setPosition(m_pWindow->getView().getCenter());
	
	m_menuButtons.push_back(new MenuButton(m_font, "Main Menu", 4));
	m_menuButtons[2]->getText()->setPosition(m_pWindow->getView().getCenter().x, m_pWindow->getView().getCenter().y + m_pWindow->getView().getSize().y / 4.0f);
	m_pWindow->setView(view);
	state = LOSE;
}