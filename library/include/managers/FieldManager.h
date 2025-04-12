//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_FIELDMANAGER_H
#define PROGRAM_FIELDMANAGER_H

#include "typedefs.h"
#include <vector>

/**
 * @class FieldManager
 * @brief Zarządza operacjami związanymi z boiskami.
 *
 * Ta klasa zapewnia funkcjonalności do rejestracji, wyrejestrowania i zarządzania różnymi rodzajami boisk.
 */
class FieldManager {
private:
    FieldRepositoryPtr fieldRepository; ///< Repozytorium przechowujące dane boisk.
public:
    /**
     * @brief Konstruktor nowego obiektu FieldManager.
     */
    FieldManager();

    /**
     * @brief Destruktor obiektu FieldManager.
     */
    ~FieldManager();

    /**
     * @brief Pobiera boisko na podstawie nazwy.
     *
     * @param fieldName Nazwa boiska.
     * @return FieldPtr Wskaźnik na obiekt boiska.
     */
    FieldPtr getField(std::string fieldName);

    /**
     * @brief Wyrejestrowuje boisko na podstawie nazwy.
     *
     * @param fieldName Nazwa boiska.
     * @return true jeśli boisko zostało pomyślnie wyrejestrowane.
     * @return false jeśli wyrejestrowanie boiska nie powiodło się.
     */
    bool unregisterField(std::string fieldName);

    /**
     * @brief Wyszukuje boiska spełniające określone kryteria.
     *
     * @param fieldPredicate Predykat określający kryteria wyszukiwania.
     * @return std::vector<FieldPtr> Wektor wskaźników na obiekty boisk.
     */
    std::vector<FieldPtr> findFields(FieldPredicate fieldPredicate);

    /**
     * @brief Zwraca wszystkie boiska.
     *
     * @return std::vector<FieldPtr> Wektor wskaźników na obiekty wszystkich boisk.
     */
    std::vector<FieldPtr> findAllFields();

    /**
     * @brief Zwraca liczbę boisk.
     *
     * @return unsigned int Liczba boisk.
     */
    unsigned int getSize();

    /**
     * @brief Generuje raport o boiskach.
     *
     * @return std::string Raport o boiskach w formie tekstowej.
     */
    std::string report();

    /**
     * @brief Rejestruje nowe boisko do koszykówki.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do koszykówki.
     * @param covered Czy boisko jest zadaszone.
     * @return true jeśli boisko zostało pomyślnie zarejestrowane.
     * @return false jeśli rejestracja boiska nie powiodła się.
     */
    bool registerBasketballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                 basketballDimensions dimensions, bool covered);

    /**
     * @brief Rejestruje nowe boisko do piłki nożnej.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do piłki nożnej.
     * @param grassy Czy boisko jest trawiaste.
     * @return true jeśli boisko zostało pomyślnie zarejestrowane.
     * @return false jeśli rejestracja boiska nie powiodła się.
     */
    bool registerFootballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                               footballDimensions dimensions, bool grassy);

    /**
     * @brief Rejestruje nową bieżnię.
     *
     * @param fieldName Nazwa bieżni.
     * @param price Cena za użytkowanie bieżni.
     * @param maxNumberOfPeople Maksymalna liczba osób.
     * @param trackLength Długość bieżni.
     * @return true jeśli bieżnia została pomyślnie zarejestrowana.
     * @return false jeśli rejestracja bieżni nie powiodła się.
     */
    bool registerRunningTrack(const std::string &fieldName, double price, unsigned int maxNumberOfPeople,
                              double trackLength);

    /**
     * @brief Rejestruje nowe boisko do siatkówki.
     *
     * @param fieldName Nazwa boiska.
     * @param price Cena za użytkowanie boiska.
     * @param maxNumberOfPlayers Maksymalna liczba graczy.
     * @param dimensions Wymiary boiska do siatkówki.
     * @param sandy Czy boisko jest piaszczyste.
     * @return true jeśli boisko zostało pomyślnie zarejestrowane.
     * @return false jeśli rejestracja boiska nie powiodła się.
     */
    bool registerVolleyballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                 volleyballDimensions dimensions, bool sandy);
};

#endif //PROGRAM_FIELDMANAGER_H
