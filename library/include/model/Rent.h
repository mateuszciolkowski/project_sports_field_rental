//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_RENT_H
#define PROGRAM_RENT_H

#include "typedefs.h"

/**
 * @class Rent
 * @brief Klasa reprezentująca wynajem pola sportowego przez klienta.
 *
 * Klasa ta przechowuje informacje o wynajmie, takie jak identyfikator wynajmu, klient, pole sportowe, czas rozpoczęcia i zakończenia wynajmu, koszt wynajmu itp.
 */
class Rent {
private:
    ClientPtr client; ///< Wskaźnik na klienta.
    FieldPtr field; ///< Wskaźnik na pole sportowe.
    unsigned int rentId; ///< Identyfikator wynajmu.
    pt::ptime beginTime; ///< Czas rozpoczęcia wynajmu.
    pt::ptime endTime; ///< Czas zakończenia wynajmu.
    double rentCost; ///< Koszt wynajmu.
    unsigned int rentHours; ///< Liczba godzin wynajmu.
public:
    /**
     * @brief Konstruktor wynajmu pola sportowego.
     *
     * @param rentId Identyfikator wynajmu.
     * @param beginTime Czas rozpoczęcia wynajmu.
     * @param rentHours Liczba godzin wynajmu.
     * @param client Wskaźnik na klienta.
     * @param field Wskaźnik na pole sportowe.
     */
    Rent(unsigned int rentId, pt::ptime beginTime, unsigned int rentHours, ClientPtr client, FieldPtr field);

    /**
     * @brief Destruktor wynajmu.
     */
    ~Rent();

    /**
     * @brief Zwraca informacje o wynajmie.
     *
     * @return std::string Informacje o wynajmie.
     */
    std::string getRentInfo();

    /**
     * @brief Zakończenie wynajmu.
     *
     * Ustawia czas zakończenia wynajmu oraz oblicza koszt wynajmu.
     *
     * @param endTime Czas zakończenia wynajmu.
     */
    void endRent(pt::ptime endTime);

    /**
     * @brief Zwraca wskaźnik na klienta.
     *
     * @return const ClientPtr& Wskaźnik na klienta.
     */
    const ClientPtr &getClient() const;

    /**
     * @brief Zwraca wskaźnik na pole sportowe.
     *
     * @return const FieldPtr& Wskaźnik na pole sportowe.
     */
    const FieldPtr &getField() const;

    /**
     * @brief Zwraca identyfikator wynajmu.
     *
     * @return unsigned int Identyfikator wynajmu.
     */
    unsigned int getRentId() const;

    /**
     * @brief Zwraca czas rozpoczęcia wynajmu.
     *
     * @return const pt::ptime& Czas rozpoczęcia wynajmu.
     */
    const pt::ptime &getBeginTime() const;

    /**
     * @brief Zwraca czas zakończenia wynajmu.
     *
     * @return const pt::ptime& Czas zakończenia wynajmu.
     */
    const pt::ptime &getEndTime() const;

    /**
     * @brief Zwraca koszt wynajmu.
     *
     * @return double Koszt wynajmu.
     */
    double getRentCost() const;

    /**
     * @brief Zwraca liczbę godzin wynajmu.
     *
     * @return unsigned int Liczba godzin wynajmu.
     */
    unsigned int getRentHours() const;

    /**
     * @brief Ustawia koszt wynajmu.
     *
     * @param rentCost Nowy koszt wynajmu.
     */
    void setRentCost(double rentCost);

    /**
     * @brief Ustawia liczbę godzin wynajmu.
     *
     * @param rentHours Nowa liczba godzin wynajmu.
     */
    void setRentHours(unsigned int rentHours);
};

#endif //PROGRAM_RENT_H
