//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_RENTREPOSITORY_H
#define PROGRAM_RENTREPOSITORY_H

#include "typedefs.h"
#include <vector>

/**
 * @class RentRepository
 * @brief Klasa reprezentująca repozytorium wynajmów.
 *
 * Klasa ta przechowuje informacje o wynajmowanych obiektach i umożliwia wykonywanie operacji na nich, takich jak dodawanie, usuwanie, wyszukiwanie itp.
 */
class RentRepository {
private:
    std::vector<RentPtr> rents; ///< Wektor wskaźników na wynajmy.
public:
    /**
     * @brief Konstruktor repozytorium wynajmów.
     */
    RentRepository();

    /**
     * @brief Destruktor repozytorium wynajmów.
     */
    ~RentRepository();

    /**
     * @brief Dodaje wynajem do repozytorium.
     *
     * @param rent Wskaźnik na wynajem do dodania.
     */
    bool addRent(const RentPtr &rent);

    /**
     * @brief Usuwa wynajem z repozytorium.
     *
     * @param rent Wskaźnik na wynajem do usunięcia.
     */
    bool removeRent(const RentPtr &rent);

    /**
     * @brief Zwraca wynajem z repozytorium na podstawie indeksu.
     *
     * @param index Indeks wynajmu.
     * @return const RentPtr& Wskaźnik na wynajem.
     */
    const RentPtr &getRent(unsigned int index) const;

    /**
     * @brief Generuje raport z repozytorium wynajmów.
     *
     * @return std::string Raport z repozytorium wynajmów.
     */
    std::string report();

    /**
     * @brief Zwraca liczbę wynajmów w repozytorium.
     *
     * @return unsigned int Liczba wynajmów.
     */
    unsigned int getSize();

    /**
     * @brief Wyszukuje wynajmy spełniające podany predykat.
     *
     * @param predicate Predykat do spełnienia.
     * @return std::vector<RentPtr> Wektor wskaźników na znalezione wynajmy.
     */
    std::vector<RentPtr> findBy(RentPredicate &predicate) const;

    /**
     * @brief Zwraca wszystkie wynajmy w repozytorium.
     *
     * @return std::vector<RentPtr> Wektor wskaźników na wszystkie wynajmy.
     */
    std::vector<RentPtr> findAll() const;

    /**
     * @brief Wyszukuje wynajem po identyfikatorze wynajmu.
     *
     * @param rentID Identyfikator wynajmu.
     * @return RentPtr Wskaźnik na znaleziony wynajem lub nullptr, jeśli wynajem o podanym identyfikatorze nie istnieje.
     */
    RentPtr findByRentID(unsigned int rentID) const;

    /**
     * @brief Zmienia typ klienta na VIP na podstawie wynajmu.
     *
     * @param client Wskaźnik na klienta.
     */
    void changeToVIP(ClientPtr client);
};

#endif //PROGRAM_RENTREPOSITORY_H
