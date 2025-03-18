cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        src/model/BasketballField.cpp
        src/model/Client.cpp
        src/model/ClientType.cpp
        src/model/ContactDetails.cpp
        src/model/Field.cpp
        src/model/FootballField.cpp
        src/model/Rent.cpp
        src/model/RunningTrack.cpp
        src/model/SportsGround.cpp
        src/model/VolleyballField.cpp
        src/repository/ClientRepository.cpp
        src/repository/FieldRepository.cpp
        src/repository/RentRepository.cpp
        src/managers/ClientManager.cpp
        src/managers/RentManager.cpp
        src/managers/FieldManager.cpp
        src/tools/Utilities.cpp
        src/tools/Exception.cpp
)
# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include include/model src/model)

enable_testing()

# Wyszukiwanie Boost Date_Time
find_package(Boost COMPONENTS date_time REQUIRED)

# Dodanie biblioteki Boost do linkowania
target_link_libraries(Library PUBLIC Boost::date_time)

find_package(Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

# tu w przyszłości będą dodawane pliki źródłowe testów
set(SOURCE_TEST_FILES
        test/ClientTests.cpp
        test/ClientTypeTests.cpp
        test/ContactDetailsTests.cpp
        test/RentTests.cpp
        test/FieldRepositoryTests.cpp
        test/RentRepositoryTests.cpp
        test/ClientRepositoryTests.cpp
        test/ClientMangerTests.cpp
        test/FieldManagerTests.cpp
        test/ClientMangerTests.cpp
        test/master.cpp
        test/BasketballFieldTest.cpp
        test/FootballFieldTest.cpp
        test/RunningTrackTest.cpp
        test/VolleyballTest.cpp
)

add_executable(LibraryTester ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries(LibraryTester
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}

)

#dodaj test LibraryTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest LibraryTester
        --report_level=detailed
        --log_level=all
        --color_output=yes
)
#Aby raport testów był szczegółowo wypisany na konsolę, można dodać własny cel budowy o nazwie na przykłąd check (uruchamiany przez make check) w postaci:

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})