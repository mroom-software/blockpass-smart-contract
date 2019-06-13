# version
cmake_minimum_required(VERSION 3.5)

# project
project(blockpass VERSION 1.0.0)

find_package(eosio.cdt)

add_contract( blockpass blockpass blockpass.cpp )