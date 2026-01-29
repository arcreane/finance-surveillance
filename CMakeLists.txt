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

        # UI
        mainwindow.ui
        multipleViewsWindow.cpp
        multipleViewsWindow.h
        SearchableTableWidget.cpp
        SearchableTableWidget.h

        # Domain
        order.h
        Alert.h

        # Observers
        AlertObserver.cpp
        AlertObserver.h
        ChartOrderObserver.h
        ChartFraudObserver.h
        IFraudObserver.h
        IOrderObserver.h

        # Processors / Monitoring
        IProcessor.h
        FraudMonitor.cpp

        DbConnector.cpp
        DbConnector.h

        CeilingProcessor.cpp
        CeilingProcessor.h
        FloorProcessor.cpp
        FloorProcessor.h
        PumpDumpProcessor.cpp
        PumpDumpProcessor.h
        QuoteProcessor.cpp
        QuoteProcessor.h
        SpoofingProcessor.cpp
        SpoofingProcessor.h
        WashProcessor.cpp
        WashProcessor.h
)

target_include_directories(EuronextSurveilllance PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/nlohmann
)

target_link_libraries(EuronextSurveilllance PRIVATE
        Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Charts
)

