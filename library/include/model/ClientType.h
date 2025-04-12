//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_CLIENTTYPE_H
#define PROGRAM_CLIENTTYPE_H

#include "typedefs.h"
#include <string>

/**
 * @class ClientType
 * @brief Klasa bazowa reprezentująca typ klienta.
 *
 * Klasa ta definiuje interfejs dla różnych typów klientów, takich jak Employee, ClientNormal i ClientVIP.
 */
class ClientType {
public:
    /**
     * @brief Konstruktor typu klienta.
     */
    ClientType();

    /**
     * @brief Destruktor typu klienta.
     */
    ~ClientType();

    /**
     * @brief Zwraca informacje o typie klienta.
     *
     * @return std::string Informacje o typie klienta.
     */
    virtual std::string getInfo();

    /**
     * @brief Zwraca maksymalny czas wynajmu.
     *
     * @return unsigned int Maksymalny czas wynajmu w godzinach.
     */
    virtual unsigned int getMaxRentalTime() = 0;

    /**
     * @brief Zwraca procent zniżki.
     *
     * @return unsigned int Procent zniżki.
     */
    virtual unsigned int getPercentOfDiscount() = 0;
};

/**
 * @class Employee
 * @brief Klasa reprezentująca typ klienta - pracownik.
 */
class Employee : public ClientType {
private:
    unsigned int percentOfDiscount; ///< Procent zniżki dla pracownika.
    unsigned int maxRentalTime; ///< Maksymalny czas wynajmu dla pracownika.
public:
    /**
     * @brief Konstruktor pracownika.
     */
    Employee();

    /**
     * @brief Destruktor pracownika.
     */
    ~Employee();

    /**
     * @brief Zwraca informacje o pracowniku.
     *
     * @return std::string Informacje o pracowniku.
     */
    std::string getInfo() override;

    /**
     * @brief Zwraca maksymalny czas wynajmu dla pracownika.
     *
     * @return unsigned int Maksymalny czas wynajmu w godzinach.
     */
    unsigned int getMaxRentalTime() override;

    /**
     * @brief Zwraca procent zniżki dla pracownika.
     *
     * @return unsigned int Procent zniżki.
     */
    unsigned int getPercentOfDiscount() override;
};

/**
 * @class ClientNormal
 * @brief Klasa reprezentująca typ klienta - klient normalny.
 */
class ClientNormal : public ClientType {
private:
    unsigned int percentOfDiscount; ///< Procent zniżki dla klienta normalnego.
    unsigned int maxRentalTime; ///< Maksymalny czas wynajmu dla klienta normalnego.
public:
    /**
     * @brief Konstruktor klienta normalnego.
     */
    ClientNormal();

    /**
     * @brief Destruktor klienta normalnego.
     */
    ~ClientNormal();

    /**
     * @brief Zwraca informacje o kliencie normalnym.
     *
     * @return std::string Informacje o kliencie normalnym.
     */
    std::string getInfo() override;

    /**
     * @brief Zwraca maksymalny czas wynajmu dla klienta normalnego.
     *
     * @return unsigned int Maksymalny czas wynajmu w godzinach.
     */
    unsigned int getMaxRentalTime() override;

    /**
     * @brief Zwraca procent zniżki dla klienta normalnego.
     *
     * @return unsigned int Procent zniżki.
     */
    unsigned int getPercentOfDiscount() override;
};

/**
 * @class ClientVIP
 * @brief Klasa reprezentująca typ klienta - klient VIP.
 */
class ClientVIP : public ClientType {
private:
    unsigned int percentOfDiscount; ///< Procent zniżki dla klienta VIP.
    unsigned int maxRentalTime; ///< Maksymalny czas wynajmu dla klienta VIP.
public:
    /**
     * @brief Konstruktor klienta VIP.
     */
    ClientVIP();

    /**
     * @brief Destruktor klienta VIP.
     */
    ~ClientVIP();

    /**
     * @brief Zwraca informacje o kliencie VIP.
     *
     * @return std::string Informacje o kliencie VIP.
     */
    std::string getInfo() override;

    /**
     * @brief Zwraca maksymalny czas wynajmu dla klienta VIP.
     *
     * @return unsigned int Maksymalny czas wynajmu w godzinach.
     */
    unsigned int getMaxRentalTime() override;

    /**
     * @brief Zwraca procent zniżki dla klienta VIP.
     *
     * @return unsigned int Procent zniżki.
     */
    unsigned int getPercentOfDiscount() override;
};

#endif //PROGRAM_CLIENTTYPE_H
