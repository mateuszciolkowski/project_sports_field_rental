//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_CLIENT_H
#define PROGRAM_CLIENT_H

#include "typedefs.h"
#include <string>

/**
 * @class Client
 * @brief Klasa reprezentująca klienta.
 *
 * Ta klasa przechowuje dane klienta oraz zapewnia metody do zarządzania tymi danymi.
 */
class Client {
private:
    std::string firstName; ///< Imię klienta.
    std::string lastName; ///< Nazwisko klienta.
    std::string PESEL; ///< Numer PESEL klienta.
    ContactDetailsPtr contactDetails; ///< Wskaźnik na dane kontaktowe klienta.
    ClientTypePtr clientType; ///< Wskaźnik na typ klienta.
public:
    /**
     * @brief Konstruktor klienta.
     *
     * @param firstName Imię klienta.
     * @param lastName Nazwisko klienta.
     * @param PESEL Numer PESEL klienta.
     * @param contactDetails Wskaźnik na dane kontaktowe klienta.
     * @param clientType Wskaźnik na typ klienta.
     */
    Client(std::string firstName, std::string lastName, std::string PESEL, ContactDetailsPtr contactDetails,
           ClientTypePtr clientType);

    /**
     * @brief Destruktor klienta.
     */
    ~Client();

    /**
     * @brief Zwraca imię klienta.
     *
     * @return const std::string& Imię klienta.
     */
    const std::string &getFirstName() const;

    /**
     * @brief Zwraca nazwisko klienta.
     *
     * @return const std::string& Nazwisko klienta.
     */
    const std::string &getLastName() const;

    /**
     * @brief Ustawia imię klienta.
     *
     * @param firstName Nowe imię klienta.
     */
    void setFirstName(const std::string &firstName);

    /**
     * @brief Ustawia nazwisko klienta.
     *
     * @param lastName Nowe nazwisko klienta.
     */
    void setLastName(const std::string &lastName);

    /**
     * @brief Zwraca numer PESEL klienta.
     *
     * @return const std::string& Numer PESEL klienta.
     */
    const std::string &getPesel() const;

    /**
     * @brief Zwraca wskaźnik na dane kontaktowe klienta.
     *
     * @return const ContactDetailsPtr& Wskaźnik na dane kontaktowe klienta.
     */
    const ContactDetailsPtr &getContactDetails() const;

    /**
     * @brief Ustawia dane kontaktowe klienta.
     *
     * @param contactDetails Nowe dane kontaktowe klienta.
     */
    void setContactDetails(const ContactDetailsPtr &contactDetails);

    /**
     * @brief Zwraca wskaźnik na typ klienta.
     *
     * @return const ClientTypePtr& Wskaźnik na typ klienta.
     */
    const ClientTypePtr &getClientType() const;

    /**
     * @brief Ustawia typ klienta.
     *
     * @param clientType Nowy typ klienta.
     */
    void setClientType(const ClientTypePtr &clientType);

    /**
     * @brief Zwraca informacje o kliencie.
     *
     * @param fullInfo Flaga określająca, czy zwrócić pełne informacje (domyślnie false).
     * @return std::string Informacje o kliencie.
     */
    std::string getInfo(bool fullInfo = false);
};

#endif //PROGRAM_CLIENT_H
