TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
  # $$PWD/simplefactory.cpp \
  $$PWD/dynamicfactory.cpp

HEADERS += \
  $$PWD/dynamicobject.h \
