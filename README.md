# Welcome to BetterDouble

BetterDouble is a collection of floating-point types with extra capabilities. It includes:
 - `bd::Real<T>` - imitation of standard numeric types, such as `float` or `double`.
 - `bd::Differentiable<T, N>` - numeric types that hold information about derivatives. E.g. automatic differentiation!

### Example
```
bd::DDouble a = 1; a.derivative[0] = 2;             //a = 1, da/dt = 2
bd::DDouble b = 3; b.derivative[0] = 4;             //b = 3, da/dt = 4
bd::DDouble c = a * b;                              //c = a * b
std::cout << "c     = " << (double)c << '\n';       //c = ?
std::cout << "dc/dt = " << c.derivative[0] << '\n'; //dt/dc = ?
```