//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_FIELDMENAGER_H
#define PROGRAM_FIELDMENAGER_H

#include "typedefs.h"

/**
 * @class FieldRepository
 * @brief Klasa reprezentująca repozytorium pól sportowych.
 *
 * Klasa ta przechowuje informacje o polach sportowych i umożliwia wykonywanie operacji na nich, takich jak dodawanie, usuwanie, wyszukiwanie itp.
 */
class FieldRepository {
private:
    std::vector<FieldPtr> fields; ///< Wektor wskaźników na pola sportowe.
public:
    /**
     * @brief Konstruktor repozytorium pól sportowych.
     */
    FieldRepository();

    /**
     * @brief Destruktor repozytorium pól sportowych.
     */
    ~FieldRepository();

    /**
     * @brief Dodaje pole sportowe do repozytorium.
     *
     * @param field Wskaźnik na pole sportowe do dodania.
     * @return bool true, jeśli dodanie powiodło się, w przeciwnym razie false.
     */
    bool addField(const FieldPtr &field);

    /**
     * @brief Usuwa pole sportowe z repozytorium.
     *
     * @param field Wskaźnik na pole sportowe do usunięcia.
     * @return bool true, jeśli usunięcie powiodło się, w przeciwnym razie false.
     */
    bool removeField(const FieldPtr &field);

    /**
     * @brief Zwraca pole sportowe z repozytorium na podstawie indeksu.
     *
     * @param index Indeks pola sportowego.
     * @return FieldPtr Wskaźnik na pole sportowe.
     */
    FieldPtr getField(unsigned int index) const;

    /**
     * @brief Generuje raport z repozytorium pól sportowych.
     *
     * @return std::string Raport z repozytorium pól sportowych.
     */
    std::string report();

    /**
     * @brief Zwraca liczbę pól sportowych w repozytorium.
     *
     * @return unsigned int Liczba pól sportowych.
     */
    unsigned int getSize();

    /**
     * @brief Wyszukuje pola sportowe spełniające podany predykat.
     *
     * @param predicate Predykat do spełnienia.
     * @return std::vector<FieldPtr> Wektor wskaźników na znalezione pola sportowe.
     */
    std::vector<FieldPtr> findBy(FieldPredicate &predicate) const;

    /**
     * @brief Zwraca wszystkie pola sportowe w repozytorium.
     *
     * @return std::vector<FieldPtr> Wektor wskaźników na wszystkie pola sportowe.
     */
    std::vector<FieldPtr> findAll() const;

    /**
     * @brief Wyszukuje pole sportowe po nazwie.
     *
     * @param fieldName Nazwa pola sportowego.
     * @return FieldPtr Wskaźnik na znalezione pole sportowe lub nullptr, jeśli pole o podanej nazwie nie istnieje.
     */
    FieldPtr findByFieldName(std::string fieldName) const;
};

#endif //PROGRAM_FIELDMENAGER_H
