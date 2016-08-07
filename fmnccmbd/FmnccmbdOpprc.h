/**
  * \file FmnccmbdOpprc.h
  * operation processor for Fmnc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCCMBDOPPRC_H
#define FMNCCMBDOPPRC_H

/**
  * FmnccmbdOpprc
  */
namespace FmnccmbdOpprc {
	void* run(void* arg);
	void cleanup(void* arg);
};

#endif


