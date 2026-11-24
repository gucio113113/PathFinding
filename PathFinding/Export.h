#pragma once
#ifdef EXPORT_H
	#define API_LIB __declspec(dllexport)
#else
	#define API_LIB __declspec(dllimport)
#endif