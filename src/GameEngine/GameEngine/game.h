#pragma once
#include <string> 
#include <iostream>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <windows.h>

namespace softartstudios {
	class Game
	{
	public:
		Game();
		~Game();
		void Run();
		void setDebugMode(bool debugMode);
		void setGameName(char* str);
	private:
		int Config(); // Initialize Game
		int Init(); // Initialize Game
		int LoadAssests(); // Load All Required Images, Audio, Etc
		int UnLoadAssests(); // Unload All Previously Load Assests
		void GameLoop(float dt); // GAME LOOP
		bool debugMode = 0; // Debug Mode Flag
		void Log(char* str);
		void Log(float str);
		void Log(std::string str);
		sf::RenderWindow* window;
		sf::Event event;
		sf::Clock clock;
		char* window_name = "Default Game";
		int window_width = 1920;
		int window_height = 1080;
		sf::Uint32 window_style = sf::Style::Fullscreen;
	};

}