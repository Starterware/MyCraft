#ifndef LEVENSTEIN_DISTANCE_IN_TRIES_HPP
#define LEVENSTEIN_DISTANCE_IN_TRIES_HPP

#ifdef LevensteinDistanceInTries_EXPORTS	
	#ifdef WIN32
		#define EXPORT_DECLSPEC __declspec(dllexport)
	#else
		#define EXPORT_DECLSPEC __attribute__((visibility("default")))
	#endif
#else
	#ifdef WIN32
		#define EXPORT_DECLSPEC __declspec(dllimport)
	#else
		#define EXPORT_DECLSPEC
	#endif
#endif

#endif
