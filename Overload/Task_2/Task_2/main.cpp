#include <iostream>

class Fraction
{
private:
    int numerator_;
    int denominator_;
    int nod_;
    
    double FractionValue() {
        return static_cast<double>(numerator_) / static_cast<double>(denominator_);
    }
    
    int NOD(int num1, int num2) {
        int temp = 0;
        while (num2) {
            temp = num1 % num2;
            num1 = num2;
            num2 = temp;
        }
        return num1;
    }
    
public:
    Fraction(int numerator, int denominator)
    {
        if (denominator != 0) {
            numerator_ = numerator;
            denominator_ = denominator;
            nod_ = NOD(numerator, denominator);
        } else {
            throw std::runtime_error("Denominator couldn't be zero");
        }
    }
    
    void ReduceFraction() {
        int nod = NOD(numerator_, denominator_);
        if (nod != 1 && nod != -1) {
            numerator_ = numerator_ / nod;
            denominator_ = denominator_ / nod;
        }
    }
    
    void Print() {
        std::cout << numerator_ << "/" << denominator_;
    }
    
    Fraction operator+ (Fraction other) { return Fraction((numerator_ * other.denominator_) + (denominator_ * other.numerator_), (denominator_ * other.denominator_)); }
    
    Fraction operator- (Fraction other) { return Fraction((numerator_ * other.denominator_) - (denominator_ * other.numerator_), (denominator_ * other.denominator_)); }
    
    Fraction operator* (Fraction other) { return  Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_); }
    
    Fraction operator++ () {
        return Fraction(numerator_ + denominator_, denominator_);
    }
    
    Fraction operator++ (int) {
        Fraction temp = *this;
        Fraction(numerator_ + denominator_, denominator_);
        return temp;
    }
    
    Fraction operator-- () { numerator_--; return *this; }
    
    Fraction operator-- (int) {
        Fraction temp = *this;
        --(*this);
        return temp;
    }
};

int main()
{
    try {
        int num, denom;
        std::cout << "Введите числитель дроби 1: ";
        std::cin >> num;
        std::cout << "Введите знаменатель дроби 1: ";
        std::cin >> denom;
        Fraction f1(num, denom);
        
        std::cout << "Введите числитель дроби 2: ";
        std::cin >> num;
        std::cout << "Введите знаменатель дроби 2: ";
        std::cin >> denom;
        Fraction f2(num, denom);
    
        Fraction sum_f1_f2 = f1 + f2;
        sum_f1_f2.ReduceFraction();
        f1.Print(); std::cout << " + "; f2.Print(); std::cout << " = "; sum_f1_f2.Print(); std::cout << std::endl;
        
        Fraction sub_f1_f2 = f1 - f2;
        sub_f1_f2.ReduceFraction();
        f1.Print(); std::cout << " - "; f2.Print(); std::cout << " = "; sub_f1_f2.Print(); std::cout << std::endl;
        
        Fraction mul_f1_f2 = f1 * f2;
        mul_f1_f2.ReduceFraction();
        f1.Print(); std::cout << " * "; f2.Print(); std::cout << " = "; mul_f1_f2.Print(); std::cout << std::endl;
        
        Fraction inc_pref = ++f1 * f2;
        inc_pref.ReduceFraction();
        std::cout << "++"; f1.Print(); std::cout << " * "; f2.Print(); std::cout << " = "; inc_pref.Print(); std::cout << std::endl;
        std::cout << "Значение дроби 1 = "; f1.Print(); std::cout << std::endl;
        
        Fraction inc_post = f1++ * f2;
        inc_post.ReduceFraction();
        f1.Print(); std::cout << "++";  std::cout << " * "; f2.Print(); std::cout << " = "; inc_post.Print(); std::cout << std::endl;
        std::cout << "Значение дроби 1 = "; f1.Print(); std::cout << std::endl;
        
    } catch (std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    
    return 0;
}
