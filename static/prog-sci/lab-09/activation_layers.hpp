#ifndef ACTIVATION_LAYERS_HPP
#define ACTIVATION_LAYERS_HPP

#include "layer.hpp"

// la classe base delle attivazioni, per ora vuota (Laboratorio 08)
template <typename ntype>
class ActivationLayer : public Layer<ntype> {
};

template <typename ntype>
class SigmoidLayer : public ActivationLayer<ntype> {
    using bc = ActivationLayer<ntype>;
    using bc::outputs;

public:
    // sigma(z) = 1 / (1 + exp(-z)), elemento per elemento
    Matrix<ntype>& forward(const Matrix<ntype>& input) override {
        const ntype uno = static_cast<ntype>(1.0);
        outputs = uno / (uno + (-input.array()).exp());
        return outputs;
    }
};

template <typename ntype>
class TanhLayer : public ActivationLayer<ntype> {
    using bc = ActivationLayer<ntype>;
    using bc::outputs;

public:
    // tanh(z), elemento per elemento
    Matrix<ntype>& forward(const Matrix<ntype>& input) override {
        // Task 4, da completare: la tanh di ogni elemento di input, in outputs
        return outputs;
    }
};

#endif
