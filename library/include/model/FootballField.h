//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_FOOTBALLFIELD_H
#define PROGRAM_FOOTBALLFIELD_H

#include "typedefs.h"
#include "SportsGround.h"

/**
 * @class FootballField
 * @brief Klasa reprezentująca boisko do piłki nożnej.
 *
 * Klasa ta dziedziczy po klasie SportsGround i dodaje specyficzne właściwości dla boisk do piłki nożnej.
 */
class FootballField : public SportsGround {
private:
    footballDimensions dimensions; ///< Wymiary boiska do piłki nożnej.
    bool grassy; ///< Informacja, czy boisko jest trawiaste.
public:
    /**
     * @brief Konstruktor boiska do piłki nożnej.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do piłki nożnej.
     * @param grassy Czy boisko jest trawiaste.
     */
    FootballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                  footballDimensions dimensions, bool grassy);

    /**
     * @brief Zwraca informacje o boisku do piłki nożnej.
     *
     * @return std::string Informacje o boisku.
     */
    std::string getInfo() const override;

    /**
     * @brief Sprawdza, czy boisko jest trawiaste.
     *
     * @return true jeśli boisko jest trawiaste.
     * @return false jeśli boisko nie jest trawiaste.
     */
    bool isGrassy() const;

    /**
     * @brief Destruktor boiska do piłki nożnej.
     */
    ~FootballField() override;

    /**
     * @brief Zwraca wymiary boiska do piłki nożnej.
     *
     * @return footballDimensions Wymiary boiska.
     */
    footballDimensions getDimensions() const;

    /**
     * @brief Zwraca aktualną cenę za użytkowanie boiska.
     *
     * @return double Aktualna cena.
     */
    double getActualPrice() const override;

    /**
     * @brief Zmiana pola grassy
     * @param change
     */
    void setGrassy(bool change);
};

#endif //PROGRAM_FOOTBALLFIELD_H
