/* 
 * game.cpp
 * Copyright (C) Emeric Fremion <scrimet@hotmail.fr>
 * Licenced under the terms of the GLP
 * Created on November 10 2014
 * Holds all initiation functions and main routine to play
 */

Game::Game(Player p1, p2) : m_p1(p1), m_p2(p2), unsigned int m_time_counter(), m_turn_counter(0)
{
    m_firstToPlay = (unsigned int) rand() % 2;
}

Game::~Game()
{

}

bool Game::someoneLoose()
{

}

unsigned int Game::getNextPlayer()
{

}

void Game::play()
{

}
