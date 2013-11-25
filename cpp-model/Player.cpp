#include "Player.h"

Player::Player(int playerId, int teamId) {
    player_id_ = playerId;
    player_type_ = kPlayerTypeAI;
    team_id_ = (teamId < 0 ? playerId : teamId);    
    player_state_ = kPlayerStateReady;
    score_ = 0;
    level_ = 0;
    game_points_ = 0;
    is_zombie_ = false;
}

bool operator ==(const Player &lhs, const Player &rhs)
{
    return (lhs.get_player_id() == rhs.get_player_id()
            && lhs.get_player_type() == rhs.get_player_type()
            && lhs.get_player_state() == rhs.get_player_state()
            && lhs.get_team_id() == rhs.get_team_id()
            && lhs.get_level() == rhs.get_level()
            && lhs.get_score() == rhs.get_score()
            && lhs.get_game_points() == rhs.get_game_points()
            && lhs.is_zombie() == rhs.is_zombie()
            && lhs.get_score_delta() == rhs.get_score_delta());
}

Player::~Player(void)
{

}

Move Player::GetMove(void) {
    return Move();
}
