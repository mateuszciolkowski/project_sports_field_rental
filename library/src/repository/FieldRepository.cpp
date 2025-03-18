//
// Created by Mateusz Ciołkowski on 21/05/2024.
//

#include "../../include/repository/FieldRepository.h"
#include "sstream"
#include "Field.h"
#include "tools/Exception.h"

FieldRepository::FieldRepository() {

}

FieldRepository::~FieldRepository() {

}

bool FieldRepository::addField(const FieldPtr &field) {
    bool find = false;
    for (const auto &it: fields) {
        if (it == field) {
            find = true;
        }
    }
    if (!find && field != nullptr) {
        fields.push_back(field);
        return true;
    } else {
        throw FieldException("Nie dodano obiektu sportowego do repozytorium.");
//        return false;
    }
}

bool FieldRepository::removeField(const FieldPtr &field) {
    bool find = false;
    for (const auto &it: fields) {
        if (it == field) {
            find = true;
        }
    }
    if (find && field != nullptr) {
        auto newEnd = std::remove(fields.begin(), fields.end(), field);
        fields.erase(newEnd, fields.end());
        return true;
    } else {
        throw FieldException("Nie usunieto obiektu sportowego z repozytorium.");
//        return false;
    }
}

FieldPtr FieldRepository::getField(unsigned int index) const {
    return fields.at(index);
}

std::string FieldRepository::report() {
    std::stringstream report;
    for (unsigned int i = 0; i < fields.size(); i++) {
        report << fields[i]->getInfo() << std::endl;
    }
    return report.str();
}

unsigned int FieldRepository::getSize() {
    return fields.size();
}

std::vector<FieldPtr> FieldRepository::findBy(FieldPredicate &predicate) const {
    std::vector<FieldPtr> found;
    for (unsigned int i = 0; i < fields.size(); i++) {
        FieldPtr field = getField(i);
        if (field != nullptr && predicate(field)) {
            found.push_back(field);
        }
    }
    return found;
}

std::vector<FieldPtr> FieldRepository::findAll() const {
    FieldPredicate test = [](const FieldPtr &) { return true; };
    return findBy(test);
}

FieldPtr FieldRepository::findByFieldName(std::string fieldName) const {
    for (const auto &it: fields) {
        if (it->getFieldName() == fieldName) {
            return it;
        }
    }
    return nullptr;
}



