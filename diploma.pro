QT += core gui
QT += gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


CONFIG += c++11

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
           $$files($$PWD/inc/view/*.hpp)

# Automatically include all .ui files from the form directory
FORMS += $$files($$PWD/form/*.ui)

# Include paths for headers
INCLUDEPATH += inc

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
