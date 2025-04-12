//
// Created by 48791 on 23.05.2024.
//

#ifndef ORLIK_UTILITIES_H
#define ORLIK_UTILITIES_H

#include "../typedefs.h"

namespace tools {


/**
 * @brief Konwertuje wymiary boiska do siatkówki na string.
 *
 * @param dimensions Wymiary boiska do siatkówki.
 * @return std::string Wymiary boiska do siatkówki w postaci stringa.
 */
    std::string dimensionsToString(volleyballDimensions dimensions);

/**
 * @brief Konwertuje wymiary boiska do piłki nożnej na string.
 *
 * @param dimensions Wymiary boiska do piłki nożnej.
 * @return std::string Wymiary boiska do piłki nożnej w postaci stringa.
 */
    std::string dimensionsToString(footballDimensions dimensions);

/**
 * @brief Konwertuje wymiary boiska do koszykówki na string.
 *
 * @param dimensions Wymiary boiska do koszykówki.
 * @return std::string Wymiary boiska do koszykówki w postaci stringa.
 */
    std::string dimensionsToString(basketballDimensions dimensions);

    /**
     * @brief Zwraca pelną liste możliwych enumów dla FootballField
     * @return std::string Informacje o mozliwosciach
     */
    std::string allDimensionsFootball();

    /**
  * @brief Zwraca pelną liste możliwych enumów dla VolleyballField
  * @return std::string Informacje o mozliwosciach
  */
    std::string allDimensionsVolleyball();

    /**
  * @brief Zwraca pelną liste możliwych enumów dla BasketballField
  * @return std::string Informacje o mozliwosciach
  */
    std::string allDimensionsBasktball();

    /**
 * @brief Bezpiecznie wczytuje wartość całkowitą.
 *
 * Funkcja próbuje bezpiecznie wczytać wartość całkowitą z wejścia standardowego.
 * Zwraca true, jeśli operacja zakończyła się sukcesem, w przeciwnym razie false.
 *
 * @param v Referencja do zmiennej, do której zostanie zapisana wczytana wartość.
 * @return true jeśli wczytanie zakończyło się sukcesem, false w przeciwnym razie.
 */
    bool safeInput(int& v);

/**
 * @brief Bezpiecznie wczytuje wartość zmiennoprzecinkową.
 *
 * Funkcja próbuje bezpiecznie wczytać wartość zmiennoprzecinkową z wejścia standardowego.
 * Zwraca true, jeśli operacja zakończyła się sukcesem, w przeciwnym razie false.
 *
 * @param v Referencja do zmiennej, do której zostanie zapisana wczytana wartość.
 * @return true jeśli wczytanie zakończyło się sukcesem, false w przeciwnym razie.
 */
    bool safeInput(double& v);

/**
 * @brief Bezpiecznie wczytuje wartość nieujemnej liczby całkowitej.
 *
 * Funkcja próbuje bezpiecznie wczytać wartość nieujemnej liczby całkowitej z wejścia standardowego.
 * Zwraca true, jeśli operacja zakończyła się sukcesem, w przeciwnym razie false.
 *
 * @param v Referencja do zmiennej, do której zostanie zapisana wczytana wartość.
 * @return true jeśli wczytanie zakończyło się sukcesem, false w przeciwnym razie.
 */
    bool safeInput(unsigned int& v);



}
#endif //ORLIK_UTILITIES_H
