// Copyright (c) 2012-2017, The CryptoNote developers, The Bytecoin developers
// Copyright (c) 2023-2024, The CrownCoin Developers
//
// Please see the included LICENSE file for more information.

#pragma once

#include <cstdint>
#include <initializer_list>

namespace CryptoNote {
namespace parameters {

const uint64_t CRYPTONOTE_MAX_BLOCK_NUMBER                   = 500000000;
const size_t   CRYPTONOTE_MAX_BLOCK_BLOB_SIZE                = 500000000;
const size_t   CRYPTONOTE_MAX_TX_SIZE                        = 1000000000;
// Currency-specific address prefix
const uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX       = 0x4c9c;
// Choose maturity period for your currency (how long will coins be locked for after being mined).
const size_t   CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW          = 60;
const uint64_t CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT            = 60 * 60 * 2;

const size_t   BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW             = 60;

// Here we specify the total number of available coins, in terms of Atomic Units.
// Atomic Units = Total Coins + Display Decimal Point.
// Example:  You want a total of 5 million coins with 10 decimal points.
// Example:  Then set MONEY_SUPPLY as UINT64_C(50000000000000000).
// Note: ((uint64_t)(-1)) equals to 18446744073709551616 coins.
// Note: You can define number explicitly UINT64_C(858986905600000000).
const uint64_t MONEY_SUPPLY                                  = UINT64_C(3000000000000);
const size_t   CRYPTONOTE_DISPLAY_DECIMAL_POINT              = 4;

// Define minimum fee for transactions ( actual fee is MINIMUM_FEE / CRYPTONOTE_DISPLAY_DECIMAL_POINT )
// Example:  You want a minimum fee of 0.01, and have a total of 10 display decimal points.
// Example:  As 0.01 = ( 10000000 / 1000000000 ).  Then set MINIMUM_FEE = 10000000
const uint64_t MINIMUM_FEE                                   = 100;
const uint64_t DEFAULT_DUST_THRESHOLD                        = MINIMUM_FEE;

// Define preferred block's target time and emission speed
const uint64_t DIFFICULTY_TARGET                             = 60; // seconds
const unsigned EMISSION_SPEED_FACTOR                         = 22;
static_assert(EMISSION_SPEED_FACTOR <= 8 * sizeof(uint64_t), "Bad EMISSION_SPEED_FACTOR");

const uint64_t EXPECTED_NUMBER_OF_BLOCKS_PER_DAY             = 24 * 60 * 60 / DIFFICULTY_TARGET;

//TODO Define number of blocks for block size median calculation
const size_t   CRYPTONOTE_REWARD_BLOCKS_WINDOW               = 100;
const size_t   CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE     = 100000; //size of block (bytes) after which reward for block calculated using block size
const size_t   CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE        = 600;


//TODO There are options to tune CryptoNote's difficulty retargeting function.
//TODO We recommend not to change it.
const size_t   DIFFICULTY_WINDOW                             = EXPECTED_NUMBER_OF_BLOCKS_PER_DAY; // blocks
const size_t   DIFFICULTY_CUT                                = 60;  // timestamps to cut after sorting
const size_t   DIFFICULTY_LAG                                = 15;
static_assert(2 * DIFFICULTY_CUT <= DIFFICULTY_WINDOW - 2, "Bad DIFFICULTY_WINDOW or DIFFICULTY_CUT");

const size_t   MAX_BLOCK_SIZE_INITIAL                        =  20 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_NUMERATOR         = 100 * 1024;
const uint64_t MAX_BLOCK_SIZE_GROWTH_SPEED_DENOMINATOR       = 365 * 24 * 60 * 60 / DIFFICULTY_TARGET;

const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS     = 1;
const uint64_t CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS    = DIFFICULTY_TARGET * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS;

const uint64_t CRYPTONOTE_MEMPOOL_TX_LIVETIME                = 60 * 60 * 24;     //seconds, one day
const uint64_t CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME = 60 * 60 * 24 * 7; //seconds, one week
const uint64_t CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL = 7;  // CRYPTONOTE_NUMBER_OF_PERIODS_TO_FORGET_TX_DELETED_FROM_POOL * CRYPTONOTE_MEMPOOL_TX_LIVETIME = time to forget tx

const size_t   FUSION_TX_MAX_SIZE                            = CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE * 30 / 100;
const size_t   FUSION_TX_MIN_INPUT_COUNT                     = 12;
const size_t   FUSION_TX_MIN_IN_OUT_COUNT_RATIO              = 4;

const char     CRYPTONOTE_BLOCKS_FILENAME[]                  = "blocks.dat";
const char     CRYPTONOTE_BLOCKINDEXES_FILENAME[]            = "blockindexes.dat";
const char     CRYPTONOTE_BLOCKSCACHE_FILENAME[]             = "blockscache.dat";
const char     CRYPTONOTE_POOLDATA_FILENAME[]                = "poolstate.bin";
const char     P2P_NET_DATA_FILENAME[]                       = "p2pstate.bin";
const char     CRYPTONOTE_BLOCKCHAIN_INDICES_FILENAME[]      = "blockchainindices.dat";
const char     MINER_CONFIG_FILE_NAME[]                      = "miner_conf.json";
} // parameters

//TODO Put here the name of your currency
const char     CRYPTONOTE_NAME[]                             = "thecrowncoin";
const char     GENESIS_COINBASE_TX_HEX[]                     = "013c01ff0001f7d32b029b2e4c0281c0b02e7c53291a94d1d0cbff8883f8024f5142ee494ffbbd0880712101bdc0f59e08cabed4c635cdc1cd69dfb4f6dd72d26711a386dfa984aa7a4df20b";

const uint8_t  CURRENT_TRANSACTION_VERSION                   =  1;
const uint8_t  BLOCK_MAJOR_VERSION_1                         =  1;
const uint8_t  BLOCK_MINOR_VERSION_0                         =  0;

const size_t   BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT        =  10000;  //by default, blocks ids count in synchronizing
const size_t   BLOCKS_SYNCHRONIZING_DEFAULT_COUNT            =  200;    //by default, blocks count in blocks downloading
const size_t   COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT         =  1000;

//TODO This port will be used by the daemon to establish connections with p2p network
const int      P2P_DEFAULT_PORT                              = 50505;
//TODO This port will be used by the daemon to interact with simplewallet
const int      RPC_DEFAULT_PORT                              = 50005;

const size_t   P2P_LOCAL_WHITE_PEERLIST_LIMIT                =  1000;
const size_t   P2P_LOCAL_GRAY_PEERLIST_LIMIT                 =  5000;

const size_t   P2P_CONNECTION_MAX_WRITE_BUFFER_SIZE          = 16 * 1024 * 1024; // 16 MB
const uint32_t P2P_DEFAULT_CONNECTIONS_COUNT                 = 8;
const size_t   P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT     = 70;
const uint32_t P2P_DEFAULT_HANDSHAKE_INTERVAL                = 60;            // seconds
const uint32_t P2P_DEFAULT_PACKET_MAX_SIZE                   = 50000000;      // 50000000 bytes maximum packet size
const uint32_t P2P_DEFAULT_PEERS_IN_HANDSHAKE                = 250;
const uint32_t P2P_DEFAULT_CONNECTION_TIMEOUT                = 5000;          // 5 seconds
const uint32_t P2P_DEFAULT_PING_CONNECTION_TIMEOUT           = 2000;          // 2 seconds
const uint64_t P2P_DEFAULT_INVOKE_TIMEOUT                    = 60 * 2 * 1000; // 2 minutes
const size_t   P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT          = 5000;          // 5 seconds
const char     P2P_STAT_TRUSTED_PUB_KEY[]                    = "8f80f9a5a434a9f1510d13336228debfee9c918ce505efe225d8c94d045fa115";

//TODO Add here your network seed nodes
const std::initializer_list<const char*> SEED_NODES = {
  "13.78.134.123:50505",   //Azure Seed Node #1 - USA
  "51.12.211.212:50505",   //Azure Seed Node #2 - Europe
  "172.160.240.6:50505",   //Azure Seed Node #3 - Europe
  "4.255.145.145:50505",   //Azure Seed Node #4 - USA
  "5.196.71.153:50505",    //OVH Seed Node #1
  "37.187.118.119:50505"   //OVH Seed Node #2
};

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

#ifdef __GNUC__
__attribute__((unused))
#endif

// You may add here other checkpoints using the following format:
// {<block height>, "<block hash>"},
const std::initializer_list<CheckpointData> CHECKPOINTS = {
  //{ 10000, "84b6345731e2702cdaadc6ce5e5238c4ca5ecf48e3447136b2ed829b8a95f3ad" },
};
} // CryptoNote

#define ALLOW_DEBUG_COMMANDS
