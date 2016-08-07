/**
  * \file RootFmnc.h
  * API code for job RootFmnc (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef ROOTFMNC_H
#define ROOTFMNC_H

#include "ApiFmnc_blks.h"

/**
  * RootFmnc
  */
namespace RootFmnc {
	/**
		* DpchAppLogin (full: DpchAppRootFmncLogin)
		*/
	class DpchAppLogin : public DpchAppFmnc {

	public:
		static const uint SCRJREF = 1;
		static const uint PASSWORD = 2;
		static const uint USERNAME = 3;
		static const uint ALL = 4;

	public:
		DpchAppLogin(const string& scrJref = "", const string& password = "", const string& username = "", const set<uint>& mask = {NONE});

	public:
		string password;
		string username;

	public:
		string getSrefsMask();

		void writeXML(xmlTextWriter* wr);
	};

};

#endif

