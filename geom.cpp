#include "geom.hpp"
bool top::operator==(p_t a, p_t b) {  
return a.x == b.x && a.y == b.y;}bool top::operator!=(p_t a, p_t b) {  
return !(a == b);}size_t top::rows(f_t fr){ 
return fr.bb.y - fr.aa.y + 1;}s
i
ze_t top::cols(f_t fr){ 
 
return fr.bb.x - fr.aa.x + 1;}
