#ifndef PARAMETRIC_LAYER_HPP
#define PARAMETRIC_LAYER_HPP

#include <cmath>
#include <stdexcept>
#include <string>
#include "layer.hpp"
#include "randnumgen.hpp"

// la classe base dei layer con pesi
template <typename ntype>
class ParametricLayer : public Layer<ntype> {
protected:
    // un numero gaussiano di media 0 e varianza 1 (Box-Muller, Laboratorio 08)
    ntype gauss() {
        double x1, x2;
        do {
            x1 = rng.ranf();
            x2 = rng.ranf();
        } while (x1 == 0 || x2 == 0);
        return std::cos(2 * M_PI * x2) * std::sqrt(-2.0 * std::log(x1));
    }
};

// Uno strato di Nn neuroni con Ni ingressi ciascuno: z = W x
template <typename ntype>
class DenseLayer : public ParametricLayer<ntype> {
    using bc = ParametricLayer<ntype>;   // bc: la classe base
    using bc::gauss;
    using bc::outputs;

    // un peso, con la scala s della formula scelta (Laboratorio 08)
    ntype randfunc(InitType type, DistroType distro) {
        double s = 0.0;
        switch (type) {
            case InitType::HE:
                s = (distro == DistroType::UNIFORM) ? std::sqrt(6.0 / Nin)
                                                    : std::sqrt(2.0 / Nin);
                break;
            case InitType::XAVIER:
                s = (distro == DistroType::UNIFORM) ? std::sqrt(6.0 / (Nnodes + Nin))
                                                    : std::sqrt(2.0 / (Nnodes + Nin));
                break;
        }
        if (distro == DistroType::UNIFORM)
            return 2.0 * s * (rng.ranf() - 0.5);
        return s * gauss();
    }

public:
    Matrix<ntype> Wt;   // W: Nnodes x Nin
    int Nnodes, Nin;

    DenseLayer(int Nn, int Ni, InitType type = InitType::HE,
               DistroType distro = DistroType::GAUSSIAN)
        : Nnodes(Nn), Nin(Ni) {
        Wt = Matrix<ntype>(Nn, Ni);
        for (int i = 0; i < Nn; i++)
            for (int j = 0; j < Ni; j++)
                Wt(i, j) = randfunc(type, distro);
    }

    Matrix<ntype>& forward(const Matrix<ntype>& input) override {
        if (input.rows() != Nin)
            throw std::runtime_error("[DenseLayer] l'ingresso ha "
                + std::to_string(input.rows()) + " righe, ne servono "
                + std::to_string(Nin));
        // Task 3, da completare: il prodotto di Wt per input, in outputs
        return outputs;
    }
};

#endif
