#pragma once
#ifdef EXPORT_H
#ifdef EXPORT_DECL
	#define API_LIB __declspec(dllexport)
#else
	#define API_LIB __declspec(dllimport)
#endif // EXPORT_H

#endif