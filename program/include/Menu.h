#ifndef ORLIK_MENU_H
#define ORLIK_MENU_H
#include "typedefs.h"
/**
 * @class Menu
 * @brief Klasa reprezentująca menu aplikacji, która zarządza interakcjami użytkownika z systemem.
 *
 * Klasa Menu jest odpowiedzialna za zarządzanie interfejsem użytkownika i delegowanie zadań do
 * odpowiednich managerów, takich jak ClientManager, FieldManager, i RentManager.
 */
class Menu {
private:
    ClientManagerPtr clientManager; /**< Wskaźnik do obiektu zarządzającego klientami. */
    FieldManagerPtr fieldManager; /**< Wskaźnik do obiektu zarządzającego polami. */
    RentManagerPtr rentManager; /**< Wskaźnik do obiektu zarządzającego wynajmami. */

public:
    /**
     * @brief Konstruktor domyślny klasy Menu.
     *
     * Inicjalizuje nowy obiekt klasy Menu.
     */
    Menu();

    /**
     * @brief Destruktor klasy Menu.
     *
     * Usuwa obiekt klasy Menu i zwalnia zasoby.
     */
    ~Menu();

    /**
     * @brief Uruchamia interfejs wiersza poleceń.
     *
     * Metoda odpowiedzialna za uruchomienie interfejsu wiersza poleceń,
     * umożliwiającego użytkownikowi interakcję z systemem.
     */
    void cliInterface();

    /**
     * @brief Metoda zarządzająca klientami.
     *
     * Odpowiada za operacje związane z zarządzaniem klientami, takie jak dodawanie,
     * usuwanie i edytowanie danych klientów.
     */
    void client();

    /**
     * @brief Metoda zarządzająca polami.
     *
     * Odpowiada za operacje związane z zarządzaniem polami, takie jak dodawanie,
     * usuwanie i edytowanie danych pól.
     */
    void field();

    /**
     * @brief Metoda zarządzająca wynajmami.
     *
     * Odpowiada za operacje związane z zarządzaniem wynajmami, takie jak dodawanie,
     * usuwanie i edytowanie danych wynajmów.
     */
    void rent();
};



#endif //ORLIK_MENU_H
