# blockpass-smart-contract

## How to build:
- cd EOS/blockpass
- mkdir build
- cd build
- cmake ../
- make
- cp blockpass.abi blockpass.wasm ../

## How to deploy:
- cleos -u {eos_api_endpoint} set contract {contract_name} {path_to_eos_blockpass} -p {account_name}@active