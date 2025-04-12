//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_RENTMANAGER_H
#define PROGRAM_RENTMANAGER_H

#include "typedefs.h"
#include <vector>

/**
 * @class RentManager
 * @brief Zarządza operacjami związanymi z wynajmem boisk.
 *
 * Ta klasa zapewnia funkcjonalności do zarządzania aktualnymi i archiwalnymi wynajmami boisk.
 */
class RentManager {
private:
    RentRepositoryPtr archiveRents; ///< Repozytorium przechowujące archiwalne wynajmy.
    RentRepositoryPtr currentRents; ///< Repozytorium przechowujące aktualne wynajmy.
    unsigned int count = 0; ///< Licznik wynajmów.
public:
    /**
     * @brief Konstruktor nowego obiektu RentManager.
     */
    RentManager();

    /**
     * @brief Destruktor obiektu RentManager.
     */
    ~RentManager();

    /**
     * @brief Pobiera wynajmy danego klienta.
     *
     * @param client Wskaźnik na obiekt klienta.
     * @param archive Flaga określająca, czy pobrać wynajmy archiwalne (domyślnie false).
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty wynajmów.
     */
    std::vector<RentPtr> getClientRents(const ClientPtr& client, bool archive = false);

    /**
     * @brief Pobiera wynajem danego boiska.
     *
     * @param field Wskaźnik na obiekt boiska.
     * @return RentPtr Wskaźnik na obiekt wynajmu.
     */
    RentPtr getFieldRent(const FieldPtr& field);

    /**
     * @brief Wyszukuje wynajmy spełniające określone kryteria.
     *
     * @param rentPredicate Predykat określający kryteria wyszukiwania.
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty wynajmów.
     */
    std::vector<RentPtr> findRents(const RentPredicate& rentPredicate);

    /**
     * @brief Wyszukuje archiwalne wynajmy spełniające określone kryteria.
     *
     * @param rentPredicate Predykat określający kryteria wyszukiwania.
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty archiwalnych wynajmów.
     */
    std::vector<RentPtr> findArchiveRents(RentPredicate rentPredicate);

    /**
     * @brief Wyszukuje aktualne wynajmy spełniające określone kryteria.
     *
     * @param rentPredicate Predykat określający kryteria wyszukiwania.
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty aktualnych wynajmów.
     */
    std::vector<RentPtr> findCurrentRents(RentPredicate rentPredicate);

    /**
     * @brief Zwraca wszystkie wynajmy.
     *
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty wszystkich wynajmów.
     */
    std::vector<RentPtr> findAllRents();

    /**
     * @brief Zwraca wszystkie aktualne wynajmy.
     *
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty wszystkich aktualnych wynajmów.
     */
    std::vector<RentPtr> findAllCurrentRents();

    /**
     * @brief Zwraca wszystkie archiwalne wynajmy.
     *
     * @return std::vector<RentPtr> Wektor wskaźników na obiekty wszystkich archiwalnych wynajmów.
     */
    std::vector<RentPtr> findAllArchiveRents();

    /**
     * @brief Znajduje wynajem po identyfikatorze.
     *
     * @param id Identyfikator wynajmu.
     * @param archive Flaga określająca, czy szukać w archiwalnych wynajmach (domyślnie false).
     * @return RentPtr Wskaźnik na obiekt wynajmu.
     */
    RentPtr findById(unsigned int id, bool archive = false);

    /**
     * @brief Sprawdza liczbę wynajmów danego klienta.
     *
     * @param client Wskaźnik na obiekt klienta.
     * @return unsigned int Liczba wynajmów klienta.
     */
    unsigned int checkClientRents(const ClientPtr& client);

    /**
     * @brief Wynajmuje boisko.
     *
     * @param client Wskaźnik na obiekt klienta.
     * @param field Wskaźnik na obiekt boiska.
     * @param beginTime Czas rozpoczęcia wynajmu.
     * @param rentHours Liczba godzin wynajmu.
     * @return true jeśli wynajem został pomyślnie zarejestrowany.
     * @return false jeśli rejestracja wynajmu nie powiodła się.
     */
    bool rentField(const ClientPtr& client, const FieldPtr& field, pt::ptime beginTime, unsigned int rentHours);

    /**
     * @brief Zwraca boisko po wynajmie.
     *
     * @param field Wskaźnik na obiekt boiska.
     * @param endTime Czas zakończenia wynajmu.
     * @return true jeśli boisko zostało pomyślnie zwrócone.
     * @return false jeśli zwrot boiska nie powiódł się.
     */
    bool returnField(FieldPtr field, pt::ptime endTime);

    /**
     * @brief Generuje raport o wynajmach.
     *
     * @return std::string Raport o wynajmach w formie tekstowej.
     */
    std::string report();

    /**
     * @brief Generuje raport o archiwalnych wynajmach.
     *
     * @return std::string Raport o archiwalnych wynajmach w formie tekstowej.
     */
    std::string archiveReport();

    /**
     * @brief Generuje raport o aktualnych wynajmach.
     *
     * @return std::string Raport o aktualnych wynajmach w formie tekstowej.
     */
    std::string currentReport();

    /**
     * @brief Zwiększa licznik wynajmów.
     */
    void incrementCount();

    /**
     * @brief Zwraca bieżący licznik wynajmów.
     *
     * @return unsigned int Liczba wynajmów.
     */
    unsigned int getCount() const;
};

#endif //PROGRAM_RENTMANAGER_H
