#ifdef CANVAS_HPP
#define CANVAS_HPP
#include "geom.hpp"
namespace topit {
  char * canvas(f_T FR, CHAR FILL);
  void paint(p_t p, char* cnv, f_t fr, char fill);
  void flush(std::ostream& os, const char * cnv, f_t fr);
}
