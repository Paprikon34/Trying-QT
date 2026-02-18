cmake_minimum_required(VERSION 3.19)
project(QT-consol_app-hello LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core)

qt_standard_project_setup()

qt_add_executable(QT-consol_app-hello
    main.cpp
)

target_link_libraries(QT-consol_app-hello
    PRIVATE
        Qt::Core
)

include(GNUInstallDirs)

install(TARGETS QT-consol_app-hello
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)
