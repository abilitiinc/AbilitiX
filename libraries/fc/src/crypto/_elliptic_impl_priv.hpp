#pragma once
#include <fc/crypto/elliptic.hpp>

/* private_key_impl based on libsecp256k1
 * used by mixed + secp256k1
 */

namespace fc { namespace ecc { namespace detail {

void _init_lib();

class private_key_impl
{
    public:
        private_key_impl() noexcept;
        private_key_impl( const private_key_impl& cpy ) noexcept;

        private_key_impl& operator=( const private_key_impl& pk ) noexcept;

        private_key_secret _key;
};

}}}
