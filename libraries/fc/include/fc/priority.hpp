#ifndef _FC_PRIORITY_HPP_
#define  _FC_PRIORITY_HPP_

namespace fc {
  /**
   *  An integer value used to sort asynchronous tasks.  The higher the
   *  prioirty the sooner it will be run.
   */
  class priority {
    public:
    explicit priority( int v = 0):value(v){}
    priority( const priority& p ):value(p.value){}
    bool operator < ( const priority& p )const {
       return value < p.value;
    }
    int value;
  };
}
#endif //  _FC_PRIORITY_HPP_
