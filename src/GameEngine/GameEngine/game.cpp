#include "game.h"

softartstudios::Game::Game()
{
}

softartstudios::Game::~Game()
{
	if (this->debugMode) {
		this->Log("Unloading Assets");
	}
	this->UnLoadAssests();
	if (this->debugMode) {
		this->Log("Closing Game");
	}
}

void softartstudios::Game::Log(char* str)
{
	std::cout << str << std::endl;
}

void softartstudios::Game::Log(float str)
{
	std::cout << str << std::endl;
}

void softartstudios::Game::Log(std::string str)
{
	std::cout << str << std::endl;
}

void softartstudios::Game::setGameName(char* str)
{
	this->window_name = str;
}

void softartstudios::Game::setDebugMode(bool debugMode)
{
	this->debugMode = debugMode;
	if (this->debugMode) {
		this->Log("Debug Mode Enabled");
		ShowWindow(GetConsoleWindow(), SW_RESTORE);
	}
	else {
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
}

void softartstudios::Game::Run()
{
	if (this->debugMode) {
		this->Log("Running Game");
	}
	this->Init();
	this->LoadAssests();
	float dt = this->clock.restart().asSeconds();
	// TODO: Game Logic Here
	while (this->window->isOpen()) {
		while (this->window->pollEvent(this->event)) {
			if ((&(sf::Event)this->event)->type == sf::Event::Closed) {
				this->window->close();
			}
		}
		dt = this->clock.restart().asSeconds();
		if (this->debugMode) {
			auto result = "Time: " + std::to_string(dt);
			this->Log(result);
		}
		this->GameLoop(dt);
	}
}



int softartstudios::Game::Config() {
	if (this->debugMode) {
		this->Log("Loading Game Configs");
	}
	int lineCounter = 0;
	std::string line;
	std::ifstream config("app.config");
	if (!this->debugMode) {
		if (config.is_open())
		{
			if (this->debugMode) {
				this->Log("Opened Config File");
			}
			while (getline(config, line))
			{
				if (lineCounter == 0) {
					this->window_height = (int)std::stoi(line);
				}
				if (lineCounter == 0) {
					this->window_width = (int)std::stoi(line);
				}
				if (lineCounter == 0) {
					this->window_style = (uint32_t)std::stoi(line);
				}
				lineCounter++;
			}
			config.close();
		}
		else {
			if (this->debugMode) {
				this->Log("Config File Doesn't Exist, Loading Default Settings");
			}
			this->window_height = 1080;
			this->window_width = 1920;
			this->window_style = sf::Style::Fullscreen;
		}
	}

	if (this->debugMode) {
		this->Log("Loading Debug Config Data");
		this->window_height = 1080;
		this->window_width = 1920;
		this->window_style = sf::Style::Fullscreen;
	}
	return 0;
}

int softartstudios::Game::Init() {
	if (this->debugMode) {
		this->Log("Initializing Game");
	}
	this->Config();
	this->window = new sf::RenderWindow(sf::VideoMode(this->window_width, this->window_height), this->window_name, this->window_style);
	this->clock = sf::Clock();
	return 0;
}
int softartstudios::Game::LoadAssests() {
	if (this->debugMode) {
		this->Log("Loading Game Assest");
	}
	return 0;
}
int softartstudios::Game::UnLoadAssests() {
	if (this->debugMode) {
		this->Log("Unloading Game Assests");
	}
	return 0;
}

void softartstudios::Game::GameLoop(float dt) {

}