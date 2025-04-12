//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_BASKETBALLFIELD_H
#define PROGRAM_BASKETBALLFIELD_H

#include "typedefs.h"
#include "SportsGround.h"


/**
 * @class BasketballField
 * @brief Klasa reprezentująca boisko do koszykówki.
 *
 * Dziedziczy po klasie SportsGround i dodaje specyficzne właściwości dla boisk do koszykówki.
 */
class BasketballField : public SportsGround {
private:
    basketballDimensions dimensions; ///< Wymiary boiska do koszykówki.
    bool covered; ///< Informacja, czy boisko jest zadaszone.
public:
    /**
     * @brief Konstruktor boiska do koszykówki.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do koszykówki.
     * @param covered Czy boisko jest zadaszone.
     */
    BasketballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                    basketballDimensions dimensions, bool covered);

    /**
     * @brief Destruktor boiska do koszykówki.
     */
    ~BasketballField() override;

    /**
     * @brief Zwraca informacje o boisku do koszykówki.
     *
     * @return std::string Informacje o boisku.
     */
    std::string getInfo() const override;

    /**
     * @brief Sprawdza, czy boisko jest zadaszone.
     *
     * @return true jeśli boisko jest zadaszone.
     * @return false jeśli boisko nie jest zadaszone.
     */
    bool isCovered() const;

    /**
     * @brief Zwraca wymiary boiska do koszykówki.
     *
     * @return basketballDimensions Wymiary boiska.
     */
    basketballDimensions getDimensions() const;

    /**
     * @brief Zwraca aktualną cenę za użytkowanie boiska.
     *
     * @return double Aktualna cena.
     */
    double getActualPrice() const override;

    /**
     * @brief Zmiana pola covered
     * @param change
     */
    void setCovered(bool change);
};

#endif //PROGRAM_BASKETBALLFIELD_H
