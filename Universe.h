/*
 *  Universe.h
 *  GameOfLife
 *
 *  Created by R1D1 on 25/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef UNIVERS_H
#define UNIVERS_H

#include <SFML/Graphics.hpp>
#include <iostream>

#define DIM 60

class Universe
{
	public :
		Universe();
		~Universe();

		int getLocation(int x, int y);
		int getLocation_past(int x, int y);
		void setLocation(int x, int y, int valeur);
		void setLocation_past(int x, int y, int valeur);
		
		void init_rocket_universe();
		void init_bird_universe();
		void init_helix_universe();
		void init_trial_universe();
		void init_rand_universe();
		void reset();
		void update_universe();
		void display(sf::RenderWindow & appli);

	private :
		int universe[DIM][DIM];
		int past_universe[DIM][DIM];
};

#endif
