#include <SFML/Graphics.hpp>
#include "Game.h"

int main() {
	Game::Inst()->init(sf::VideoMode(1024, 576), "Ludum Dare 30", sf::Style::Close | sf::Style::Titlebar);
	
	while(Game::Inst()->isRunning()) {
		Game::Inst()->handleEvents();
		Game::Inst()->update();
		Game::Inst()->draw();
	}
	Game::Inst()->clean();
	return 0;
}