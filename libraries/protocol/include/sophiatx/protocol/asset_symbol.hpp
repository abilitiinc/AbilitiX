#pragma once

#include <fc/io/raw.hpp>
#include <sophiatx/protocol/types_fwd.hpp>

#define VESTS_SYMBOL_U64  (uint64_t('V') | (uint64_t('E') << 8) | (uint64_t('S') << 16) | (uint64_t('T') << 24) | (uint64_t('S') << 32))
#define SOPHIATX_SYMBOL_U64  (uint64_t('S') | (uint64_t('P') << 8) | (uint64_t('H') << 16) | (uint64_t('T') << 24) | (uint64_t('X') << 32))
#define SBD1_SYMBOL_U64    (uint64_t('U') | (uint64_t('S') << 8) | (uint64_t('D') << 16) )
#define SBD2_SYMBOL_U64    (uint64_t('E') | (uint64_t('U') << 8) | (uint64_t('R') << 16) )
#define SBD3_SYMBOL_U64    (uint64_t('C') | (uint64_t('H') << 8) | (uint64_t('F') << 16) )
#define SBD4_SYMBOL_U64    (uint64_t('C') | (uint64_t('N') << 8) | (uint64_t('Y') << 16) )
#define SBD5_SYMBOL_U64    (uint64_t('G') | (uint64_t('B') << 8) | (uint64_t('P') << 16) )


#define VESTS_SYMBOL_SER  (VESTS_SYMBOL_U64) ///< VESTS|VESTS with 6 digits of precision
#define SOPHIATX_SYMBOL_SER  (SOPHIATX_SYMBOL_U64) ///< SPHTX|TESTS with 6 digits of precision
#define SBD1_SYMBOL_SER    (SBD1_SYMBOL_U64)  
#define SBD2_SYMBOL_SER    (SBD2_SYMBOL_U64)  
#define SBD3_SYMBOL_SER    (SBD3_SYMBOL_U64) 
#define SBD4_SYMBOL_SER    (SBD4_SYMBOL_U64) 
#define SBD5_SYMBOL_SER    (SBD5_SYMBOL_U64)

#define SOPHIATX_ASSET_MAX_DECIMALS 6

namespace sophiatx { namespace protocol {

  class asset_symbol_type
  {
  public:
     uint64_t value = SOPHIATX_SYMBOL_SER;
  public:
     asset_symbol_type() {}
     asset_symbol_type(uint64_t v): value(v) {}
     asset_symbol_type(const asset_symbol_type& as){value = as.value;}

     static asset_symbol_type from_string( const std::string& str ){
        FC_ASSERT((str.size() >= 3 && str.size() <= 6), "invalid symbol length");
       const char* c_str = str.c_str();
       uint64_t ret = 0;
       int i = str.size();
       while( i-- ){
          ret = (ret << 8) | uint64_t(c_str[i]);
       }
       asset_symbol_type rv (ret) ;
       return rv;
     }

     std::string to_string()const{
       std::string ret;
       uint64_t symbol = value;
       while ( symbol ) {
         ret.push_back(symbol & (uint64_t(255)));
         symbol = symbol >> 8;
       }
       FC_ASSERT((ret.size() >= 3), "invalid symbol length");
       return ret;
     }

     uint8_t decimals()const{ return SOPHIATX_DECIMALS; };

     friend bool operator == ( const asset_symbol_type& a, const asset_symbol_type& b )
     {  return (a.value == b.value);   }
     friend bool operator != ( const asset_symbol_type& a, const asset_symbol_type& b )
     {  return (a.value != b.value);   }
     friend bool operator < ( const asset_symbol_type& a, const asset_symbol_type& b )
     {  return (a.value < b.value);    }
  };
/*
class asset_symbol_type
{
   public:

      asset_symbol_type() {}

      // buf must have space for SOPHIATX_ASSET_SYMBOL_MAX_LENGTH+1
      static asset_symbol_type from_string( const std::string& str );
      static asset_symbol_type from_asset_num( uint32_t asset_num )
      {   asset_symbol_type result;   result.asset_num = asset_num;   return result;   }

      std::string to_string()const;

      //Returns true when symbol represents vesting variant of the token, false for liquid one.
      bool is_vesting() const;
      //Returns vesting symbol when called from liquid one and liquid symbol when called from vesting one. Returns back the SBD symbol if represents SBD.

      asset_symbol_type get_paired_symbol() const;

      uint8_t decimals()const
      {  return uint8_t( asset_num & 0x0F );    }
      void validate()const;

      friend bool operator == ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num == b.asset_num);   }
      friend bool operator != ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num != b.asset_num);   }
      friend bool operator <  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <  b.asset_num);   }
      friend bool operator >  ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >  b.asset_num);   }
      friend bool operator <= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num <= b.asset_num);   }
      friend bool operator >= ( const asset_symbol_type& a, const asset_symbol_type& b )
      {  return (a.asset_num >= b.asset_num);   }

      uint32_t asset_num = 0;
};
*/
} } // sophiatx::protocol

FC_REFLECT(sophiatx::protocol::asset_symbol_type, (value))

/*
FC_REFLECT(sophiatx::protocol::asset_symbol_type, (asset_num))

namespace fc { namespace raw {

template< typename Stream >
inline void pack( Stream& s, const sophiatx::protocol::asset_symbol_type& sym )
{
   switch( sym.space() )
   {
      case sophiatx::protocol::asset_symbol_type::legacy_space:
      {
         uint64_t ser = 0;
         switch( sym.asset_num )
         {
            case SOPHIATX_ASSET_NUM_SOPHIATX:
               ser = SOPHIATX_SYMBOL_SER;
               break;
            case SOPHIATX_ASSET_NUM_SBD:
               ser = SBD_SYMBOL_SER;
               break;
            case SOPHIATX_ASSET_NUM_VESTS:
               ser = VESTS_SYMBOL_SER;
               break;
            default:
               FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
         }
         pack( s, ser );
         break;
      }
      case sophiatx::protocol::asset_symbol_type::smt_nai_space:
         pack( s, sym.asset_num );
         break;
      default:
         FC_ASSERT( false, "Cannot serialize unknown asset symbol" );
   }
}

template< typename Stream >
inline void unpack( Stream& s, sophiatx::protocol::asset_symbol_type& sym )
{
   uint64_t ser = 0;
   s.read( (char*) &ser, 4 );

   switch( ser )
   {
      case SOPHIATX_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == SOPHIATX_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = SOPHIATX_ASSET_NUM_SOPHIATX;
         break;
      case SBD_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == SBD_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = SOPHIATX_ASSET_NUM_SBD;
         break;
      case VESTS_SYMBOL_SER & 0xFFFFFFFF:
         s.read( ((char*) &ser)+4, 4 );
         FC_ASSERT( ser == VESTS_SYMBOL_SER, "invalid asset bits" );
         sym.asset_num = SOPHIATX_ASSET_NUM_VESTS;
         break;
      default:
         sym.asset_num = uint32_t( ser );
   }
   sym.validate();
}

} // fc::raw
*/
namespace fc{
inline void to_variant( const sophiatx::protocol::asset_symbol_type& sym, fc::variant& var )
{
   try
   {
      var = sym.to_string();
   } FC_CAPTURE_AND_RETHROW()
}

inline void from_variant( const fc::variant& var, sophiatx::protocol::asset_symbol_type& sym )
{
   try
   {
      sym = sophiatx::protocol::asset_symbol_type::from_string(var.as<std::string>());

   } FC_CAPTURE_AND_RETHROW()
}

} // fc
