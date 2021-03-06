#pragma once

#include <sophiatx/protocol/types.hpp>

#include <sophiatx/protocol/operation_util.hpp>
#include <sophiatx/protocol/sophiatx_operations.hpp>
#include <sophiatx/protocol/sophiatx_virtual_operations.hpp>

namespace sophiatx { namespace protocol {

   /** NOTE: do not change the order of any operations prior to the virtual operations
    * or it will trigger a hardfork.
    */
   typedef fc::static_variant<

            transfer_operation,
            transfer_to_vesting_operation,
            withdraw_vesting_operation,
            feed_publish_operation,

            account_create_operation,
            account_update_operation,
            account_delete_operation,

            witness_update_operation,
            witness_stop_operation,
            account_witness_vote_operation,
            account_witness_proxy_operation,
            witness_set_properties_operation,


            custom_operation,
            custom_json_operation,
            custom_binary_operation,

            request_account_recovery_operation,
            recover_account_operation,
            change_recovery_account_operation,
            escrow_transfer_operation,
            escrow_dispute_operation,
            escrow_release_operation,
            escrow_approve_operation,

            reset_account_operation,
            set_reset_account_operation,

            application_create_operation,
            application_update_operation,
            application_delete_operation,
            buy_application_operation,
            cancel_application_buying_operation,
            transfer_from_promotion_pool_operation,
            sponsor_fees_operation,

            admin_witness_update_operation,
           /// virtual operations below this point

            interest_operation,
            fill_vesting_withdraw_operation,
            shutdown_witness_operation,
            hardfork_operation,
            producer_reward_operation,
            promotion_pool_withdraw_operation

         > operation;

   /*void operation_get_required_authorities( const operation& op,
                                            flat_set<string>& active,
                                            flat_set<string>& owner,
                                            flat_set<string>& posting,
                                            vector<authority>&  other );

   void operation_validate( const operation& op );*/

   bool is_virtual_operation( const operation& op );

   bool is_fee_free_operation( const operation& op );

} } // sophiatx::protocol

/*namespace fc {
    void to_variant( const sophiatx::protocol::operation& var,  fc::variant& vo );
    void from_variant( const fc::variant& var,  sophiatx::protocol::operation& vo );
}*/

SOPHIATX_DECLARE_OPERATION_TYPE( sophiatx::protocol::operation )
FC_REFLECT_TYPENAME( sophiatx::protocol::operation )
