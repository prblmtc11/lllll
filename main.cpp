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
    p_t begin() const override;
    p_t next(p_t prev) const override;
    p_t d;
  };
}
int main() {
  using namespace loll; 
  p_t a{1, 1}, b{0, 1};
  std::cout << (a == b) << "\n";
}
topit::p_t loll::Dot::begin() const {
  return d;
}
topit:: p_t loll::Dot::next(p_t prev) const {
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
