//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_RUNNINGTRACK_H
#define PROGRAM_RUNNINGTRACK_H

#include "typedefs.h"
#include "Field.h"

/**
 * @class RunningTrack
 * @brief Klasa reprezentująca bieżnię do biegania.
 *
 * Klasa ta dziedziczy po klasie Field i dodaje specyficzne właściwości dla bieżni do biegania.
 */
class RunningTrack : public Field {
private:
    unsigned int maxNumberOfPeople; ///< Maksymalna liczba osób korzystających z bieżni.
    double trackLength; ///< Długość bieżni.
public:
    /**
     * @brief Konstruktor bieżni do biegania.
     *
     * @param fieldName Nazwa bieżni.
     * @param price Cena za użytkowanie bieżni.
     * @param maxNumberOfPeople Maksymalna liczba osób korzystających z bieżni.
     * @param trackLength Długość bieżni.
     */
    RunningTrack(const std::string &fieldName, double price, unsigned int maxNumberOfPeople, double trackLength);

    /**
     * @brief Zwraca maksymalną liczbę osób korzystających z bieżni.
     *
     * @return unsigned int Maksymalna liczba osób.
     */
    unsigned int getMaxNumberOfPeople() const;

    /**
     * @brief Zwraca długość bieżni.
     *
     * @return double Długość bieżni.
     */
    double getTrackLength() const;

    /**
     * @brief Zwraca informacje o bieżni.
     *
     * @return std::string Informacje o bieżni.
     */
    std::string getInfo() const override;

    /**
     * @brief Destruktor bieżni.
     */
    ~RunningTrack() override;

    /**
     * @brief Zwraca aktualną cenę za użytkowanie bieżni.
     *
     * @return double Aktualna cena.
     */
    double getActualPrice() const override;
};

#endif //PROGRAM_RUNNINGTRACK_H
