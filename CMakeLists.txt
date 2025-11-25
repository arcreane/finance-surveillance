cmake_minimum_required(VERSION 3.16)
project(EuronextSurveilllance LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Charts)

add_executable(EuronextSurveilllance
        main.cpp
        FraudMonitor.cpp
        multipleViewsWindow.cpp
        DbConnector.cpp
        CeilingProcessor.cpp
        FloorProcessor.cpp
        PumpDumpProcessor.cpp
        SpoofingProcessor.cpp
        WashProcessor.cpp
        SearchableTableWidget.cpp
        AlertObserver.cpp
)

target_include_directories(EuronextSurveilllance PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann
)

target_link_libraries(EuronextSurveilllance PRIVATE
        Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Charts
)