#include "../include/betterdouble/betterdouble.hxx"

template class bd::Real<double>;
template class bd::Real<float>;
template class bd::Differentiable<double, 1>;
template class bd::Differentiable<float, 1>;

int main()
{
    bd::Double a = 1;
    a += 1;
    a = sin(a);
    return 0;
}