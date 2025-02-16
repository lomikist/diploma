# Include necessary Qt modules
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Use C++17 standard
CONFIG += c++17
CONFIG += debug
LIBS += -L/usr/lib -lboost_graph

# Ensure that MOC processing is done correctly
CONFIG += moc

# Automatically include all .cpp files from src and its subdirectories
SOURCES += $$files($$PWD/src/*.cpp) \
           $$files($$PWD/src/parser/*.cpp)

# Automatically include all .hpp files from inc and its subdirectories
HEADERS += $$files($$PWD/inc/*.hpp) \
           $$files($$PWD/inc/parser/*.hpp)

# Add the 'inc' directory to the include path for headers
INCLUDEPATH +=  inc \
                inc/parser \

# Installation paths (optional, depending on your deployment needs)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
