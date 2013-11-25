#include "Game.h"
#include "ModelMacro.h"


Game::Game(void)
:rules_(), round_(0)
{
	// put 2 default players
	players_.push_back(Player(static_cast<int>(players_.size())));
	players_.push_back(Player(static_cast<int>(players_.size())));
}

Game::~Game(void)
{
}

bool operator ==(const Game &lhs, const Game &rhs)
{
    return (lhs.get_rules() == rhs.get_rules()
            && lhs.get_players() == rhs.get_players()
            && lhs.get_round() == rhs.get_round());
}

