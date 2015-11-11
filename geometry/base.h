#ifndef GEOMETRY_BASE_H_
#define GEOMETRY_BASE_H_

// Class that represent 2D point. Can also represent a vector where
// starts at origin.
class Point final {
 public:
  Point() = default;
  Point(double x, double y);
  // Distance to origin.
  double Norm() const;
  // Return true if this point is clockwise to point o.
  bool IsClockwiseTo(const Point& o) const;
  // Return true if this point is counter-clockwise to point o.
  bool IsCounterClockwiseTo(const Point& o) const;
  // Return true if this point is on the same line with point o.
  bool IsCollinearTo(const Point& o) const;
  // Access dimension values.
  double x() const;
  double y() const;

 private:
  double x_;
  double y_;
};

// Sum of vector <(0,0)->A> and vector <(0,0)->B>.
Point operator+(const Point& A, const Point& B);
// Difference of vector <(0,0)->A> and vector <(0,0)->B>.
Point operator-(const Point& A, const Point& B);
// Dot product of vector <(0,0)->A> and vector <(0,0)->B>.
double operator^(const Point& A, const Point& B);
// Cross product of vector <(0,0)->A> and vector <(0,0)->B>.
double operator*(const Point& A, const Point& B);

#endif  // GEOMETRY_BASE_H_
