#include <sophiatx/protocol/get_config.hpp>
#include <sophiatx/protocol/config.hpp>
#include <sophiatx/protocol/asset.hpp>
#include <sophiatx/protocol/types.hpp>
#include <sophiatx/protocol/version.hpp>

namespace sophiatx { namespace protocol {

fc::variant_object get_config()
{
   fc::mutable_variant_object result;

#ifdef IS_TEST_NET
   result["IS_TEST_NET"] = true;
#else
   result["IS_TEST_NET"] = false;
#endif

#if 0
    // do not expose private key, period.
    // we need this line present but inactivated so CI check for all constants in config.hpp doesn't complain.
    // result["SOPHIATX_INIT_PRIVATE_KEY"] = SOPHIATX_INIT_PRIVATE_KEY;
#endif

    result["SOPHIATX_BLOCKCHAIN_VERSION"] = SOPHIATX_BLOCKCHAIN_VERSION;
    result["SOPHIATX_INIT_PUBLIC_KEY_STR"] = SOPHIATX_INIT_PUBLIC_KEY_STR;
    result["SOPHIATX_MIN_ACCOUNT_CREATION_FEE"] = SOPHIATX_MIN_ACCOUNT_CREATION_FEE;
    result["SOPHIATX_OWNER_AUTH_RECOVERY_PERIOD"] = SOPHIATX_OWNER_AUTH_RECOVERY_PERIOD;
    result["SOPHIATX_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD"] = SOPHIATX_ACCOUNT_RECOVERY_REQUEST_EXPIRATION_PERIOD;
    result["SOPHIATX_OWNER_UPDATE_LIMIT"] = SOPHIATX_OWNER_UPDATE_LIMIT;
    result["SOPHIATX_INIT_SUPPLY"] = SOPHIATX_INIT_SUPPLY;
    result["SOPHIATX_TOTAL_SUPPLY"] = SOPHIATX_TOTAL_SUPPLY;
    result["SOPHIATX_MIN_FEEDS"] = SOPHIATX_MIN_FEEDS;
    result["SOPHIATX_ADDRESS_PREFIX"] = SOPHIATX_ADDRESS_PREFIX;
    result["SOPHIATX_GENESIS_TIME"] = SOPHIATX_GENESIS_TIME;
    result["SOPHIATX_BLOCK_INTERVAL"] = SOPHIATX_BLOCK_INTERVAL;
    result["SOPHIATX_BLOCKS_PER_YEAR"] = SOPHIATX_BLOCKS_PER_YEAR;
    result["SOPHIATX_BLOCKS_PER_DAY"] = SOPHIATX_BLOCKS_PER_DAY;
    result["SOPHIATX_START_VESTING_BLOCK"] = SOPHIATX_START_VESTING_BLOCK;
    result["SOPHIATX_START_MINER_VOTING_BLOCK"] = SOPHIATX_START_MINER_VOTING_BLOCK;
    result["SOPHIATX_DECIMALS"] = SOPHIATX_DECIMALS;
    result["SOPHIATX_SATOSHIS"] = SOPHIATX_SATOSHIS;
    result["SOPHIATX_PROMOTION_POOL_PERCENTAGE"] = SOPHIATX_PROMOTION_POOL_PERCENTAGE;
    result["SOPHIATX_MINING_POOL_PERCENTAGE"] = SOPHIATX_MINING_POOL_PERCENTAGE;
    result["SOPHIATX_INTEREST_POOL_PERCENTAGE"] = SOPHIATX_INTEREST_POOL_PERCENTAGE;
    result["SOPHIATX_BURN_FEE_PERCENTAGE"] = SOPHIATX_BURN_FEE_PERCENTAGE;
    result["SOPHIATX_INTEREST_BLOCKS"] = SOPHIATX_INTEREST_BLOCKS;
    result["SOPHIATX_INTEREST_FEES_TIME"] = SOPHIATX_INTEREST_FEES_TIME;
    result["SOPHIATX_INTEREST_DELAY"] = SOPHIATX_INTEREST_DELAY;
    result["SOPHIATX_COINBASE_YEARS"] = SOPHIATX_COINBASE_YEARS;
    result["SOPHIATX_COINBASE_BLOCKS"] = SOPHIATX_COINBASE_BLOCKS;

    result["SOPHIATX_FINAL_WITNESS_REQUIRED_VESTING_BALANCE"] = SOPHIATX_FINAL_WITNESS_REQUIRED_VESTING_BALANCE;
    result["SOPHIATX_WITNESS_VESTING_INCREASE_DAYS"] = SOPHIATX_WITNESS_VESTING_INCREASE_DAYS;
    result["SOPHIATX_INITIAL_WITNESS_REQUIRED_VESTING_BALANCE"] = SOPHIATX_INITIAL_WITNESS_REQUIRED_VESTING_BALANCE;

    result["VESTS_SYMBOL"] = VESTS_SYMBOL;
    result["SOPHIATX_SYMBOL"] = SOPHIATX_SYMBOL;
    result["SBD1_SYMBOL"] = SBD1_SYMBOL;
    result["SBD2_SYMBOL"] = SBD2_SYMBOL;
    result["SBD3_SYMBOL"] = SBD3_SYMBOL;
    result["SBD4_SYMBOL"] = SBD4_SYMBOL;
    result["SBD5_SYMBOL"] = SBD5_SYMBOL;
    result["BASE_FEE"] = BASE_FEE;
    result["BASE_FEE_SBD1"] = BASE_FEE_SBD1;
    result["BASE_FEE_SBD2"] = BASE_FEE_SBD2;
    result["BASE_FEE_SBD3"] = BASE_FEE_SBD3;
    result["BASE_FEE_SBD4"] = BASE_FEE_SBD4;
    result["BASE_FEE_SBD5"] = BASE_FEE_SBD5;
    result["SIZE_COVERED_IN_BASE_FEE"] = SIZE_COVERED_IN_BASE_FEE;
    result["SIZE_INCREASE_PER_FEE"] = SIZE_INCREASE_PER_FEE;
    result["SOPHIATX_BLOCKCHAIN_HARDFORK_VERSION"] = SOPHIATX_BLOCKCHAIN_HARDFORK_VERSION;
    result["SOPHIATX_INIT_MINER_NAME"] = SOPHIATX_INIT_MINER_NAME;
    result["SOPHIATX_NUM_INIT_MINERS"] = SOPHIATX_NUM_INIT_MINERS;
    result["SOPHIATX_INIT_TIME"] = SOPHIATX_INIT_TIME;
    result["SOPHIATX_MAX_WITNESSES"] = SOPHIATX_MAX_WITNESSES;
    result["SOPHIATX_MAX_VOTED_WITNESSES_HF0"] = SOPHIATX_MAX_VOTED_WITNESSES_HF0;
    result["SOPHIATX_MAX_MINER_WITNESSES_HF0"] = SOPHIATX_MAX_MINER_WITNESSES_HF0;
    result["SOPHIATX_MAX_RUNNER_WITNESSES_HF0"] = SOPHIATX_MAX_RUNNER_WITNESSES_HF0;
    result["SOPHIATX_HARDFORK_REQUIRED_WITNESSES"] = SOPHIATX_HARDFORK_REQUIRED_WITNESSES;
    result["SOPHIATX_MAX_TIME_UNTIL_EXPIRATION"] = SOPHIATX_MAX_TIME_UNTIL_EXPIRATION;
    result["SOPHIATX_MAX_MEMO_SIZE"] = SOPHIATX_MAX_MEMO_SIZE;
    result["SOPHIATX_MAX_NAME_SEED_SIZE"] = SOPHIATX_MAX_NAME_SEED_SIZE;
    result["SOPHIATX_MAX_PROXY_RECURSION_DEPTH"] = SOPHIATX_MAX_PROXY_RECURSION_DEPTH;
    result["SOPHIATX_VESTING_WITHDRAW_INTERVALS"] = SOPHIATX_VESTING_WITHDRAW_INTERVALS;
    result["SOPHIATX_VESTING_WITHDRAW_INTERVAL_SECONDS"] = SOPHIATX_VESTING_WITHDRAW_INTERVAL_SECONDS;
    result["SOPHIATX_VOTE_REGENERATION_SECONDS"] = SOPHIATX_VOTE_REGENERATION_SECONDS;
    result["SOPHIATX_MAX_VOTE_CHANGES"] = SOPHIATX_MAX_VOTE_CHANGES;
    result["SOPHIATX_REVERSE_AUCTION_WINDOW_SECONDS"] = SOPHIATX_REVERSE_AUCTION_WINDOW_SECONDS;
    result["SOPHIATX_MIN_VOTE_INTERVAL_SEC"] = SOPHIATX_MIN_VOTE_INTERVAL_SEC;
    result["SOPHIATX_VOTE_DUST_THRESHOLD"] = SOPHIATX_VOTE_DUST_THRESHOLD;
    result["SOPHIATX_MIN_REPLY_INTERVAL"] = SOPHIATX_MIN_REPLY_INTERVAL;
    result["SOPHIATX_POST_AVERAGE_WINDOW"] = SOPHIATX_POST_AVERAGE_WINDOW;
    result["SOPHIATX_POST_WEIGHT_CONSTANT"] = SOPHIATX_POST_WEIGHT_CONSTANT;
    result["SOPHIATX_MAX_ACCOUNT_WITNESS_VOTES"] = SOPHIATX_MAX_ACCOUNT_WITNESS_VOTES;
    result["SOPHIATX_100_PERCENT"] = SOPHIATX_100_PERCENT;
    result["SOPHIATX_1_PERCENT"] = SOPHIATX_1_PERCENT;
    result["SOPHIATX_MINER_PAY_PERCENT"] = SOPHIATX_MINER_PAY_PERCENT;
    result["SOPHIATX_MAX_RATION_DECAY_RATE"] = SOPHIATX_MAX_RATION_DECAY_RATE;
    result["SOPHIATX_LIMIT_BANDWIDTH_BLOCKS"] = SOPHIATX_LIMIT_BANDWIDTH_BLOCKS;
    result["SOPHIATX_MAX_ALLOWED_BANDWIDTH"] = SOPHIATX_MAX_ALLOWED_BANDWIDTH;
    result["SOPHIATX_MAX_ALLOWED_OPS_COUNT"] = SOPHIATX_MAX_ALLOWED_OPS_COUNT;
    result["SOPHIATX_CREATE_ACCOUNT_DELEGATION_RATIO"] = SOPHIATX_CREATE_ACCOUNT_DELEGATION_RATIO;
    result["SOPHIATX_CREATE_ACCOUNT_DELEGATION_TIME"] = SOPHIATX_CREATE_ACCOUNT_DELEGATION_TIME;
    result["SOPHIATX_MINING_REWARD"] = SOPHIATX_MINING_REWARD;
    result["SOPHIATX_ACTIVE_CHALLENGE_FEE"] = SOPHIATX_ACTIVE_CHALLENGE_FEE;
    result["SOPHIATX_OWNER_CHALLENGE_FEE"] = SOPHIATX_OWNER_CHALLENGE_FEE;
    result["SOPHIATX_ACTIVE_CHALLENGE_COOLDOWN"] = SOPHIATX_ACTIVE_CHALLENGE_COOLDOWN;
    result["SOPHIATX_OWNER_CHALLENGE_COOLDOWN"] = SOPHIATX_OWNER_CHALLENGE_COOLDOWN;
    result["SOPHIATX_APR_PERCENT_MULTIPLY_PER_BLOCK"] = SOPHIATX_APR_PERCENT_MULTIPLY_PER_BLOCK;
    result["SOPHIATX_APR_PERCENT_SHIFT_PER_BLOCK"] = SOPHIATX_APR_PERCENT_SHIFT_PER_BLOCK;
    result["SOPHIATX_APR_PERCENT_MULTIPLY_PER_ROUND"] = SOPHIATX_APR_PERCENT_MULTIPLY_PER_ROUND;
    result["SOPHIATX_APR_PERCENT_SHIFT_PER_ROUND"] = SOPHIATX_APR_PERCENT_SHIFT_PER_ROUND;
    result["SOPHIATX_APR_PERCENT_MULTIPLY_PER_HOUR"] = SOPHIATX_APR_PERCENT_MULTIPLY_PER_HOUR;
    result["SOPHIATX_APR_PERCENT_SHIFT_PER_HOUR"] = SOPHIATX_APR_PERCENT_SHIFT_PER_HOUR;
    result["SOPHIATX_MIN_ACCOUNT_NAME_LENGTH"] = SOPHIATX_MIN_ACCOUNT_NAME_LENGTH;
    result["SOPHIATX_MAX_ACCOUNT_NAME_LENGTH"] = SOPHIATX_MAX_ACCOUNT_NAME_LENGTH;
    result["SOPHIATX_MIN_PERMLINK_LENGTH"] = SOPHIATX_MIN_PERMLINK_LENGTH;
    result["SOPHIATX_MAX_PERMLINK_LENGTH"] = SOPHIATX_MAX_PERMLINK_LENGTH;
    result["SOPHIATX_MAX_WITNESS_URL_LENGTH"] = SOPHIATX_MAX_WITNESS_URL_LENGTH;
    result["SOPHIATX_MAX_SHARE_SUPPLY"] = SOPHIATX_MAX_SHARE_SUPPLY;
    result["SOPHIATX_MAX_SATOSHIS"] = SOPHIATX_MAX_SATOSHIS;
    result["SOPHIATX_MAX_SIG_CHECK_DEPTH"] = SOPHIATX_MAX_SIG_CHECK_DEPTH;
    result["SOPHIATX_MIN_TRANSACTION_SIZE_LIMIT"] = SOPHIATX_MIN_TRANSACTION_SIZE_LIMIT;
    result["SOPHIATX_SECONDS_PER_YEAR"] = SOPHIATX_SECONDS_PER_YEAR;
    result["SOPHIATX_MAX_TRANSACTION_SIZE"] = SOPHIATX_MAX_TRANSACTION_SIZE;
    result["SOPHIATX_MIN_BLOCK_SIZE_LIMIT"] = SOPHIATX_MIN_BLOCK_SIZE_LIMIT;
    result["SOPHIATX_MAX_BLOCK_SIZE"] = SOPHIATX_MAX_BLOCK_SIZE;
    result["SOPHIATX_SOFT_MAX_BLOCK_SIZE"] = SOPHIATX_SOFT_MAX_BLOCK_SIZE;
    result["SOPHIATX_MIN_BLOCK_SIZE"] = SOPHIATX_MIN_BLOCK_SIZE;
    result["SOPHIATX_BLOCKS_PER_HOUR"] = SOPHIATX_BLOCKS_PER_HOUR;
    result["SOPHIATX_FEED_INTERVAL_BLOCKS"] = SOPHIATX_FEED_INTERVAL_BLOCKS;
    result["SOPHIATX_FEED_HISTORY_WINDOW"] = SOPHIATX_FEED_HISTORY_WINDOW;
    result["SOPHIATX_MAX_FEED_AGE_SECONDS"] = SOPHIATX_MAX_FEED_AGE_SECONDS;
    result["SOPHIATX_MIN_UNDO_HISTORY"] = SOPHIATX_MIN_UNDO_HISTORY;
    result["SOPHIATX_MAX_UNDO_HISTORY"] = SOPHIATX_MAX_UNDO_HISTORY;
    result["SOPHIATX_MIN_TRANSACTION_EXPIRATION_LIMIT"] = SOPHIATX_MIN_TRANSACTION_EXPIRATION_LIMIT;
    result["SOPHIATX_BLOCKCHAIN_PRECISION"] = SOPHIATX_BLOCKCHAIN_PRECISION;
    result["SOPHIATX_BLOCKCHAIN_PRECISION_DIGITS"] = SOPHIATX_BLOCKCHAIN_PRECISION_DIGITS;
    result["SOPHIATX_MAX_INSTANCE_ID"] = SOPHIATX_MAX_INSTANCE_ID;
    result["SOPHIATX_MAX_AUTHORITY_MEMBERSHIP"] = SOPHIATX_MAX_AUTHORITY_MEMBERSHIP;
    result["SOPHIATX_MAX_ASSET_WHITELIST_AUTHORITIES"] = SOPHIATX_MAX_ASSET_WHITELIST_AUTHORITIES;
    result["SOPHIATX_MAX_URL_LENGTH"] = SOPHIATX_MAX_URL_LENGTH;
    result["SOPHIATX_IRREVERSIBLE_THRESHOLD"] = SOPHIATX_IRREVERSIBLE_THRESHOLD;
    result["SOPHIATX_VIRTUAL_SCHEDULE_LAP_LENGTH"] = SOPHIATX_VIRTUAL_SCHEDULE_LAP_LENGTH;
    result["SOPHIATX_VIRTUAL_SCHEDULE_LAP_LENGTH2"] = SOPHIATX_VIRTUAL_SCHEDULE_LAP_LENGTH2;
    result["SOPHIATX_MINER_ACCOUNT"] = SOPHIATX_MINER_ACCOUNT;
    result["SOPHIATX_NULL_ACCOUNT"] = SOPHIATX_NULL_ACCOUNT;
    result["SOPHIATX_TEMP_ACCOUNT"] = SOPHIATX_TEMP_ACCOUNT;
    result["SOPHIATX_PROXY_TO_SELF_ACCOUNT"] = SOPHIATX_PROXY_TO_SELF_ACCOUNT;
    result["SOPHIATX_ROOT_POST_PARENT"] = SOPHIATX_ROOT_POST_PARENT;

    return result;
}

} } // sophiatx::protocol
