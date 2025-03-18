//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_FIELD_H
#define PROGRAM_FIELD_H

#include "typedefs.h"
#include <string>

/**
 * @class Field
 * @brief Klasa abstrakcyjna reprezentująca pole sportowe.
 *
 * Klasa ta definiuje podstawowe właściwości i zachowania pól sportowych.
 */
class Field {
private:
    std::string fieldName; ///< Nazwa pola sportowego.
    double price; ///< Cena za wynajem pola sportowego.
public:
    /**
     * @brief Konstruktor pola sportowego.
     *
     * @param fieldName Nazwa pola sportowego.
     * @param price Cena za wynajem pola sportowego.
     */
    Field(const std::string &fieldName, double price);

    /**
     * @brief Wirtualny destruktor pola sportowego.
     */
    virtual ~Field() = 0;

    /**
     * @brief Zwraca nazwę pola sportowego.
     *
     * @return const std::string& Nazwa pola sportowego.
     */
    const std::string &getFieldName() const;

    /**
     * @brief Zwraca cenę za wynajem pola sportowego.
     *
     * @return double Cena za wynajem pola sportowego.
     */
    double getPrice() const;

    /**
     * @brief Zwraca informacje o polu sportowym.
     *
     * @return std::string Informacje o polu sportowym.
     */
    virtual std::string getInfo() const;

    /**
     * @brief Ustawia cenę za wynajem pola sportowego.
     *
     * @param price Nowa cena za wynajem pola sportowego.
     */
    void setPrice(double price);

    /**
     * @brief Zwraca aktualną cenę za wynajem pola sportowego.
     *
     * Jest to metoda abstrakcyjna, która musi być zaimplementowana w klasach pochodnych.
     *
     * @return double Aktualna cena za wynajem pola sportowego.
     */
    virtual double getActualPrice() const = 0;
};

#endif //PROGRAM_FIELD_H
