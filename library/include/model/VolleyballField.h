//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_VOLLEYBALLFIELD_H
#define PROGRAM_VOLLEYBALLFIELD_H

#include "typedefs.h"
#include "SportsGround.h"

/**
 * @class VolleyballField
 * @brief Klasa reprezentująca boisko do siatkówki.
 *
 * Klasa ta dziedziczy po klasie SportsGround i dodaje specyficzne właściwości dla boisk do siatkówki.
 */
class VolleyballField : public SportsGround {
private:
    volleyballDimensions dimensions; ///< Wymiary boiska do siatkówki.
    bool sandy; ///< Informacja, czy boisko jest piaskowe.
public:
    /**
     * @brief Konstruktor boiska do siatkówki.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do siatkówki.
     * @param sandy Czy boisko jest piaskowe.
     */
    VolleyballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                    volleyballDimensions dimensions, bool sandy);

    /**
     * @brief Destruktor boiska do siatkówki.
     */
    ~VolleyballField() override;

    /**
     * @brief Zwraca informacje o boisku do siatkówki.
     *
     * @return std::string Informacje o boisku.
     */
    std::string getInfo() const override;

    /**
     * @brief Zwraca wymiary boiska do siatkówki.
     *
     * @return volleyballDimensions Wymiary boiska.
     */
    volleyballDimensions getDimensions() const;

    /**
     * @brief Sprawdza, czy boisko jest piaskowe.
     *
     * @return true jeśli boisko jest piaskowe.
     * @return false jeśli boisko nie jest piaskowe.
     */
    bool isSandy() const;

    /**
     * @brief Zwraca aktualną cenę za użytkowanie boiska.
     *
     * @return double Aktualna cena.
     */
    double getActualPrice() const override;

    /**
     * @brief Zmiana pola sandy
     * @param change
     */
    void setSandy(bool change);
};

#endif //PROGRAM_VOLLEYBALLFIELD_H
