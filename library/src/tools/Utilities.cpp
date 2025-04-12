//
// Created by 48791 on 23.05.2024.
//

#include "tools/Utilities.h"
//#include string>
#include "sstream"

namespace tools {

    std::string dimensionsToString(volleyballDimensions dimensions) {
        switch (dimensions) {
            case 15:
                return "Length: 18, Width: 9";
            case 13:
                return "Length: 16, Width: 8";
            default:
                return "Unknown dimensions";
        }
    }

    std::string dimensionsToString(footballDimensions dimensions) {
        switch (dimensions) {
            case 25:
                return "Length: 105, Width: 68";
            case 15:
                return "Length: 62, Width: 30";
            case 10:
                return "Length: 31, Width: 15";
            default:
                return "Unknown dimensions";
        }
    }

    std::string dimensionsToString(basketballDimensions dimensions) {
        switch (dimensions) {
            case 15:
                return "Length: 28, Width: 15";
            case 10:
                return "Length: 14, Width: 8";
            default:
                return "Unknown dimensions";
        }
    }

    std::string allDimensionsFootball() {
        std::stringstream info;
        info << "\n\t Mozliwe wymiary: \n \t 1: L105W68 \n\t 2: L62W30 \n\t 3: L31W15 \n";
        return info.str();
    }

    std::string allDimensionsVolleyball() {
        std::stringstream info;
        info << "\n\t Mozliwe wymiary: \n \t 1: L18W9 \n\t 2: L16W8 \n";
        return info.str();
    }

    std::string allDimensionsBasktball() {
        std::stringstream info;
        info << "\n\t Mozliwe wymiary: \n \t 1: L28W15 \n\t 2: L46W8 \n";
        return info.str();
    }

    bool safeInput(int &v) {
        std::cin >> v;

        // if(!cin) // to samo, co if(cin.fail())
        if (std::cin.fail()) // b��d logiczny lub b��d systemu IO
        {
            if (std::cin.bad()) // IO error
                return false;

            std::cin.clear(); // reset flag stanu (goodbit, eofbit, failbit, badbit)
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            // std::cin.ignore(200, '\n');  // tylko std::numeric_limits<std::streamsize>::max()
            // gwarantuje wyczyszczenie ca�ego bufora
            // std::cin.ignore(); // usuni�cie JEDNEGO znaku z bufora

            return false;
        }

        return true;
    }

    bool safeInput(double &v) {
        std::cin >> v;
        if (std::cin.fail())
        {
            if (std::cin.bad())
                return false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        if(v < 0){
            return false;
        }
        return true;
    }

    bool safeInput(unsigned int &v) {
        std::cin >> v;
        if (std::cin.fail())
        {
            if (std::cin.bad())
                return false;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return false;
        }
        if(v < 0){
            return false;
        }
        return true;
    }
}