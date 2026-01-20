#ifndef DOT_HPP
#define DOT_HPP
namespace topit {
struct Dot: IDraw {
    explicit Dot(p_t dd);
    p_t begin() const override;
    p_t next(p_t prev) const override;
    p_t d;
  };
}
#endif
