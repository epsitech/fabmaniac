/**
  * \file FmnccmbdJobprc.h
  * job processor for Fmnc combined daemon (declarations)
  * \author Alexander Wirthmueller
  * \date created: 7 Mar 2016
  * \date modified: 7 Mar 2016
  */

#ifndef FMNCCMBDJOBPRC_H
#define FMNCCMBDJOBPRC_H

/**
  * FmnccmbdJobprc
  */
namespace FmnccmbdJobprc {
	void* run(void* arg);
	void cleanup(void* arg);

	void accessJob(XchgFmnccmbd* xchg, DbsFmnc* dbsfmnc, ReqFmnc* req);
};

#endif


