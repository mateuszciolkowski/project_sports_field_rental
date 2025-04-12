//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_CLIENTREPOSITORY_H
#define PROGRAM_CLIENTREPOSITORY_H

#include "typedefs.h"
#include <vector>

/**
 * @class ClientRepository
 * @brief Klasa reprezentująca repozytorium klientów.
 *
 * Klasa ta przechowuje informacje o klientach i umożliwia wykonywanie operacji na nich, takich jak dodawanie, usuwanie, wyszukiwanie itp.
 */
class ClientRepository {
private:
    std::vector<ClientPtr> clients; ///< Wektor wskaźników na klientów.
public:
    /**
     * @brief Konstruktor repozytorium klientów.
     */
    ClientRepository();

    /**
     * @brief Destruktor repozytorium klientów.
     */
    ~ClientRepository();

    /**
     * @brief Zwraca klienta z repozytorium na podstawie indeksu.
     *
     * @param index Indeks klienta.
     * @return const ClientPtr& Wskaźnik na klienta.
     */
    const ClientPtr &getClient(unsigned int index) const;

    /**
     * @brief Dodaje klienta do repozytorium.
     *
     * @param client Wskaźnik na klienta do dodania.
     * @return bool true, jeśli dodanie powiodło się, w przeciwnym razie false.
     */
    bool addClient(const ClientPtr &client);

    /**
     * @brief Usuwa klienta z repozytorium.
     *
     * @param client Wskaźnik na klienta do usunięcia.
     * @return bool true, jeśli usunięcie powiodło się, w przeciwnym razie false.
     */
    bool removeClient(const ClientPtr &client);

    /**
     * @brief Generuje raport z repozytorium klientów.
     *
     * @return std::string Raport z repozytorium klientów.
     */
    std::string report(bool fullClientInfo = false);

    /**
     * @brief Zwraca liczbę klientów w repozytorium.
     *
     * @return unsigned int Liczba klientów.
     */
    unsigned int size();

    /**
     * @brief Wyszukuje klientów spełniających podany predykat.
     *
     * @param predicate Predykat do spełnienia.
     * @return std::vector<ClientPtr> Wektor wskaźników na znalezione klienty.
     */
    std::vector<ClientPtr> findBy(ClientPredicate &predicate) const;

    /**
     * @brief Zwraca wszystkich klientów w repozytorium.
     *
     * @return std::vector<ClientPtr> Wektor wskaźników na wszystkich klientów.
     */
    std::vector<ClientPtr> findAll() const;

    /**
     * @brief Wyszukuje klienta po numerze PESEL.
     *
     * @param personalID Numer PESEL klienta.
     * @return ClientPtr Wskaźnik na znalezionego klienta lub nullptr, jeśli klient o podanym numerze PESEL nie istnieje.
     */
    ClientPtr findByPESEL(std::string personalID) const;
};

#endif //PROGRAM_CLIENTREPOSITORY_H
