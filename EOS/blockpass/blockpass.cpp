#include "blockpass.hpp"

void blockpass::add(name owner, string data)
{
    require_recipient(owner);
    require_auth(owner);

    notes nt(_self, owner.value);
    auto lookup = nt.find(owner.value);

    if (lookup != nt.end()) {
        nt.modify(lookup, owner, [&](auto& n) {
            n.data = data;
        });

    } else {
        nt.emplace(owner, [&](auto& n) {
            n.owner = owner;
            n.data = data;
        });
    }
    
}

void blockpass::del(name owner)
{
    require_recipient(owner);
    require_auth(owner);

    notes nt(_self, owner.value);
    auto lookup = nt.find(owner.value);
    nt.erase(lookup);

}

EOSIO_DISPATCH(blockpass, (add) (del))