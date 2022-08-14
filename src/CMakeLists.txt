cmake_minimum_required(VERSION 3.5)

if(APPLE)
    set(CMAKE_PREFIX_PATH "/Users/idawnlight/Qt/6.3.1/macos/lib/cmake")
endif()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        ui/window/EntryWidget.cpp ui/window/EntryWidget.h ui/window/SetupWindow.cpp ui/window/SetupWindow.h ui/window/ExamWindow.cpp ui/window/ExamWindow.h ui/widgets/ProblemIndicatorLayout.cpp ui/widgets/ProblemIndicatorLayout.h models/BaseProblem.cpp models/BaseProblem.h models/Paper.cpp models/Paper.h models/AnswerPaper.cpp models/AnswerPaper.h models/problems/SingleChoiceProblem.cpp models/problems/SingleChoiceProblem.h models/problems/MultipleChoiceProblem.cpp models/problems/MultipleChoiceProblem.h models/problems/TrueOrFalseProblem.cpp models/problems/TrueOrFalseProblem.h models/problems/ShortAnswerProblem.cpp models/problems/ShortAnswerProblem.h)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(auto_exam
            MANUAL_FINALIZATION
            ${PROJECT_SOURCES}
            )
    # Define target properties for Android with Qt 6 as:
    #    set_property(TARGET auto_exam APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
    #                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
    # For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(auto_exam SHARED
                ${PROJECT_SOURCES}
                )
        # Define properties for Android with Qt 5 after find_package() calls as:
        #    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(auto_exam
                ${PROJECT_SOURCES}
                )
    endif()
endif()

target_link_libraries(auto_exam PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(auto_exam PRIVATE nlohmann_json::nlohmann_json)

set_target_properties(auto_exam PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
        MACOSX_BUNDLE TRUE
        WIN32_EXECUTABLE TRUE
        )

install(TARGETS auto_exam
        BUNDLE DESTINATION .
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(auto_exam)
endif()