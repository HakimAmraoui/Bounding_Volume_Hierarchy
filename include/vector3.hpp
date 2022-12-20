
#ifndef RAYTRACING_VECTOR3_H
#define RAYTRACING_VECTOR3_H
#include <iostream>
namespace Raytracing{
    class Vector3 {
        public:
            float x;
            float y;
            float z;
            Vector3();
            Vector3(float x, float y, float z);
            Vector3(float xyz);
            Vector3 operator*(const float &l) const;
            Vector3 operator/(const float &l) const;

            Vector3 operator+(const float &l) const; //coordwise addition
            Vector3 operator+(const Vector3 &l) const;

            Vector3 operator-(const float &l) const;
            Vector3 operator-(const Vector3 &l) const;
            
            Vector3 operator=(const Vector3 &l);
            Vector3 operator=(const float &l);

            bool operator==(const Vector3 &l) const;
            bool operator!=(const Vector3 &l) const;

            void normalize();
            float length();

            Vector3 vectorProduct(const Vector3 &v) const;
            float dotProduct(const Vector3 &v) const;
            Vector3 normalized();
            Vector3 dimensionWiseProduct(const Vector3 &v) const;
            float clamp(float fact, int min, int max) const;
            Vector3 mix(const Vector3 &v1, float fact) const;
            uint32_t toHexColor() const;

            Vector3 reflected_along(Vector3 n) const;

    };
    std::ostream& operator<<(std::ostream &outs, const Vector3 &v);
}

#endif
