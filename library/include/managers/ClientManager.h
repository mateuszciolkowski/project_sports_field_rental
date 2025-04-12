//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_CLIENTMANAGER_H
#define PROGRAM_CLIENTMANAGER_H

#include "typedefs.h"
#include <vector>

/**
 * @class ClientManager
 * @brief Zarządza operacjami związanymi z klientami.
 *
 * Ta klasa zapewnia funkcjonalności do rejestracji, wyrejestrowania i zarządzania klientami.
 */
class ClientManager {
private:
    ClientRepositoryPtr clientRepository; ///< Repozytorium przechowujące dane klientów.
public:
    /**
     * @brief Konstruktor nowego obiektu ClientManager.
     */
    ClientManager();

    /**
     * @brief Destruktor obiektu ClientManager.
     */
    ~ClientManager();

    /**
     * @brief Pobiera klienta na podstawie numeru PESEL.
     *
     * @param PESEL Numer PESEL klienta.
     * @return ClientPtr Wskaźnik na obiekt klienta.
     */
    ClientPtr getClient(std::string PESEL);

    /**
     * @brief Rejestruje nowego klienta.
     *
     * @param firstName Imię klienta.
     * @param lastName Nazwisko klienta.
     * @param PESEL Numer PESEL klienta.
     * @param contactDetails Wskaźnik na dane kontaktowe klienta.
     * @param clientType Wskaźnik na typ klienta.
     * @return true jeśli klient został pomyślnie zarejestrowany.
     * @return false jeśli rejestracja klienta nie powiodła się.
     */
    bool registerClient(std::string firstName, std::string lastName, std::string PESEL, ContactDetailsPtr contactDetails, ClientTypePtr clientType);

    /**
     * @brief Wyrejestrowuje klienta na podstawie numeru PESEL.
     *
     * @param PESEL Numer PESEL klienta.
     * @return true jeśli klient został pomyślnie wyrejestrowany.
     * @return false jeśli wyrejestrowanie klienta nie powiodło się.
     */
    bool unregisterClient(std::string PESEL);

    /**
     * @brief Wyszukuje klientów spełniających określone kryteria.
     *
     * @param clientPredicate Predykat określający kryteria wyszukiwania.
     * @return std::vector<ClientPtr> Wektor wskaźników na obiekty klientów.
     */
    std::vector<ClientPtr> findClients(ClientPredicate clientPredicate);

    /**
     * @brief Zwraca wszystkich klientów.
     *
     * @return std::vector<ClientPtr> Wektor wskaźników na obiekty wszystkich klientów.
     */
    std::vector<ClientPtr> findAllClients();

    /**
     * @brief Zwraca liczbę klientów.
     *
     * @return unsigned int Liczba klientów.
     */
    unsigned int getSize();

    /**
     * @brief Generuje raport o klientach.
     *
     * @return std::string Raport o klientach w formie tekstowej.
     */
    std::string report(bool fullClientInfo = false);
};

#endif //PROGRAM_CLIENTMANAGER_H
