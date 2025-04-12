//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "managers/FieldManager.h"
#include "repository/FieldRepository.h"
#include "BasketballField.h"
#include "FootballField.h"
#include "RunningTrack.h"
#include "VolleyballField.h"
#include "tools/Exception.h"

FieldManager::~FieldManager() {

}


FieldManager::FieldManager() : fieldRepository(new FieldRepository()) {

}

FieldPtr FieldManager::getField(std::string fieldName) {
    return fieldRepository->findByFieldName(fieldName);
}

bool FieldManager::unregisterField(std::string fieldName) {
    if (fieldRepository->removeField(fieldRepository->findByFieldName(fieldName))) {
        return true;
    } else {
        throw FieldException("Nie udalo sie wyrejestrowac boiska.");
//        return false;
    };
}

std::vector<FieldPtr> FieldManager::findAllFields() {
    return fieldRepository->findAll();
}

std::vector<FieldPtr> FieldManager::findFields(FieldPredicate fieldPredicate) {
    return fieldRepository->findBy(fieldPredicate);

}

unsigned int FieldManager::getSize() {
    return fieldRepository->getSize();
}

std::string FieldManager::report() {
    return fieldRepository->report();
}

bool FieldManager::registerBasketballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                           basketballDimensions dimensions, bool covered) {

    BasketballFieldPtr fieldTmp = std::make_shared<BasketballField>(fieldName, price, maxNumberOfPlayers, dimensions,
                                                                    covered);
    if (fieldRepository->findByFieldName(fieldName) == nullptr) {
        fieldRepository->addField(fieldTmp);
        return true;
    } else {
        throw FieldException("Nie zarejestrowano boiska do koszykowki.");
//        return false;
    }
}

bool FieldManager::registerFootballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                         footballDimensions dimensions, bool grassy) {
    FootballFieldPtr fieldTmp = std::make_shared<FootballField>(fieldName, price, maxNumberOfPlayers, dimensions,
                                                                grassy);
    if (fieldRepository->findByFieldName(fieldName) == nullptr) {
        fieldRepository->addField(fieldTmp);
        return true;
    } else {
        throw FieldException("Nie zarejestrowano boiska do pilki noznej.");
//        return false;
    }
}

bool FieldManager::registerRunningTrack(const std::string &fieldName, double price, unsigned int maxNumberOfPeople,
                                        double trackLength) {
    RunningTrackPtr fieldTmp = std::make_shared<RunningTrack>(fieldName, price, maxNumberOfPeople, trackLength);
    if (fieldRepository->findByFieldName(fieldName) == nullptr) {
        fieldRepository->addField(fieldTmp);
        return true;
    } else {
        throw FieldException("Nie zarejestrowano biezni.");
//        return false;
    }
}

bool FieldManager::registerVolleyballField(const std::string &fieldName, double price, unsigned int maxNumberOfPlayers,
                                           volleyballDimensions dimensions, bool sandy) {
    VolleyballFieldPtr fieldTmp = std::make_shared<VolleyballField>(fieldName, price, maxNumberOfPlayers, dimensions,
                                                                    sandy);
    if (fieldRepository->findByFieldName(fieldName) == nullptr) {
        fieldRepository->addField(fieldTmp);
        return true;
    } else {
        throw FieldException("Nie zarejestrowano boiska do siatkowki.");
//        return false;
    }
}
