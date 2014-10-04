/*
 * Logger.h
 *
 *  Created on: Oct 3, 2014
 *      Author: amu
 */
#include <android/log.h>
#include <strings.h>

#ifndef LOGGERR_H_
#define LOGGERR_H_

#define  LOG_TAG    "asteroids"
#define  ALOG(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

class Logger {
public:
	Logger();
	virtual ~Logger();
};

#endif /* LOGGERR_H_ */
