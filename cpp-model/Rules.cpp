#include "Rules.h"

Rules::Rules(void)
:can_capture_teammates_(false)
{

}

Rules::~Rules(void)
{
}

bool operator ==(const Rules &lhs, const Rules &rhs)
{
    // TODO: compare other rules when added
    return (lhs.can_capture_teammates() == rhs.can_capture_teammates());
}
