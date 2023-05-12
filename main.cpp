#include "main.h"

#include <iostream>
#include <QTimer>
#include <QApplication>
#include <QThread>

void myFunction() {
	std::cout << "Function called." << std::endl;
}

void MyObject::handleTimer()
{
		std::cout << "Timer called." << std::endl;
}

int main(int argc, char* argv[]) 
{
	std::cout << "Hello World!" << std::endl;

	QApplication app(argc, argv); // Create QApplication object



	MyObject myObject;
	QTimer timer;
	

	// Create new thread and send timer and myObject to it

	QThread new_thread;

	// Send timer and myObject to new_thread
	timer.moveToThread(&new_thread);
	myObject.moveToThread(&new_thread);



	QObject::connect(&timer, SIGNAL(timeout()), &myObject, SLOT(handleTimer()));
	new_thread.start();
	//timer.setInterval(1000);
	//timer.start();


	QMetaObject::invokeMethod(&timer, "start", Qt::QueuedConnection, Q_ARG(int, 1000)); // Start the timer in the new thread

	
	return app.exec(); // Start the event loop
}
