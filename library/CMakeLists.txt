cmake_minimum_required(VERSION 3.4)
project(library)

set(SOURCE_FILES
    src/model/client.cpp
    src/model/address.cpp
    src/model/vehicle.cpp
    src/model/rent.cpp
    src/model/motorvehicle.cpp
    src/model/mope.cpp
    src/model/car.cpp
    src/model/bicycle.cpp
    src/model/segmentMap.cpp
    src/model/rentsrepository.cpp
    src/model/vehiclerepository.cpp
    src/model/clientrepository.cpp
    src/model/clientstandard.cpp
    src/model/clientpremium.cpp
    src/model/clientbusiness.cpp
    src/model/clienttype.cpp
    src/model/rentsmanager.cpp
    src/exceptions/clientexception.cpp
    src/exceptions/rentexception.cpp
    src/exceptions/vehicleexception.cpp
    src/model/clientmanager.cpp
    src/model/vehiclemanager.cpp
)
#utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(library ${SOURCE_FILES})

target_include_directories(library PUBLIC include)
target_include_directories(library PUBLIC include/model)
target_include_directories(library PUBLIC include/exceptions)


#Sekcja testów
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/model
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_RENT_FILES
        test/master.cpp
        test/RentTest.cpp)
        
set(SOURCE_VEHICLE_TEST_FILES
		test/master.cpp
		test/VehiclesTest.cpp)
		
set(SOURCE_REPOSITORY_TEST_FILES
		test/master.cpp
		test/RepositoriesTest.cpp)
set(SOURCE_CLIENTTYPE_TEST_FILES
        test/master.cpp
        test/ClientTypeTest.cpp)
set(SOURCE_MANAGERS_TEST_FILES
		test/master.cpp
		test/ManagersTest.cpp)
		
add_executable (RentTest ${SOURCE_TEST_RENT_FILES})
add_executable (VehicleTest ${SOURCE_VEHICLE_TEST_FILES})
add_executable (RepositoryTest ${SOURCE_REPOSITORY_TEST_FILES})
add_executable (ClientTypeTest ${SOURCE_CLIENTTYPE_TEST_FILES})
add_executable (ManagersTest ${SOURCE_MANAGERS_TEST_FILES})

target_link_libraries (RentTest
        library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (VehicleTest
        library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (RepositoryTest
		library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		)
target_link_libraries (ClientTypeTest
        library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
target_link_libraries (ManagersTest
		library
		${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
		)
		
enable_testing()
        
add_test(RentsTest RentTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(VehiclesTest VehicleTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(RepositoriesTest RepositoryTest
		--report_level=detailed
        --log_level=all
        --color_output=yes
        )
add_test(ClientTypesTest ClientTypeTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
        
add_test(ManagerTest ManagersTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )
        
add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIG> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
