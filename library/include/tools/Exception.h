//
// Created by Mateusz on 12/06/2024.
//
#include <stdexcept>

#ifndef ORLIK_EXCEPTION_H
#define ORLIK_EXCEPTION_H


// Exception.h
#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>
/**
 * @class Exceptions
 * @brief Klasa bazowa dla wyjątków, dziedzicząca po std::runtime_error.
 *
 * Klasa Exceptions stanowi bazę dla wszystkich wyjątków specyficznych dla aplikacji,
 * dziedzicząc po standardowej klasie std::runtime_error.
 */
class Exceptions : public std::runtime_error {
public:
    /**
     * @brief Konstruktor klasy Exceptions.
     *
     * Inicjalizuje nowy obiekt klasy Exceptions z podaną wiadomością błędu.
     * @param message Wiadomość błędu opisująca wyjątek.
     */
    explicit Exceptions(const std::string& message);
};

/**
 * @class InvalidInputException
 * @brief Wyjątek zgłaszany w przypadku nieprawidłowego wejścia.
 *
 * Klasa InvalidInputException jest używana do zgłaszania wyjątków związanych z nieprawidłowym wejściem danych przez użytkownika.
 */
class InvalidInputException : public Exceptions {
public:
    /**
     * @brief Konstruktor klasy InvalidInputException.
     *
     * Inicjalizuje nowy obiekt klasy InvalidInputException z podaną wiadomością błędu.
     * @param message Wiadomość błędu opisująca wyjątek.
     */
    explicit InvalidInputException(const std::string& message);
};

/**
 * @class ClientException
 * @brief Wyjątek zgłaszany w przypadku błędów związanych z klientami.
 *
 * Klasa ClientException jest używana do zgłaszania wyjątków specyficznych dla operacji na klientach.
 */
class ClientException : public Exceptions {
public:
    /**
     * @brief Konstruktor klasy ClientException.
     *
     * Inicjalizuje nowy obiekt klasy ClientException z podaną wiadomością błędu.
     * @param message Wiadomość błędu opisująca wyjątek.
     */
    explicit ClientException(const std::string& message);
};

/**
 * @class FieldException
 * @brief Wyjątek zgłaszany w przypadku błędów związanych z polami.
 *
 * Klasa FieldException jest używana do zgłaszania wyjątków specyficznych dla operacji na polach.
 */
class FieldException : public Exceptions {
public:
    /**
     * @brief Konstruktor klasy FieldException.
     *
     * Inicjalizuje nowy obiekt klasy FieldException z podaną wiadomością błędu.
     * @param message Wiadomość błędu opisująca wyjątek.
     */
    explicit FieldException(const std::string& message);
};

/**
 * @class RentException
 * @brief Wyjątek zgłaszany w przypadku błędów związanych z wynajmami.
 *
 * Klasa RentException jest używana do zgłaszania wyjątków specyficznych dla operacji na wynajmach.
 */
class RentException : public Exceptions {
public:
    /**
     * @brief Konstruktor klasy RentException.
     *
     * Inicjalizuje nowy obiekt klasy RentException z podaną wiadomością błędu.
     * @param message Wiadomość błędu opisująca wyjątek.
     */
    explicit RentException(const std::string& message);
};


#endif // EXCEPTION_H


#endif //ORLIK_EXCEPTION_H
