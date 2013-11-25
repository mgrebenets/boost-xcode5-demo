#include "Move.h"
#include <boost/serialization/nvp.hpp>

Move::~Move(void)
{
}

bool operator ==(const Move &lhs, const Move &rhs) {
    return (lhs.get_from_vid() == rhs.get_from_vid()
            && lhs.get_to_vid() == rhs.get_to_vid());
}

template <class Archive>
void Move::serialize(Archive &ar, const unsigned int version) {
    ar & BOOST_SERIALIZATION_NVP(from_vid_);
    ar & BOOST_SERIALIZATION_NVP(to_vid_);
}