/**
 *  @file
 *  @copyright defined in eos/LICENSE.txt
 */
#pragma once

#include <eosio/eosio.hpp>
#include <string>

using namespace std;
using namespace eosio;

class [[eosio::contract("blockpass")]] blockpass : public contract
{
public:
    using contract::contract;

    blockpass(name receiver, name code, datastream<const char*> ds):contract(receiver, code, ds) {

    }

    [[eosio::action]]
    void add(name owner, string notes);

private:
    struct [[eosio::table]] note
    {
        name owner;
        string data;
        uint64_t primary_key() const { return owner.value; }
    };

    typedef eosio::multi_index<"note"_n, note> notes;
};
