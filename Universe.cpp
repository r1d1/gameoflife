/*
 *  Universe.cpp
 *  GameOfLife
 *
 *  Created by R1D1 on 25/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "Universe.h"

Universe::Universe(){ reset(); }
Universe::~Universe(){}

void Universe::init_rocket_universe()
{
	universe[DIM/2][DIM/2-1]=1;
	universe[DIM/2 -1][DIM/2]=1;
	universe[DIM/2-1][DIM/2+1]=1;
	universe[DIM/2][DIM/2+1]=1;
	universe[DIM/2+1][DIM/2+1]=1;

	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++){ past_universe[i][j] = universe[i][j]; } }
}

void Universe::init_bird_universe()
{
	universe[(DIM/2)-3][(DIM/2)-1]=1;
	universe[(DIM/2)-3][(DIM/2)+1]=1;
	universe[(DIM/2)-2][(DIM/2)+2]=1;
	universe[(DIM/2)-1][(DIM/2)-2]=1;
	universe[(DIM/2)-1][(DIM/2)+2]=1;
	universe[(DIM/2)][(DIM/2)-2]=1;
	universe[(DIM/2)][(DIM/2)+2]=1;
	universe[(DIM/2)+1][(DIM/2)+2]=1;
	universe[(DIM/2)+2][(DIM/2)-1]=1;
	universe[(DIM/2)+2][(DIM/2)+2]=1;
	universe[(DIM/2)+3][(DIM/2)]=1;
	universe[(DIM/2)+3][(DIM/2)+1]=1;
	universe[(DIM/2)+3][(DIM/2)+2]=1;

	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++){ past_universe[i][j] = universe[i][j]; } }
}

void Universe::init_helix_universe()
{
	universe[(DIM/2)-3][(DIM/2)]=1;
	universe[(DIM/2)-2][(DIM/2)]=1;
	universe[(DIM/2)-1][(DIM/2)]=1;
	universe[(DIM/2)][(DIM/2)]=1;
	universe[(DIM/2)+1][(DIM/2)]=1;
	universe[(DIM/2)+2][(DIM/2)]=1;
	universe[(DIM/2)+3][(DIM/2)]=1;
		
	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++) { past_universe[i][j] = universe[i][j]; } }
}


void Universe::init_trial_universe()
{
	universe[(DIM/2)-4][(DIM/2)-2]=1;
	universe[(DIM/2)-4][(DIM/2)-1]=1;
	universe[(DIM/2)-4][(DIM/2)]=1;
	
	universe[(DIM/2)-3][(DIM/2)-3]=1;
	universe[(DIM/2)-3][(DIM/2)+1]=1;

	universe[(DIM/2)-2][(DIM/2)-3]=1;
	universe[(DIM/2)-2][(DIM/2)+2]=1;

	universe[(DIM/2)-1][(DIM/2)-2]=1;
	universe[(DIM/2)-1][(DIM/2)+3]=1;

	universe[(DIM/2)][(DIM/2)-1]=1;
	universe[(DIM/2)][(DIM/2)+4]=1;

	universe[(DIM/2)+1][(DIM/2)-2]=1;
	universe[(DIM/2)+1][(DIM/2)+3]=1;

	universe[(DIM/2)+2][(DIM/2)-3]=1;
	universe[(DIM/2)+2][(DIM/2)+2]=1;

	universe[(DIM/2)+3][(DIM/2)-3]=1;
	universe[(DIM/2)+3][(DIM/2)+1]=1;

	universe[(DIM/2)+4][(DIM/2)-2]=1;
	universe[(DIM/2)+4][(DIM/2)-1]=1;
	universe[(DIM/2)+4][(DIM/2)]=1;
	
	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++){ past_universe[i][j] = this->universe[i][j]; } }
}


void Universe::init_rand_universe()
{
	for(int i = 0; i < DIM; i++)
	{
		for(int j=0 ; j < DIM ; j++)
		{
			universe[i][j] = rand() % 2;
			//std::cout << universe[i][j] << std::endl;
			past_universe[i][j] = universe[i][j];
		}
	}
}

void Universe::init_randfloat_universe()
{
	for(int i = 0; i < DIM; i++)
	{
		for(int j=0 ; j < DIM ; j++)
		{
			universe[i][j] = rand() % 100 / 100.0;
			//std::cout << universe[i][j] << std::endl;
			past_universe[i][j] = universe[i][j];
		}
	}
}

void Universe::reset()
{
	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++){ past_universe[i][j] = universe[i][j] = 0; } }
}

void Universe::update_universe()
{
	int i_lesser, i_upper, j_lesser, j_upper;
	int sum = 0;

	// Memorising the current state of the world to compute next one
	for(int i = 0; i < DIM; i++){ for(int j=0 ; j < DIM ; j++){ past_universe[i][j] = universe[i][j]; } }

	//=====================================================
	//			Game of Life Rules
	//=====================================================

	for(int i=0; i < DIM; i++)
	{
		for(int j=0 ; j < DIM ; j++)
		{	
			sum = 0;
			if(i == 0){ i_lesser = DIM-1; } else { i_lesser = i-1; }
			if(j == 0){ j_lesser = DIM-1; } else { j_lesser = j-1; }
			if(i == DIM-1){ i_upper = 0; } else { i_upper = i+1; }
			if(j == DIM-1){ j_upper = 0; } else { j_upper = j+1; }
			
			if(getLocation_past(i_lesser, j_lesser) == 1){ sum++; }
			if(getLocation_past(i_lesser, j) == 1){ sum++; }
			if(getLocation_past(i_lesser, j_upper) == 1){ sum++; }
			if(getLocation_past(i, j_lesser) == 1){ sum++; }
			if(getLocation_past(i, j_upper) == 1){ sum++; }
			if(getLocation_past(i_upper, j_lesser) == 1){ sum++; }
			if(getLocation_past(i_upper, j) == 1){ sum++; }
			if(getLocation_past(i_upper, j_upper) == 1){ sum++; }

			// Checking neightbours 
			if (getLocation_past(i,j) == 1){ if(sum > 3 || sum < 2){ universe[i][j] = 0; } }
			//if (getLocation_past(i,j) > 0.5){ if(sum > 3 || sum < 2){ universe[i][j] = 0.0; } }
			else{ if(sum == 3){ universe[i][j] += 1.0; } }
		}
	}
	//=====================================================	
}

//int Universe::getLocation(int x, int y){ return universe[x][y]; }
//int Universe::getLocation_past(int x, int y){ return past_universe[x][y]; }
float Universe::getLocation(int x, int y){ return universe[x][y]; }
float Universe::getLocation_past(int x, int y){ return past_universe[x][y]; }
//void Universe::setLocation(int x, int y, int valeur){ universe[x][y] = valeur; }
//void Universe::setLocation_past(int x, int y, int valeur){ past_universe[x][y] = valeur; }
void Universe::setLocation(int x, int y, float valeur){ universe[x][y] = valeur; }
void Universe::setLocation_past(int x, int y, float valeur){ past_universe[x][y] = valeur; }

void Universe::display(sf::RenderWindow & appli)
{
	int side=DIM/10;

	appli.Clear(sf::Color::White);

	for(int i = 0 ; i < DIM ; i++){ for(int j = 0 ; j < DIM ; j++){ appli.Draw(sf::Shape::Rectangle(i*side, side*j, (i+1)*side, (j+1)*side, sf::Color(128*getLocation(i,j),0,0), 0, sf::Color::Black)); } }
	appli.Display();

}
