#include "blockpass.hpp"

void blockpass::add(name owner, string data, uint64_t timestamp)
{
    require_recipient(owner);
    require_auth(owner);

    notes nt(_self, owner.value);
    auto lookup = nt.find(owner.value);

    if (lookup != nt.end()) {
        nt.modify(lookup, owner, [&](auto& n) {
            n.data = data;
            n.timestamp = timestamp;
        });

    } else {
        nt.emplace(owner, [&](auto& n) {
            n.owner = owner;
            n.data = data;
            n.timestamp = timestamp;
        });
    }
    
}

void blockpass::del(name owner)
{
    require_recipient(owner);
    require_auth(owner);

    check(_self == owner, "must be owner of this data");

    notes nt(_self, owner.value);
    auto lookup = nt.find(owner.value);
    nt.erase(lookup);

}

EOSIO_DISPATCH(blockpass, (add) (del))