TEMPLATE = lib
CONFIG += c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    append_line.cpp \
    create_text.cpp \
    m.cpp \
    mpweb.cpp \
    process_forward.cpp \
    remove_all.cpp \
    rn.cpp \

HEADERS += \
    text.h \
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
