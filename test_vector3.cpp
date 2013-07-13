// Tests for vector3.hpp

#include "vector3.hpp"

#include <iostream>
#include <cassert>

using namespace std;




// Simple printing function for vector3<T>
template <typename T>
ostream& operator << (ostream& out, vector3<T> v)
{
  out << "[" << v[0] << " " << v[1] << " " << v[2] << "]" << endl;
  return out;
}




int main(int argc, char* argv[])
{

  { // test default constructor
    vector3<double> v;

    assert(0 == v[0]);
    assert(0 == v[1]);
    assert(0 == v[2]);
  }

  { // test constructor
    vector3<double> v(1, 2, 3);

    assert(1 == v[0]);
    assert(2 == v[1]);
    assert(3 == v[2]);
  }

  { // test copy constructor
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(v1);

    assert(1 == v2[0]);
    assert(2 == v2[1]);
    assert(3 == v2[2]);
  }

  { // test zero
    vector3<double> v(1, 2, 3);
    v.zero();

    assert(0 == v[0]);
    assert(0 == v[1]);
    assert(0 == v[2]);
  }

  { // test set
    vector3<double> v;
    v.set(1, 2, 3);

    assert(1 == v[0]);
    assert(2 == v[1]);
    assert(3 == v[2]);
  }

  { // test normalize
    vector3<double> v(2, 0, 0);
    v.normalize();

    assert(1 == v[0]);
    assert(0 == v[1]);
    assert(0 == v[2]);
  }

  { // test norm
    vector3<double> v(2, 0, 0);

    assert(2 == v.norm());
  }

  { // test sum
    vector3<double> v(1, 2, 3);

    assert(6 == v.sum());
  }

  { // test dot
    vector3<double> v1(1, 1, 0);
    vector3<double> v2(1, 0, 1);

    assert(1 == v1.dot(v2));
  }

  { // test cross
    vector3<double> v1(1, 0, 0);
    vector3<double> v2(0, 1, 0);
    vector3<double> v3(0, 0, 1);

    assert(v3 == v1.cross(v2));
  }

  { // test abs
    vector3<double> v1(-1, -2, -3);
    vector3<double> v2(1, 2, 3);

    assert(v2 == v1.abs());
  }

  { // test assignment
    vector3<double> v1;
    vector3<double> v2(1, 2, 3);
    v1 = v2;

    assert(v2 == v1);
  }

  { // test indexing
    vector3<double> v(1, 2, 3);

    assert(1 == v[0]);
    assert(2 == v[1]);
    assert(3 == v[2]);
  }

  { // test scalar addition
    vector3<double> v;
    v += 1;

    assert(1 == v[0]);
    assert(1 == v[1]);
    assert(1 == v[2]);
  }

  { // test scalar subtraction
    vector3<double> v(2, 2, 2);
    v -= 1;

    assert(1 == v[0]);
    assert(1 == v[1]);
    assert(1 == v[2]);
  }

  { // test scalar multiplication
    vector3<double> v(1, 1, 1);
    v *= 2;

    assert(2 == v[0]);
    assert(2 == v[1]);
    assert(2 == v[2]);
  }

  { // test scalar division
    vector3<double> v(8, 8, 8);
    v /= 4;

    assert(2 == v[0]);
    assert(2 == v[1]);
    assert(2 == v[2]);
  }

  { // test vector addition
    vector3<double> v1;
    vector3<double> v2(1, 2, 3);
    v1 += v2;

    assert(1 == v1[0]);
    assert(2 == v1[1]);
    assert(3 == v1[2]);
  }

  { // test vector subtraction
    vector3<double> v1(3, 2, 1);
    vector3<double> v2(1, 2, 3);
    v1 -= v2;

    assert(2 == v1[0]);
    assert(0 == v1[1]);
    assert(-2 == v1[2]);
  }

  { // test element-wise multiplication
    vector3<double> v1(3, 2, 1);
    vector3<double> v2(1, 2, 3);
    v1 *= v2;

    assert(3 == v1[0]);
    assert(4 == v1[1]);
    assert(3 == v1[2]);
  }

  { // test element-wise division
    vector3<double> v1(2, 4, 6);
    vector3<double> v2(1, 2, 3);
    v1 /= v2;

    assert(2 == v1[0]);
    assert(2 == v1[1]);
    assert(2 == v1[2]);
  }

  { // test scalar less than
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);
    vector3<double> v3 = v1 < 2;

    assert(1 == v3[0]);
    assert(0 == v3[1]);
    assert(0 == v3[2]);
  }

  { // test scalar greater than
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);
    vector3<double> v3 = v1 > 2;

    assert(0 == v3[0]);
    assert(0 == v3[1]);
    assert(1 == v3[2]);
  }

  { // test element-wise less than
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);
    vector3<double> v3 = v1 < v2;

    assert(1 == v3[0]);
    assert(0 == v3[1]);
    assert(0 == v3[2]);
  }

  { // test element-wise greater than
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);
    vector3<double> v3 = v1 > v2;

    assert(0 == v3[0]);
    assert(0 == v3[1]);
    assert(1 == v3[2]);
  }

  { // test equality
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(1, 2, 3);

    assert(v1 == v2);
  }

  { // test equality
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);

    assert(v1 != v2);
  }

  { // test element-wise addition
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(2, 3, 4);
    vector3<double> v3(3, 5, 7);

    assert(v3 == (v1 + v2));
  }

  { // test element-wise subtraction
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);
    vector3<double> v3(-2, 0, 2);

    assert(v3 == (v1 - v2));
  }

  { // test dot product
    vector3<double> v1(1, 2, 3);
    vector3<double> v2(3, 2, 1);

    assert(10 == (v1 * v2));
  }

  { // test cross product
    vector3<double> v1(1, 0, 0);
    vector3<double> v2(0, 1, 0);
    vector3<double> v3(0, 0, 1);

    assert(v3 == (v1 ^ v2));
  }

  cout << __FILE__ << " passed" << endl;
}
