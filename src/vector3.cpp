#include "vector3.hpp"
#include <cmath>
namespace Raytracing{
    
    Vector3::Vector3(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vector3::Vector3(float xyz){
        this->y=this->z=this->x=xyz;
    }
    Vector3::Vector3(){
        Vector3(0,0,0);
    }

    Vector3 Vector3::operator*(const float &l) const {
        return Vector3(this->x * l, this->y * l, this->z * l);
    }


    Vector3 Vector3::operator/(const float &l) const{
        return *this*(1/l);
    }


    float Vector3::length() {
        return std::sqrt( this -> x * this -> x + this -> y * this -> y + this -> z * this -> z);
    }



    void Vector3::normalize(){

        *this = *this / this->length();

    }
    
    Vector3 Vector3::normalized(){
        return *this / this->length();
    }

    Vector3 Vector3::vectorProduct(const Vector3 &v) const{
        return Vector3( this->y * v.z - this->z * v.y, 
                        this->z * v.x - this->x * v.z,
                        this->x * v.y - this->y * v.x);
    }

    float Vector3::dotProduct(const Vector3 &v) const{
        return this->x*v.x + this->y*v.y + this->z*v.z;

    }


    Vector3 Vector3::operator=(const Vector3 &v){
        this->x=v.x;
        this->y=v.y;
        this->z=v.z;
        return *this;
    }

    Vector3 Vector3::operator+(const Vector3 &l) const{
        return Vector3(this->x+l.x, this->y+l.y, this->z+l.z);
    }
    Vector3 Vector3::operator-(const Vector3 &l) const{
        return Vector3(this->x-l.x, this->y-l.y, this->z-l.z);
    }

    bool Vector3::operator==(const Vector3 &l) const{
        return l.x == this->x && l.y == this->y & l.z == this->z;
    }
    bool Vector3::operator!=(const Vector3 &l) const{
        return l.x != this->x || l.y != this->y || l.z != this->z;
    }

    std::ostream& operator<<(std::ostream &outs, const Vector3 &v){ //no bug here
        return outs << "(" << v.x << "," << v.y << "," << v.z << ")";
    }


    float Vector3::clamp(float fact, int min, int max) const{
        if (fact < min){
            return min;
        } else if (fact > max){
            return max;
        }
        else {
            return fact;
        }
    }


    Vector3 Vector3::mix(Vector3 const &v, float fact) const{
        fact = Vector3::clamp(fact, 0.f ,1.f);
        return (* this) * fact + v * (1-fact);
    }

    uint32_t Vector3::toHexColor() const{
        return  (uint8_t(0xff * this->x)<<24)
            +   (uint8_t(0xff * this->y)<<16)
            +   (uint8_t(0xff * this->z)<<8)
            +   0xff;
    }

    Vector3 Vector3::dimensionWiseProduct(const Vector3 &v) const{
        return Vector3(v.x * this->x, v.y * this->y, v.z * this->z);
    }
    Vector3 Vector3::reflected_along(Vector3 n) const{
        return (*this) - n * (2 * (this->dotProduct(n)));
    }

}
