cmake_minimum_required(VERSION 3.16)

# Название проекта, стандартная версия проекта, ЯП - С++
project(SuperRota VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# При установке этого флага выдаст ошибку, если версия С++ < 17
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Искать Qt6 и импортировать Quick компонент. Флаг REQUIRED прервет работу программы, если не найдет этот модуль
find_package(Qt6 6.2
    COMPONENTS Quick Xml Sql
    REQUIRED)


set (HEADERS
    instruments.h
    servercontroller.h
    DB/Tables/addirionalinfo.h
    DB/Tables/address.h
    DB/Tables/document.h
    DB/Tables/documenttype.h
    DB/Tables/education.h
    DB/Tables/educationtype.h
    DB/Tables/human.h
    DB/Tables/humanhasaddress.h
    DB/Tables/practice.h
    DB/Tables/rank.h
    DB/Tables/relatives.h
    DB/Tables/rota.h
    DB/Tables/scientificwork.h
    DB/Tables/scientificworktype.h
    DB/Tables/squad.h
    DB/Tables/summon.h
    DB/Tables/workplace.h
    DB/Tables/workplacetype.h

#    Documents/Excel/excelbase.h
#    Documents/Excel/excelfsb.h
#    Documents/Excel/excelhrdepartment.h
#    Documents/Excel/excelrotapassport.h
)

set (SOURCES
    ${HEADERS}
    instruments.cpp
    servercontroller.cpp
    DB/Tables/addirionalinfo.cpp
    DB/Tables/address.cpp
    DB/Tables/document.cpp
    DB/Tables/documenttype.cpp
    DB/Tables/education.cpp
    DB/Tables/educationtype.cpp
    DB/Tables/human.cpp
    DB/Tables/humanhasaddress.cpp
    DB/Tables/practice.cpp
    DB/Tables/rank.cpp
    DB/Tables/relatives.cpp
    DB/Tables/rota.cpp
    DB/Tables/scientificwork.cpp
    DB/Tables/scientificworktype.cpp
    DB/Tables/squad.cpp
    DB/Tables/summon.cpp
    DB/Tables/workplace.cpp
    DB/Tables/workplacetype.cpp

#    Documents/Excel/excelbase.cpp
#    Documents/Excel/excelfsb.cpp
#    Documents/Excel/excelhrdepartment.cpp
#    Documents/Excel/excelrotapassport.cpp
)


set (QML_FILES
    main.qml
    Frontend/AppHeader.qml
    Frontend/NavButton.qml
    Frontend/NavigationDrawer.qml
    Frontend/personnel.qml
    Frontend/Separator.qml
    Frontend/Structure.qml
    Frontend/Table.qml
)

set (RESOURCES
    qml.qrc
    #    db.jpg
)


qt_add_executable(appSuperRota
    main.cpp
    ${SOURCES}
    ${QML_FILES}
    ${RESOURCES}
#    ${MOC_SOURCES}
#    ${QRC_SOURCES}
)

qt_add_qml_module(appSuperRota
    URI SuperRota
    VERSION 1.0
    SOURCES ${SOURCES}
    QML_FILES ${QML_FILES}
    RESOURCES ${RESOURCES}
)


source_group("Source Files" FILES ${SOURCES})
source_group("Header Files" FILES ${HEADERS})
source_group("Qml files" FILES ${QML_FILES})
source_group ("Resource Files" FILES ${RESOURCES})
#source_group ("Generated Files" FILES ${MOC_SOURCES})


set_target_properties(appSuperRota PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSuperRota
    PRIVATE Qt6::Quick Qt6::Xml Qt6::Sql
)

install(TARGETS appSuperRota
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
