EuronextSurveilllance

A C++ / Qt6-based desktop application for real-time market surveillance and fraud detection monitoring systems for Euronext.
The project implements a modular architecture with processors, observers, and UI components to visualize 
and detect suspicious trading behaviors such as spoofing, pump-and-dump, wash trading, and price ceiling/floor.

Features
•	Qt6 GUI with multi-view windows and searchable tables
•	Real-time monitoring architecture using Observer pattern
•	Fraud detection processors:
•	Spoofing
•	Pump and Dump
•	Wash Trading
•	Quote Stuffing
•	Ceiling / Floor
•	Interactive charts (Qt6 Charts)
•	Database connector module (extensible backend)
•	Modern C++17 codebase

Project Structure

EuronextSurveilllance/
main.cpp
UI:
    mainwindow.ui
    multipleViewsWindow.h/.cpp
    SearchableTableWidget.h/.cpp
Domain:
    order.h
    Alert.h
Observers:
    IOrderObserver.h
    IFraudObserver.h
    AlertObserver.h/.cpp 
    ChartOrderObserver.h
    ChartFraudObserver.h
Processors:
    IProcessor.h
    FraudMonitor.cpp
    SpoofingProcessor.h/.cpp
    PumpDumpProcessor.h/.cpp
    WashProcessor.h/.cpp
    QuoteProcessor.h/.cpp
    CeilingProcessor.h/.cpp
    FloorProcessor.h/.cpp
Database:
    DbConnector.h/.cpp
nlohmann:
    json.hpp
CMakeLists.txt

Requirements
•	CMake ≥ 3.16
•	C++17 compatible compiler
•	GCC 9+
•	Clang 10+
•	MSVC 2019+
•	Qt 6 with the following components:
•	Core
•	Gui
•	Widgets
•	Charts


Build Instructions

1. Install Qt6

Make sure Qt6 is installed and Qt6_DIR is available in your environment.

2. Clone the Repository

git clone https://github.com/arcreane/finance-surveillance.git
cd EuronextSurveilllance

3. Run CMakeLists.txt in Qt



Fraud Detection Modules

Module	Description
SpoofingProcessor	Detects fake order placement and cancellation patterns
PumpDumpProcessor	Identifies abnormal volume/price surges
WashProcessor	Detects self-trading behaviors
QuoteProcessor	Flags excessive quote updates
CeilingProcessor	Detects price hitting upper limits
FloorProcessor	Detects price hitting lower limits


JSON Support

The project includes support for nlohmann/json for structured market or alert data handling.

To enable:
•	Place json.hpp inside the nlohmann/ directory
•	Include in your code:

#include <nlohmann/json.hpp>

