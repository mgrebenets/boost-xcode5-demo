#pragma once

#include <boost/type_traits.hpp>

#include "Player.h"
#include "Rules.h"

#include <fstream>

#include <boost/serialization/access.hpp>
#include <boost/serialization/split_member.hpp>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/string.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>

using std::vector;
using std::string;

class Game
{    
public:

    Game(void);
    ~Game(void);

    friend bool operator ==(const Game &lhs, const Game &rhs);
    friend inline bool operator !=(const Game &lhs, const Game &rhs) { return !(lhs == rhs); }

    const vector <Player> &get_players(void) const { return players_; }

    const Rules &get_rules(void) const { return rules_; }
    Rules &get_rules(void) { return rules_; }
    
    /* round */
    int get_round(void) const { return round_; }
    void set_round(int round) { round_ = round; }

protected:

    Rules rules_;
    vector< Player > players_;
    int round_;

    // serialization
    friend class boost::serialization::access;

    template<class Archive>
    void serialize_common(Archive &ar, const unsigned int version) {
        
        ar & BOOST_SERIALIZATION_NVP(players_);
        ar & BOOST_SERIALIZATION_NVP(round_);
        ar & BOOST_SERIALIZATION_NVP(rules_);
    }
    
    BOOST_SERIALIZATION_SPLIT_MEMBER()
    
    template<class Archive>
    void save(Archive &ar, const unsigned int version) const {
        const_cast<Game *>(this)->serialize_common(ar, version);
    }
    
    template<class Archive>
    void load(Archive &ar, const unsigned int version) {
        serialize_common(ar, version);
        
        // TODO: some custom stuff, like recreating things
        // that should are not serialized due to overhead
    }
    
public:
    bool SaveGame(const char *filename) {
        std::ofstream ofs(filename);
        boost::archive::xml_oarchive oa(ofs);
        Game *thisGame = this;
        oa << BOOST_SERIALIZATION_NVP(thisGame);
        ofs.close();
        // TODO: return false if fails
        return true;
    }
    
    static Game *LoadGame(const char *filename) {
        std::ifstream ifs(filename);
        boost::archive::xml_iarchive ia(ifs);
        Game *g = new Game();
        ia >> BOOST_SERIALIZATION_NVP(*g);
        ifs.close();
        return g;
    }

    
};
