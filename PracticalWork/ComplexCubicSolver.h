#include <iostream>
#include <cmath>
#include <vector>
namespace practica
{

struct cfloat32_t {
    float re;
    float im;

    cfloat32_t operator+(const cfloat32_t& b) {
        return cfloat32_t{ this->re + b.re, this->im + b.im };
    }
    cfloat32_t operator-(const cfloat32_t& b) {
        return cfloat32_t{ this->re - b.re, this->im - b.im };
    }
    cfloat32_t operator*(const cfloat32_t& b) {
        return cfloat32_t{
            this->re * b.re - this->im * b.im,
            this->im * b.re + this->re * b.im 
        };
    }
    cfloat32_t operator*(const float& b) {
        return cfloat32_t{
            this->re * b,
            this->im * b
        };
    }
    cfloat32_t operator/(const float& b) {
        return cfloat32_t{
            this->re / b,
            this->im / b
        };
    }
    cfloat32_t pow(const float& b) {
        float rn = powf(sqrtf(this->im * this->im + this->re * this->re), b);
        float fi = atanf(this->im / this->re);


        return cfloat32_t{
            rn * cosf(fi*b),
            rn * sinf(fi*b)
        };
    }
    cfloat32_t operator/(const cfloat32_t& b) {
        return cfloat32_t{
            (b.re * this->re + b.im * this->im) / (b.re * b.re + b.im * b.im),
            (b.re * this->im - this->re * b.im) / (b.re * b.re + b.im * b.im)
            
        };
    }
};


std::vector<cfloat32_t> soleCubic(cfloat32_t& a, cfloat32_t& b, cfloat32_t& c, cfloat32_t& d) {
    //ax^3+bx^2+cx+d=0
    //y^3 + py + q = 0
    cfloat32_t p = ((a * c * 3.f) - b * b) / (a * a * 3.f);
    cfloat32_t q = (b * b * b * 2.f - a * b * c * 9.f + a * a * d * 27.f) / (a * a * a * 27.f);
    
    cfloat32_t Q = (p / 3.f).pow(3.f) + (q / 2.f).pow(2.f);

    cfloat32_t alpha = (q / -2.f + Q.pow(1 / 2.f)).pow(1 / 3.f);
    cfloat32_t betta = (q / -2.f - Q.pow(1 / 2.f)).pow(1 / 3.f);

    cfloat32_t y1 = alpha + betta;
    cfloat32_t y2 = (alpha + betta) / -2.f + (alpha - betta) / 2.f * sqrtf(3.f);
    cfloat32_t y3 = (alpha + betta) / -2.f - (alpha - betta) / 2.f * sqrtf(3.f);


    return std::vector<cfloat32_t> {
        y1,y2,y3
    };
}

int main()
{
    cfloat32_t a{ 0,1 };
    cfloat32_t b{ 1,0 };
    cfloat32_t c{ 0,1 };
    cfloat32_t d{ 5,0 };
    auto solutions = soleCubic(a, b, c, d);
    b = b;
}
}
