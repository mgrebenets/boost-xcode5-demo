#pragma once

#include <boost/serialization/access.hpp>

class Move
{
public:
    static Move SkipMove(void) { return Move(); }
public:
    Move(int from_vid = -1, int to_vid = -1) {
        from_vid_ = from_vid;
        to_vid_ = to_vid;
    }
    Move(const Move &move) { from_vid_ = move.get_from_vid(); to_vid_ = move.get_to_vid(); }
    ~Move(void);
    
    /* operators */
    friend bool operator ==(const Move &lhs, const Move &rhs);
    friend inline bool operator !=(const Move &lhs, const Move &rhs) { return !(lhs == rhs); }
    
    int get_from_vid(void) const { return from_vid_; }
    int get_to_vid(void) const  { return to_vid_; }
    bool IsDefined(void) const { return (from_vid_ >= 0 && to_vid_ >= 0); }
    //void printMove (void) { printf("(%d, %d)", from_vid_, to_vid_); }
    
private:
    int from_vid_;
    int to_vid_;
    
    // serialization
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version);

};
