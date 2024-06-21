#pragma once

#ifdef _WIN32
#    ifdef TOP_SHARED
#        ifdef TOP_EXPORTS
#            define TOP_API __declspec(dllexport)
#        else
#            define TOP_API __declspec(dllimport)
#        endif
#    else
#        define TOP_API
#    endif
#else
#    define TOP_API
#endif
