//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_CONTACTDETAILS_H
#define PROGRAM_CONTACTDETAILS_H

#include "typedefs.h"
#include <string>

/**
 * @class ContactDetails
 * @brief Klasa reprezentująca dane kontaktowe.
 *
 * Klasa przechowuje dane kontaktowe klienta, takie jak numer telefonu, adres email, ulica, miasto i numer domu.
 */
class ContactDetails {
private:
    std::string phoneNumber; ///< Numer telefonu.
    std::string email; ///< Adres email.
    std::string street; ///< Ulica.
    std::string city; ///< Miasto.
    std::string houseNumber; ///< Numer domu.
public:
    /**
     * @brief Konstruktor danych kontaktowych.
     *
     * @param phoneNumber Numer telefonu.
     * @param email Adres email.
     * @param street Ulica.
     * @param city Miasto.
     * @param houseNumber Numer domu.
     */
    ContactDetails(const std::string &phoneNumber, const std::string &email, const std::string &street,
                   const std::string &city, const std::string &houseNumber);

    /**
     * @brief Destruktor danych kontaktowych.
     */
    ~ContactDetails();

    /**
     * @brief Zwraca numer telefonu.
     *
     * @return const std::string& Numer telefonu.
     */
    const std::string &getPhoneNumber() const;

    /**
     * @brief Ustawia numer telefonu.
     *
     * @param phoneNumber Nowy numer telefonu.
     */
    void setPhoneNumber(const std::string &phoneNumber);

    /**
     * @brief Zwraca adres email.
     *
     * @return const std::string& Adres email.
     */
    const std::string &getEmail() const;

    /**
     * @brief Ustawia adres email.
     *
     * @param email Nowy adres email.
     */
    void setEmail(const std::string &email);

    /**
     * @brief Zwraca ulicę.
     *
     * @return const std::string& Ulica.
     */
    const std::string &getStreet() const;

    /**
     * @brief Ustawia ulicę.
     *
     * @param street Nowa ulica.
     */
    void setStreet(const std::string &street);

    /**
     * @brief Zwraca miasto.
     *
     * @return const std::string& Miasto.
     */
    const std::string &getCity() const;

    /**
     * @brief Ustawia miasto.
     *
     * @param city Nowe miasto.
     */
    void setCity(const std::string &city);

    /**
     * @brief Zwraca numer domu.
     *
     * @return const std::string& Numer domu.
     */
    const std::string &getHouseNumber() const;

    /**
     * @brief Ustawia numer domu.
     *
     * @param houseNumber Nowy numer domu.
     */
    void setHouseNumber(const std::string &houseNumber);

    /**
     * @brief Zwraca informacje o danych kontaktowych.
     *
     * @return std::string Informacje o danych kontaktowych.
     */
    std::string getContactDetailsInfo() const;
};

#endif //PROGRAM_CONTACTDETAILS_H
