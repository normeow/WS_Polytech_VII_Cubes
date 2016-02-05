#include <exception>
#include <stdexcept>
#include <iostream>
#include <unistd.h>
#include <mraa.hpp>

//g++ test.cpp -lmraa -o a.out

const int DPIN_LED = 13;
const int APIN_LIGHT = 1;
const int EDGE_LEVEL = 70;
const float EPS = 0.15;

mraa::Gpio* getGpioDirOut( int pin ){
	mraa::Gpio *gpio = new mraa::Gpio( pin );
	if( gpio == NULL )
		throw std::runtime_error( "error init gpio" );
	if( gpio->dir( mraa::DIR_OUT ) )
		throw std::runtime_error( "error set gpio dirrection" );
	return gpio;
}

mraa::Aio* getAio( int pin ){
	mraa::Aio *aio = new mraa::Aio( pin );
	if( aio == NULL )
		throw std::runtime_error( "error init aio" );
	return aio;
}

bool isEqual(float v1, float v2){
	return abs(v1 - v2) < EPS;
}

void fMain(){
	mraa::Gpio	*gpioLed = getGpioDirOut( DPIN_LED);
	mraa::Aio *aioLight = getAio( APIN_LIGHT );
	/*
  5
  4.64
  4.21
  3.93
  eps = 20
  */
	while( 1 ){
		float val = aioLight->read();
		light = ( val /204.6 )
		if (isEqual(val, 5)){
			gpioLed->write(1);
			usleep( 1000 );
		}
		else 
		if (isEqual(val, 4.6)){
			
			gpioLed->write(1);
			usleep( 1000 );
			gpioLed->write(0);
			usleep( 500 );
			gpioLed->write(1);
			usleep( 1000 );
		}
		else 
		if (isEqual(val, 4.21)){
			gpioLed->write(1);
			usleep( 100 );
			gpioLed->write(0);
			usleep( 100 );
			gpioLed->write(1);
			usleep( 100 );
			gpioLed->write(0);
			usleep( 100 );
			gpioLed->write(1);
			usleep( 100 );
		}
	}
	delete gpioLed;
	delete aioLight;
}

int main(){
	try{
		fMain();
	} catch( std::exception &ex ){
		std::cout << "error: " << ex.what() << std::endl;
		return 1;
	} catch( ... ){
		std::cout << "unknown error" << std::endl;
		return 1;
	}
	return 0;
}
