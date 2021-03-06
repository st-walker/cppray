#ifndef RAY_TUPLE_HPP
#define RAY_TUPLE_HPP

#include <ostream>

namespace ray {
class Tuple;

double magnitude(Tuple const &);
Tuple unit(Tuple const &);
double dot(Tuple const &, Tuple const &);
Tuple cross(Tuple const &, Tuple const &);

class Tuple {
public:
  Tuple(double x, double y, double z, double w) : x_(x), y_(y), z_(z), w_(w) {}
  static Tuple vector(double x, double y, double z) {
    return Tuple(x, y, z, 0);
  }
  static Tuple point(double x, double y, double z) { return Tuple(x, y, z, 1); }

  double x() const { return x_; }
  double y() const { return y_; }
  double z() const { return z_; }
  double w() const { return w_; }

  void x(double x) {  x_ = x; }
  void y(double y) {  y_ = y; }
  void z(double z) {  z_ = z; }
  void w(double w) {  w_ = w; }

  bool is_point() { return w() == 1.0; }
  bool is_vector() { return w() == 0.0; }

  bool operator==(Tuple const &) const;
  Tuple operator+(Tuple const &) const;
  Tuple operator-(Tuple const &) const;
  Tuple operator-() const;
  Tuple operator*(double) const;
  friend Tuple operator*(double, Tuple const &);
  Tuple operator/(double) const;

  friend std::ostream &operator<<(std::ostream &os, Tuple const &);

private:
  double x_;
  double y_;
  double z_;
  double w_;
};

} // namespace ray

#endif /* RAY_TUPLE_HPP */
