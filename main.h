// main.h
#include <iostream>
#include <ostream>
#include <QtCore/QObject>


void myFunction();

class MyObject : public QObject {
    Q_OBJECT
public slots:
    void handleTimer();
};