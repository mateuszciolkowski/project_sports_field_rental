//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#ifndef PROGRAM_TYPEDEFS_H
#define PROGRAM_TYPEDEFS_H

#include <memory>
#include <functional>
#include <boost/date_time.hpp>

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

class Rent;
class Field;
class Client;
class SportsGround;
class BasketballField;
class VolleyballField;
class FootballField;
class RunningTrack;
class ClientType;
class Employee;
class ClientNormal;
class ClientVIP;
class ContactDetails;
class ClientRepository;
class RentRepository;
class FieldRepository;
class FieldManager;
class RentManager;
class ClientManager;

/**
 * @file typedefs.h
 * @brief Plik nagłówkowy zawierający definicje typów i enumeracji używanych w programie.
 */

typedef std::shared_ptr<Rent> RentPtr; ///< Wskaźnik na wynajem.
typedef std::shared_ptr<Field> FieldPtr; ///< Wskaźnik na pole sportowe.
typedef std::shared_ptr<Client> ClientPtr; ///< Wskaźnik na klienta.
typedef std::shared_ptr<SportsGround> SportsGroundPtr; ///< Wskaźnik na boisko sportowe.
typedef std::shared_ptr<BasketballField> BasketballFieldPtr; ///< Wskaźnik na boisko do koszykówki.
typedef std::shared_ptr<VolleyballField> VolleyballFieldPtr; ///< Wskaźnik na boisko do siatkówki.
typedef std::shared_ptr<FootballField> FootballFieldPtr; ///< Wskaźnik na boisko do piłki nożnej.
typedef std::shared_ptr<RunningTrack> RunningTrackPtr; ///< Wskaźnik na bieżnię.
typedef std::shared_ptr<ClientType> ClientTypePtr; ///< Wskaźnik na typ klienta.
typedef std::shared_ptr<Employee> EmployeePtr; ///< Wskaźnik na pracownika.
typedef std::shared_ptr<ClientNormal> ClientNormalPtr; ///< Wskaźnik na zwykłego klienta.
typedef std::shared_ptr<ClientVIP> ClientVIPPtr; ///< Wskaźnik na VIP klienta.
typedef std::shared_ptr<ContactDetails> ContactDetailsPtr; ///< Wskaźnik na dane kontaktowe.
typedef std::shared_ptr<ClientRepository> ClientRepositoryPtr; ///< Wskaźnik na repozytorium klientów.
typedef std::shared_ptr<RentRepository> RentRepositoryPtr; ///< Wskaźnik na repozytorium wynajmów.
typedef std::shared_ptr<FieldRepository> FieldRepositoryPtr; ///< Wskaźnik na repozytorium pól sportowych.
typedef std::shared_ptr<FieldManager> FieldManagerPtr; ///< Wskaźnik na menedżera pól sportowych.
typedef std::shared_ptr<RentManager> RentManagerPtr; ///< Wskaźnik na menedżera wynajmów.
typedef std::shared_ptr<ClientManager> ClientManagerPtr; ///< Wskaźnik na menedżera klientów.

typedef std::function<bool(ClientPtr)> ClientPredicate; ///< Predykat dla klienta.
typedef std::function<bool(FieldPtr)> FieldPredicate; ///< Predykat dla pola sportowego.
typedef std::function<bool(RentPtr)> RentPredicate; ///< Predykat dla wynajmu.

/**
 * @brief Enumeracja reprezentująca wymiary boiska do koszykówki.
 */
enum basketballDimensions {
    L28xW15 = 15, ///< Wymiary boiska 28x15 metrów.
    L14xW8 = 10 ///< Wymiary boiska 14x8 metrów.
};

/**
 * @brief Enumeracja reprezentująca wymiary boiska do piłki nożnej.
 */
enum footballDimensions {
    L105xW68 = 25, ///< Wymiary boiska 105x68 metrów.
    L62xW30 = 15, ///< Wymiary boiska 62x30 metrów.
    L31xW15 = 10 ///< Wymiary boiska 31x15 metrów.
};

/**
 * @brief Enumeracja reprezentująca wymiary boiska do siatkówki.
 */
enum volleyballDimensions {
    L18xW9 = 15, ///< Wymiary boiska 18x9 metrów.
    L16xW8 = 13 ///< Wymiary boiska 16x8 metrów.
};

#endif //PROGRAM_TYPEDEFS_H
