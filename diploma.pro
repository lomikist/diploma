# Include necessary Qt modules
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Use C++17 standard
CONFIG += c++17

# Ensure that MOC processing is done correctly
CONFIG += moc

# Automatically include all .cpp files from src and its subdirectories
SOURCES += $$files($$PWD/src/*.cpp) \
           $$files($$PWD/src/controller/*.cpp) \
           $$files($$PWD/src/model/*.cpp) \
           $$files($$PWD/src/view/*.cpp)

# Automatically include all .hpp files from inc and its subdirectories
HEADERS += $$files($$PWD/inc/*.hpp) \
           $$files($$PWD/inc/controller/*.hpp) \
           $$files($$PWD/inc/model/*.hpp) \
           $$files($$PWD/inc/view/*.hpp) \
           $$files($$PWD/inc/observer/*.hpp)

# Automatically include all .ui files from the form directory
FORMS   += $$files($$PWD/form/*.ui)

# Add the 'inc' directory to the include path for headers
INCLUDEPATH +=  inc \
                inc/controller \
                inc/model \
                inc/view \
                inc/observer \
                build \
                debug

# Installation paths (optional, depending on your deployment needs)
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
