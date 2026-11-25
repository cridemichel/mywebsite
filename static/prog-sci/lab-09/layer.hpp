#ifndef LAYER_HPP
#define LAYER_HPP

#include "eigen_wrap.hpp"

// come inizializzare i pesi (Laboratorio 08)
enum class InitType   { HE, XAVIER };
enum class DistroType { UNIFORM, GAUSSIAN };

// la classe base astratta di tutti i layer, ora un template
template <typename ntype>
class Layer {
protected:
    Matrix<ntype> outputs;   // l'uscita dell'ultimo forward

public:
    virtual ~Layer() {}
    virtual Matrix<ntype>& forward(const Matrix<ntype>& input) = 0;
};

#endif
