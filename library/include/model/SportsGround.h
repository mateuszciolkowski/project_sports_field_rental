//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_SPORTSGROUND_H
#define PROGRAM_SPORTSGROUND_H

#include "typedefs.h"
#include "Field.h"

/**
 * @class SportsGround
 * @brief Klasa abstrakcyjna reprezentująca boisko sportowe.
 *
 * Klasa ta dziedziczy po klasie Field i definiuje podstawowe właściwości i zachowania boisk sportowych.
 */
class SportsGround : public Field {
private:
    unsigned int maxNumberOfPlayers; ///< Maksymalna liczba graczy na boisku.
public:
    /**
     * @brief Konstruktor boiska sportowego.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za wynajem boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy na boisku.
     */
    SportsGround(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers);

    /**
     * @brief Destruktor boiska sportowego.
     */
    ~SportsGround() override;

    /**
     * @brief Zwraca informacje o boisku sportowym.
     *
     * @return std::string Informacje o boisku.
     */
    virtual std::string getInfo() const override;

    /**
     * @brief Zwraca aktualną cenę za wynajem boiska sportowego.
     *
     * Jest to metoda abstrakcyjna, która musi być zaimplementowana w klasach pochodnych.
     *
     * @return double Aktualna cena za wynajem boiska.
     */
    double getActualPrice() const override =0;

    /**
     * @brief Zwraca maksymalną liczbę graczy na boisku.
     *
     * @return unsigned int Maksymalna liczba graczy.
     */
    unsigned int getMaxNumberOfPlayers() const;
};

#endif //PROGRAM_SPORTSGROUND_H
