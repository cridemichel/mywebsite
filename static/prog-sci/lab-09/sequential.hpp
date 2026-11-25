#ifndef SEQUENTIAL_HPP
#define SEQUENTIAL_HPP

#include <stdexcept>
#include <vector>
#include "layer.hpp"

// la rete: una sequenza di layer, di cui e' proprietaria; anche lei e' un Layer
template <typename ntype>
class Sequential : public Layer<ntype> {
private:
    std::vector<Layer<ntype>*> layers;   // i layer, creati con new

public:
    Sequential() {}
    ~Sequential() {
        for (Layer<ntype>* l : layers) {
            delete l;
        }
    }
    Sequential(const Sequential&) = delete;              // copia vietata
    Sequential& operator=(const Sequential&) = delete;   // assegnamento vietato

    void add(Layer<ntype>* layer) { layers.push_back(layer); }

    // l'uscita di ogni layer e' l'ingresso del successivo, senza copie
    Matrix<ntype>& forward(const Matrix<ntype>& input) override {
        if (layers.size() == 0)
            throw std::runtime_error("[Sequential] la rete non ha layer");
        const Matrix<ntype>* ingresso = &input;   // l'ingresso del prossimo layer
        Matrix<ntype>* uscita = nullptr;          // l'uscita dell'ultimo layer
        for (Layer<ntype>* l : layers) {
            uscita = &l->forward(*ingresso);
            // Task 5, da completare: l'uscita di l diventa l'ingresso del prossimo layer
        }
        return *uscita;
    }
};

#endif
