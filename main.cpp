#include <iostream>
namespace loll {
  struct p_t {
    int x, y;
  };
  struct f_t {
    p_t aa, bb;
  };
  bool operator == (p_t a, p_t  b);
  bool operator!= (p_t a, p_t b);
  struct IDraw {
    virtual p_t next() const = 0;
    virtual p_t next(p_t prev) const = 0;
    virtual ~IDraw() = default;
   };
  struct Dot: IDraw {
    explicit  Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t prev) const override;
    p_t d;
  };
  void append(IDraw* sh, p_t** ppts, size_t& s);
}
int main() {
  using namespace loll;
  int err = 0;
  Idraw* shp[3] = {};
  p_t * pts = nellptr;
  site_t s = 0;
  try {
    shp[0] = new Dot ({0, 0});
    shp[1] = new Dot ({2, 3});
    for (size_t i = 0; i <3; ++i){
      append(shp[i], &pts, s);
    }
    catch (...) {
    std::cerr <, "Error!\n";
    err = 1;
  }
  delete shp[1]; 
  delete shp[0];
  return err;
}
loll:Dot::Dot::(p_t dd):
  IDRAW() 
{}
}
loll::p_t loll::Dot::next(p_t prev) const {
  if (prev != d){
    throw std::logic_error("bad prev");
  }
  return d;
}
bool loll:: operator == (p_t a, p_t  b) {
  return a.x == b.x && a.y == b.y;
}
bool loll::operator!= (p_t a, p_t b) {
  return !(a == b);
}
