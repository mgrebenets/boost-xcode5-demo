#pragma once

#include "Move.h"

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>

enum {
    kPlayerTypeUser,
    kPlayerTypePeer,
    kPlayerTypeAI
};

enum {
    kPlayerStateNotReady,
    kPlayerStateReady,
};

#define player_type_key     "player_type"
#define ai_level_key        "ai_level"

class Player
{
public:
    Player(int player_id = 0, int team_id = -1);
    ~Player(void);
    
    /* operators */
    friend bool operator ==(const Player &lhs, const Player &rhs);
    friend inline bool operator !=(const Player &lhs, const Player &rhs) { return !(lhs == rhs); }
    
    int get_player_type(void) const { return player_type_; }
    void set_player_type(int player_type) { player_type_ = player_type; }
    bool IsUser(void) const { return IsHuman() && (player_type_ == kPlayerTypeUser); }
    bool IsAI(void) const { return player_type_ == kPlayerTypeAI; }
    bool IsPeer(void) const { return player_type_ == kPlayerTypePeer; }
    bool IsHuman(void) const { return !IsAI(); }
    bool IsLocal(void) const { return IsUser(); }
    bool IsRemote(void) const { return IsPeer(); }
    // local/remote?
    

    int get_player_id(void) const { return player_id_; }
    
    int get_team_id(void) const { return team_id_; }
    void set_team_id(int team_id) { team_id_ = team_id; }
    bool IsSameTeam(const Player &player) const { return team_id_ == player.get_team_id(); }

    int get_player_state(void) const { return player_state_; }
    void set_player_state(int player_state) { player_state_ = player_state; }
    bool IsReady(void) const { return (player_state_ == kPlayerStateReady); }
    bool IsConnected(void) const { return IsReady(); }
    bool IsDisconnected(void) const { return (player_state_ == kPlayerStateNotReady); }

    bool IsOut(void) const { return !score_; }
    
    bool is_zombie(void) const { return is_zombie_; }
    void set_is_zombie(bool zombie) { is_zombie_ = zombie; }
        
    int get_level(void) const { return level_; }
    void set_level(int level) { level_ = level; }
    
    int get_score(void) const { return score_; }
    void set_score(int score) { score_ = score; }
    
    int get_game_points(void) const { return game_points_; }
    void set_game_points(int game_points) { game_points_ = game_points; }
    
    int get_score_delta(void) const { return score_delta_; }
    void set_score_delta(int score_delta) { score_delta_ = score_delta; }
    
    Move GetMove(void);
        
private:
    int player_type_;
    int player_id_;
    int team_id_;
    int player_state_; // player state
    int level_; // player level (rank/experience)
    int score_;    // player score (generally same as no. of pieces)
    int game_points_;    // game points (no. of rounds won or left to lose)
    bool is_zombie_;
    int score_delta_; // score delta after last move
    
    // serialization
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(player_id_);
        ar & BOOST_SERIALIZATION_NVP(player_type_);
        ar & BOOST_SERIALIZATION_NVP(team_id_);
        ar & BOOST_SERIALIZATION_NVP(player_state_);
        ar & BOOST_SERIALIZATION_NVP(level_);
        ar & BOOST_SERIALIZATION_NVP(score_);
        ar & BOOST_SERIALIZATION_NVP(game_points_);
        ar & BOOST_SERIALIZATION_NVP(is_zombie_);
        ar & BOOST_SERIALIZATION_NVP(score_delta_);
    }
    
};
