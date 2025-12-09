#include <iostream>

namespace loll {
  struct p_t {int x, y; };
  struct f_t {p_t aa, bb; };
  size_t rows(f_t fr);
  size_t cols(f_t fr);
  bool operator == (p_t a, p_t  b);
  bool operator!=(p_t a, p_t b);
  struct IDraw {
    virtual p_t begin() const = 0;
    virtual p_t next(p_t prev) const = 0;
    virtual ~IDraw() = default;
   };
  struct Dot: IDraw {
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t prev) const override;
    p_t d;
  };
  void extend(p_t** pts, size_t s, p_t fill);
  p_t* extend(const p_t* pts, size_t s, p_t fill);
  void append(const IDraw* sh, p_t** ppts, size_t& s);
  char * canvas(f_t fr, char fill);
  f_t frame(const p_t * pts, size_t s);
  void paint(p_t p, char * cnv, f_t fr, char fill);
  void flush(std::ostream& os, const char* cnv, f_t fr);
}
int main() {
  using namespace loll;
  int err = 0;
  IDraw* shp[3] = {};
  p_t * pts = nullptr;
  size_t s = 0;
  char* cnv = nullptr;
  f_t fr;
  try {
    shp[0] = new Dot({0, 0});
    shp[1] = new Dot({2,3});
    shp[2] = new Dot({-5, -2});
    p_t points[] = {{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}};
    s = 6;
    pts = new p_t[s];
    for (size_t i = 0; i < s; ++i) {
      pts[i] = points[i];
    }
    fr = frame(pts, s);
    cnv = canvas(fr, '.');
    for (size_t i = 0; i < 6; ++i) {
      paint(pts[i], cnv, fr, '#');
    }
    flush(std::cout, cnv, fr);
    delete [] cnv;
    delete [] pts;
  } catch (...) {
    std::cerr << "Error!\n";
    err = 1;
  }
  delete shp[0];
  delete shp[1];
  delete shp[2];
  return err;
}
loll::p_t* loll::extend(const p_t* pts, size_t s, p_t fill) {
  p_t* r = new p_t[s+1];
  for (size_t i = 0; i < s; ++i) {
    r[i] = pts[i];
  }
  r[s] = fill;
  return r;
}
void loll::extend(p_t** pts, size_t s, p_t fill) {
  p_t* r = extend(*pts, s, fill);
  delete [] *pts;
  ++s;
  *pts = r;
}
void loll::append(const IDraw* sh, p_t** ppts, size_t& s) {
  extend(ppts, s, sh->begin());
  p_t b = sh->begin();
  while (sh->next(b) != sh->begin()) {
    b = sh->next(b);
    extend(ppts,s,b);
  }
}
void loll::paint(p_t p, char * cnv, f_t fr, char fill) {
  size_t dx = p.x - fr.aa.x;
  size_t dy = fr.bb.y - p.y;
  cnv[dy * cols(fr) + dx] = fill;
}
void loll::flush(std::ostream& os, const char* cnv, f_t fr) {
  for (size_t i = 0; i < rows(fr); ++i) {
    for (size_t j = 0; j < cols(fr); ++j) {
      os << cnv[i * cols(fr) + j];
    }
    os << "\n";
  }
}
char * loll::canvas(f_t fr, char fill) {
  size_t s = rows(fr) * cols(fr);
  char * c = new char[rows(fr) * cols(fr)];
  for (size_t i = 0; i < s; ++i) {
    c[i] = fill;
  }
  return c;
}
loll::f_t loll::frame(const p_t* pts, size_t s)
{
  int minx = pts[0].x;
  int miny = pts[0].y;
  int maxx = minx, maxy = miny;
  for (size_t i = 1; i < s; ++i) {
    minx = std::min(minx, pts[i].x);
    miny = std::min(miny, pts[i].y);
    maxx = std::max(maxx, pts[i].x);
    maxy = std::max(maxy, pts[i].y);
  }
  p_t a{minx, miny};
  p_t b{maxx, maxy};
  return f_t{a, b};
}
loll::Dot::Dot(p_t dd):
  d{dd}
{}

loll::p_t loll::Dot::begin() const {
  return d;
}
loll::p_t loll::Dot::next(p_t prev) const {
  if (prev != d){
    throw std::logic_error("bad prev");
  }
  return d;
}
size_t loll::rows(f_t fr) {
  return (fr.bb.y - fr.aa.y + 1);
}
size_t loll::cols(f_t fr) {
  return (fr.bb.x - fr.aa.x + 1);
}
bool loll:: operator == (p_t a, p_t  b) {
  return a.x == b.x && a.y == b.y;
}
bool loll::operator!=(p_t a, p_t b) {
  return !(a == b);
}
