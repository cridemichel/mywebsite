#include <iostream>
#include "randnumgen.hpp"
#include "parametricLayer.hpp"
#include "activation_layers.hpp"
#include "sequential.hpp"

// Laboratorio 09, Task 3: un DenseLayer in float
void prova_dense() {
    DenseLayer<float> d(128, 784);
    Matrix<float> x = Matrix<float>::Ones(784, 1);
    Matrix<float>& z = d.forward(x);
    std::cout << "DenseLayer<float>: uscita " << z.rows() << " x " << z.cols()
              << ", z(0) = " << z(0) << std::endl;
}

// Laboratorio 09, Task 4: le attivazioni in float
void prova_attivazioni() {
    Matrix<float> x = Matrix<float>::Zero(3, 1);
    x(0) = -2.0;
    x(2) = 2.0;
    SigmoidLayer<float> s;
    TanhLayer<float> t;
    std::cout << "sigmoide: " << s.forward(x).transpose() << std::endl;
    std::cout << "tanh:     " << t.forward(x).transpose() << std::endl;
}

// Laboratorio 09, Task 5: la rete in float
void prova_rete() {
    Sequential<float> rete;
    rete.add(new DenseLayer<float>(128, 784));
    rete.add(new SigmoidLayer<float>());
    rete.add(new DenseLayer<float>(10, 128, InitType::XAVIER, DistroType::UNIFORM));
    rete.add(new TanhLayer<float>());
    Matrix<float> x = Matrix<float>::Ones(784, 1);
    Matrix<float>& y = rete.forward(x);
    std::cout << "rete: uscita " << y.rows() << " x " << y.cols()
              << ", min " << y.minCoeff() << ", max " << y.maxCoeff() << std::endl;
}

// Laboratorio 09, Task 6: la stessa rete in float e in double
void confronto_precisione() {
    rng.seed(42);
    Sequential<float> rete32;
    rete32.add(new DenseLayer<float>(128, 784));
    rete32.add(new SigmoidLayer<float>());
    rete32.add(new DenseLayer<float>(10, 128));
    rete32.add(new TanhLayer<float>());

    rng.seed(42);                        // di nuovo: gli stessi pesi
    Sequential<double> rete64;
    rete64.add(new DenseLayer<double>(128, 784));
    rete64.add(new SigmoidLayer<double>());
    rete64.add(new DenseLayer<double>(10, 128));
    rete64.add(new TanhLayer<double>());

    Matrix<float> x32(784, 1);
    for (int i = 0; i < 784; i++) x32(i) = rng.ranf();
    Matrix<double> x64 = x32.cast<double>();   // lo stesso ingresso, in double

    Matrix<float>& y32 = rete32.forward(x32);
    Matrix<double>& y64 = rete64.forward(x64);
    double scarto = (y32.cast<double>() - y64).cwiseAbs().maxCoeff();
    std::cout << "scarto massimo float/double: " << scarto << std::endl;
}

int main() {
    rng.seed(42);
    // prova_dense();             // Task 3
    // prova_attivazioni();       // Task 4
    // prova_rete();              // Task 5
    // confronto_precisione();    // Task 6
    return 0;
}
