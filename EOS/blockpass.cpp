#include "blockpass.hpp"

void blockpass::add(name owner, string data)
{
    require_recipient(owner);
    require_auth(owner);
}

EOSIO_DISPATCH(blockpass, (add))