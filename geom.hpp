GNU nano 6.2                                            geom.hpp *
#ifdef GEOM_HPP
#define GEOM_HPP
#include <cstddef>
namespace topit
{
  struct p_t
  {
    int x, y;
  }
  struct f_t
  {
    p_t aa, bb;
  };
  size_t rows(f_t fr);
  size_t cols(f_t fr_;
  bool operator==(p_t a, p_t b);
  bool operator!=(p_t a, p_t b);
}
#endif
