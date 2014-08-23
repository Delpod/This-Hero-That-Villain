#ifndef MENUBUTTON_H
#define MENUBUTTON_H
#include <SFML/Graphics.hpp>

class MenuButton{
public:
	MenuButton(sf::Font &font, std::string text, int callback);
	sf::Text* getText() { return &m_text; }
	sf::FloatRect getBounds() { return m_text.getGlobalBounds(); }
	int getCallback() { return m_callback; }
	void big() {
		if(m_callback != 0) {
			m_text.setCharacterSize(200);
			sf::FloatRect textRect = m_text.getLocalBounds();
			m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			m_big = true;
		}
	}
	void small() {
		if(m_callback != 0) {
			m_text.setCharacterSize(150); 
			sf::FloatRect textRect = m_text.getLocalBounds();
			m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			m_big = false;
		}
	}
	bool isBig() { return m_big; }
private:
	sf::Text m_text;
	int m_callback;
	bool m_big;
};

#endif // MENUBUTTON_H
