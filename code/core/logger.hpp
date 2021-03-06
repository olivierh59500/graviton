/**
 * @file
 * @author  Sina Hatef Matbue ( _null_ ) <sinahatef.cpp@gmail.com>
 *
 * @section License
 *
 * This file is part of GraVitoN.
 *
 * Graviton is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Graviton is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Graviton.  If not, see http://www.gnu.org/licenses/.
 *
 * @brief GraVitoN::Core::Logger
 *
 */

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
#ifndef GRAVITON_LOGGER_H
#define GRAVITON_LOGGER_H

#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

namespace GraVitoN
{
	namespace Core
	{
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// GraVitoN Logging System
		namespace Logger
		{

			void __noLog()
			{

			}

/// Disable all logger functions
#ifndef GVN_ACTIVATE_LOGGER
#define logIt(_V1_)                                             __noLog()
#define logItLn(_V1_)                                           __noLog()
#define logItEndl(_V1_)                                         __noLog()
#define logVariable(_N1_,_V1_)                                  __noLog()
#define logVariable2(_N1_,_V1_,_N2_,_V2_)                       __noLog()
#define logVariable3(_N1_,_V1_,_N2_,_V2_,_N3_,_V3_)             __noLog()
#define logVariable4(_N1_,_V1_,_N2_,_V2_,_N3_,_V3_,_N4_,_V4_)   __noLog()
#else
#ifdef GVN_ACTIVATE_LOGGER
// #ifdef GVN_LOG_INTO_FILE
#ifdef GVN_LOG_FILE
		ofstream output(GVN_LOG_FILE);
#else
		ostream &output = cout;
#endif
#else
		ostream &output = cout;
#endif

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// Print a log message
		template < class _C_T_ > bool logIt ( const _C_T_ &log )
		{
#ifdef GVN_ACTIVATE_LOGGER
			output << log;
			return true;
#else
			return true;
#endif
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// Print an endl
		bool logEndl()
		{
#ifdef GVN_ACTIVATE_LOGGER
			output << endl;
			return true;
#else
			return true;
#endif
		}

		void logG()
		{
			logIt ( ":G) " );
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// print message with and a new line character
		template < class _C_T_ >
		bool logItLn ( const _C_T_ &log )
		{
			logG();
			logIt ( log );
			logEndl();
			return true;
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// print a variable
		template < class _C_T_ > bool
		logVariable(const string &name,const _C_T_ & value)
		{
			logG();
			logIt(name);
			logIt(": ");
			logIt(value);
			logEndl();

			return true;
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// print two variables
		template < class _C_T_ > bool
		logVariable2(const string &name,const _C_T_ & value,
				const string &name2,const _C_T_ & value2)
		{
			logG();
			logIt(name);
			logIt(": ");
			logIt(value);
			logIt(", ");
			logIt(name2);
			logIt(": ");
			logIt(value2);
			logEndl();

			return true;
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// print three variables
		template < class _C_T_ > bool
		logVariable3(const string &name,const _C_T_ & value,
				const string &name2,const _C_T_ & value2,
				const string &name3,const _C_T_ & value3)
		{
			logG();
			logIt(name);
			logIt(": ");
			logIt(value);
			logIt(", ");
			logIt(name2);
			logIt(": ");
			logIt(value2);
			logIt(", ");
			logIt(name3);
			logIt(": ");
			logIt(value3);
			logEndl();

			return true;
		}

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-//
/// print four variables
		template < class _C_T_ > bool
		logVariable4(const string &name,const _C_T_ & value,
				const string &name2,const _C_T_ & value2,
				const string &name3,const _C_T_ & value3,
				const string &name4,const _C_T_ & value4)
		{
			logG();
			logIt(name);
			logIt(": ");
			logIt(value);
			logIt(", ");
			logIt(name2);
			logIt(": ");
			logIt(value2);
			logIt(", ");
			logIt(name3);
			logIt(": ");
			logIt(value3);
			logIt(", ");
			logIt(name4);
			logIt(": ");
			logIt(value4);
			logEndl();

			return true;
		}

#endif
	}
/// end of Logger
}/// end of Core
} /// end of GraVitoN
#endif // _GVN_LOGGER_HEAD_
