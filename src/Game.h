#ifndef GAME_H
#define GAME_H
#include <string>
#include <random>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <Box2D/Box2D.h>
#include "Level.h"
#include "MenuButton.h"

class Game {
public:
	static Game* Inst() {
		if(s_pInstance == nullptr)
			s_pInstance = new Game();
		return s_pInstance;
	}
	~Game() {}
	
	void init(sf::VideoMode vm, std::string title, int style);
	void handleEvents();
	void update();
	void draw();
	void clean();
	
	void initMainMenu();
	void initGame();
	void initPause();
	void initNextLevel();
	void initLose();
	
	Level*								getLevel()					{ return m_pLevel; }
	b2World*							getWorld()					{ return m_pLevel->getWorld(); }
	sf::RenderWindow*					getWindow()					{ return m_pWindow; }
	std::vector<std::string>*			getPlayerIDs()				{ return &m_playerIDs; }
	std::vector<std::string>*			getEnemyIDs()				{ return &m_enemyIDs; }
	std::vector<std::string>*			getObstaclesIDs()			{ return &m_obstaclesIDs; }
	std::map<std::string, std::string>*	getPlayerNames()			{ return &m_playerNames; }
	std::map<std::string, std::string>*	getEnemyNames()				{ return &m_enemyNames; }
	std::map<std::string, sf::IntRect>*	getPlayerCollisionRects()	{ return &m_playerCollisionRects; }
	std::map<std::string, sf::IntRect>*	getEnemyCollisionRects()	{ return &m_enemyCollisionRects; }
	std::map<std::string, sf::Vector2i>*getObstacleSizes()			{ return &m_obstacleSizes; }

	bool isRunning() { return m_bRunning; }
	void increaseDiff() { m_diff += 2; }
	
private:
	Game() {}
	void loadTextures();
	sf::RenderWindow *m_pWindow;
	sf::Music m_music;
	sf::Font m_font;
	sf::Font m_logoFont;
	sf::Text m_logoText;
	sf::RectangleShape m_whiteScreen;
	std::vector<MenuButton*> m_menuButtons;
	std::vector<sf::Drawable*> m_menuDrawables;
	std::vector<std::string> m_playerIDs;
	std::vector<std::string> m_enemyIDs;
	std::vector<std::string> m_obstaclesIDs;
	std::map<std::string, std::string> m_playerNames;
	std::map<std::string, std::string> m_enemyNames;
	std::map<std::string, sf::IntRect> m_playerCollisionRects;
	std::map<std::string, sf::IntRect> m_enemyCollisionRects;
	std::map<std::string, sf::Vector2i>m_obstacleSizes;
	Level *m_pLevel;
	int m_diff;
	bool m_bRunning;
	enum { LOGO, MENU, GAME, PAUSE, LOSE , NEXTLEVEL} state;
	static Game* s_pInstance;
};

#endif // GAME_H 