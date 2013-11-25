#pragma once

#include <boost/serialization/access.hpp>
#include <boost/serialization/nvp.hpp>

class Rules
{
public:
    Rules(void);
    ~Rules(void);

    /* operators */
    friend bool operator ==(const Rules &lhs, const Rules &rhs);
    friend inline bool operator !=(const Rules &lhs, const Rules &rhs) { return !(lhs == rhs); }

    bool can_capture_teammates(void) const { return can_capture_teammates_; }
    void set_can_capture_teammates(bool val) { can_capture_teammates_ = val; }
    
private:
    bool can_capture_teammates_;
    
    // serialization
    friend class boost::serialization::access;
    template <class Archive>
    void serialize(Archive &ar, const unsigned int version) {
        ar & BOOST_SERIALIZATION_NVP(can_capture_teammates_);
    }
};
