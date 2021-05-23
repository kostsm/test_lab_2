TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.cpp \
    load.cpp \
    save.cpp \
    show.cpp \
    showunderscores.cpp \
    text/append_line.cpp \
    text/create_text.cpp \
    text/m.cpp \
    text/mpweb.cpp \
    text/process_forward.cpp \
    text/remove_all.cpp \
    text/rn.cpp

HEADERS += \
    text/text.h \
    text/_text.h \
    common.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
