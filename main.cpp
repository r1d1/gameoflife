#include <SFML/Graphics.hpp>
#include "Universe.h"

#define WIDTH 360
#define HEIGHT 360

int main()
{
	// Create main window
	sf::RenderWindow App(sf::VideoMode(WIDTH, HEIGHT), "Game of Life");
	
	bool run = false;
	Universe GoLife;
	
	// Start game loop
	while (App.IsOpened())
	{
		// Process events
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			// Close window : exit
			if (Event.Type == sf::Event::Closed){ App.Close(); }
		}
		if (App.GetInput().IsKeyDown(sf::Key::Q)){ App.Close(); }
		if (App.GetInput().IsKeyDown(sf::Key::H)){ GoLife.init_helix_universe(); }
		if (App.GetInput().IsKeyDown(sf::Key::R)){ GoLife.init_rocket_universe(); }
		if (App.GetInput().IsKeyDown(sf::Key::B)){ GoLife.init_bird_universe(); }
		if (App.GetInput().IsKeyDown(sf::Key::T)){ GoLife.init_trial_universe(); }
		if (App.GetInput().IsKeyDown(sf::Key::C)){ GoLife.init_rand_universe(); }	
		if (App.GetInput().IsKeyDown(sf::Key::V)){ GoLife.init_randfloat_universe(); }	
		if (App.GetInput().IsKeyDown(sf::Key::E)){ GoLife.reset(); run = false; }
		if (App.GetInput().IsKeyDown(sf::Key::A)){ run = true; }
		if (App.GetInput().IsKeyDown(sf::Key::Z)){ run = false; }
		if(run){ GoLife.update_universe(); }

		// Clear screen
		App.Clear(sf::Color::Black);
		GoLife.display(App);
	}
	return EXIT_SUCCESS;
}
